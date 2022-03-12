/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:49:23 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 11:55:56 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(const char *start, const char *end)
{
	size_t	i;

	i = 0;
	if (start == NULL || end == NULL)
		return (-1);
	while (start[i] && &start[i] != end)
	{
		write(1, &start[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_count_digit(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && ft_isalnum(str[i]))
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_addpfx(char *str, char *prfx, t_print *ptf)
{
	char		*rtn;
	char		*temp;
	size_t		size;

	rtn = NULL;
	temp = NULL;
	size = ft_strlen(prfx) + 1;
	if (str == NULL)
		return (NULL);
	temp = ft_calloc(size, sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, prfx, size);
	rtn = ft_strjoin(temp, str);
	if (ptf->c == 'X')
		ft_stoupper(rtn);
	free(temp);
	free(str);
	return (rtn);
}

void	ft_prt_addflgs(t_print *ptf, t_error e)
{
	if (ptf->preci > 0 && e == E_TRUE)
		ft_prt_mod_preci(ptf, ft_count_digit(ptf->sspec));
	if (((ptf->c == 'x' || ptf->c == 'X') && (ptf->hash)) || ptf->c == 'p')
		ptf->sspec = ft_addpfx(ptf->sspec, "0x", ptf);
	if ((ptf->c == 'i' || ptf->c == 'd') && ptf->sp && !ptf->plus)
		ptf->sspec = ft_addpfx(ptf->sspec, " ", ptf);
	if ((ptf->c == 'i' || ptf->c == 'd') && ptf->plus)
	{
		if ((ptf->zero && ptf->dash) || !(ptf->zero) ||
			!(ptf->width > ft_strlen(ptf->sspec) || e == E_ERROR))
		{
			ptf->sspec = ft_addpfx(ptf->sspec, "+", ptf);
			ft_prt_widthflg(ptf, ft_strlen(ptf->sspec));
		}
		else if ((ptf->dash || ptf->zero) && (ptf->width > 0 || e == E_ERROR))
		{
			ptf->width--;
			ft_prt_widthflg(ptf, ft_strlen(ptf->sspec));
			ptf->sspec = ft_addpfx(ptf->sspec, "+", ptf);
		}
	}
	else if ((ptf->width > 0 || e == E_ERROR))
		ft_prt_widthflg(ptf, ft_strlen(ptf->sspec));
}

t_error	ft_prt_sizechk(t_print *ptf, int ssize, char spe)
{
	if (spe == 'c')
	{
		if ((ptf->ptsize + ssize + ptf->width) > INT_MAX)
			return (E_STOP);
		return (E_TRUE);
	}
	else if ((ptf->ptsize + ssize + ptf->preci) > INT_MAX)
		return (E_ERROR);
	else if ((ptf->ptsize + ssize + ptf->width) > INT_MAX)
		return (E_STOP);
	else if ((ptf->ptsize + ssize + ptf->preci + ptf->width) > INT_MAX)
		return (E_STOP);
	return (E_TRUE);
}
