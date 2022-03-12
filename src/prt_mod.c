/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_mod_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:39:53 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 11:24:57 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error	ft_prt_zero(t_print *ptf, char spec)
{
	int		ssize;

	ssize = 0;
	if (ptf->width > ptf->preci)
		ssize = ptf->width;
	else if (spec != 'c')
		ssize = ptf->preci;
	if (ssize == 0 && spec == 'c')
		ssize = 1;
	write(1, ptf->sspec, ssize);
	ptf->ptsize += ssize;
	return (E_TRUE);
}

t_error	ft_prt_fmt(const char *start, const char *end, t_print *ptf)
{
	size_t	i;

	i = 0;
	if (start == NULL)
		return (ft_clean(ptf, E_ERROR));
	if (end == NULL)
	{
		write(1, start, ft_strlen(start));
		ptf->i += (ft_strlen(start) - 1);
		ptf->ptsize += (ft_strlen(start));
		ft_clean(ptf, E_TRUE);
		return (E_STOP);
	}
	i = ft_putnstr(start, end);
	ptf->i += i;
	ptf->ptsize += i;
	ptf->i++;
	return (E_TRUE);
}

char	*ft_prt_widthflg(t_print *ptf, int ssize)
{
	char	*rtn;

	rtn = NULL;
	if (ptf->width <= (unsigned int)ssize || ptf->width == 0)
		return (ptf->sspec);
	if (ptf->dash)
		rtn = ft_prt_mod_width(ptf, ssize, ' ', 2);
	else if (ptf->zero && ptf->dot == 0)
		rtn = ft_prt_mod_width(ptf, ssize, '0', 1);
	else if (ptf->width > (unsigned int)ssize)
		rtn = ft_prt_mod_width(ptf, ssize, ' ', 1);
	return (rtn);
}

char	*ft_prt_mod_width(t_print *ptf, int ssize, char c, int ord)
{
	char		*temp1;
	char		*temp2;
	size_t		wsize;

	temp1 = NULL;
	temp2 = NULL;
	wsize = ptf->width - ssize;
	if ((unsigned int)ssize >= ptf->width)
		return (ptf->sspec);
	temp1 = ft_calloc(wsize, sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	ft_memrset(&temp1, c, wsize);
	if (ord == 1)
		temp2 = ft_memjoin(temp1, ptf->sspec, wsize, ssize);
	else if (ord == 2)
		temp2 = ft_memjoin(ptf->sspec, temp1, ssize, wsize);
	free(temp1);
	free(ptf->sspec);
	ptf->sspec = temp2;
	return (ptf->sspec);
}

char	*ft_prt_mod_preci(t_print *ptf, int ssize)
{
	char	*temp1;
	char	*temp2;
	int		psize;

	temp1 = NULL;
	temp2 = NULL;
	psize = ptf->preci - ssize;
	if ((unsigned int)ssize >= ptf->preci)
		return (ptf->sspec);
	temp1 = ft_calloc(psize + 1, sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	ft_memrset(&temp1, '0', psize);
	temp2 = ft_strjoin(temp1, ptf->sspec);
	free(temp1);
	free(ptf->sspec);
	ptf->sspec = temp2;
	return (ptf->sspec);
}
