/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_nmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:34:05 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 11:20:37 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_prt_negpre(t_print *ptf, size_t ssize)
{
	char	*temp1;
	char	*temp2;
	int		psize;

	temp1 = NULL;
	temp2 = NULL;
	psize = ptf->preci - ssize + 1;
	if ((unsigned int)ssize >= ptf->preci)
		return (ptf->sspec);
	temp1 = ft_calloc(psize + 1, sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	ft_memrset(&temp1, '0', psize);
	temp1[0] = '-';
	temp2 = ft_strjoin(temp1, &ptf->sspec[1]);
	free(temp1);
	free(ptf->sspec);
	ptf->sspec = temp2;
	return (ptf->sspec);
}

char		*ft_prt_negwp(t_print *ptf, int ssize)
{
	char	*temp1;
	char	*temp2;
	size_t	wsize;

	temp1 = NULL;
	temp2 = NULL;
	wsize = (ptf->width - ssize);
	if ((unsigned int)ssize >= ptf->width)
		return (ptf->sspec);
	temp1 = ft_calloc(wsize + 1, sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	ft_memrset(&temp1, ' ', wsize);
	if (ptf->dash)
		temp2 = ft_memjoin(ptf->sspec, temp1, ssize, wsize);
	else
		temp2 = ft_memjoin(temp1, ptf->sspec, wsize, ssize);
	free(temp1);
	free(ptf->sspec);
	ptf->sspec = temp2;
	return (ptf->sspec);
}

char		*ft_prt_neg0wd(t_print *ptf, int ssize)
{
	char	*temp1;
	char	*temp2;
	size_t	wsize;

	temp1 = NULL;
	temp2 = NULL;
	wsize = ptf->width - ssize + 1;
	if ((unsigned int)ssize >= ptf->width)
		return (ptf->sspec);
	temp1 = ft_calloc(wsize + 1, sizeof(char));
	if (temp1 == NULL)
		return (NULL);
	ft_memrset(&temp1, '0', wsize);
	temp1[0] = '-';
	temp2 = ft_memjoin(temp1, &ptf->sspec[1], wsize, ssize);
	free(temp1);
	free(ptf->sspec);
	ptf->sspec = temp2;
	return (ptf->sspec);
}

t_error		ft_prt_chknegnum(t_print *ptf)
{
	size_t	ssize;

	ssize = ft_strlen(ptf->sspec);
	if (ptf->preci > ft_count_digit(ptf->sspec))
	{
		if (!(ft_prt_negpre(ptf, ft_count_digit(ptf->sspec))))
			return (E_ERROR);
		if (ptf->width > ft_strlen(ptf->sspec))
			ft_prt_negwp(ptf, ft_strlen(ptf->sspec));
	}
	else if (ptf->width > ssize && ptf->zero && !ptf->dot
			&& !ptf->dash)
		ft_prt_neg0wd(ptf, ssize);
	else if (ptf->width > ssize)
		ft_prt_widthflg(ptf, ssize);
	if (ptf->sspec == NULL)
		return (E_ERROR);
	ptf->ptsize += ft_strlen(ptf->sspec);
	write(1, ptf->sspec, ft_strlen(ptf->sspec));
	return (E_TRUE);
}
