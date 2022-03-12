/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:54:39 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 12:48:27 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error		ft_isiduxpn(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == 'p'
			|| c == 'n')
		return (E_TRUE);
	else
		return (E_STOP);
}

t_error		ft_ischstr(char c)
{
	if (c == 'c' || c == 's')
		return (E_TRUE);
	else
		return (E_STOP);
}

void		ft_stoupper(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return ;
}

t_error		ft_spec_nulz(t_print *ptf)
{
	free(ptf->sspec);
	ptf->sspec = ft_calloc(1, sizeof(char));
	if (ptf->sspec == NULL)
		return (ft_clean(ptf, E_ERROR));
	return (E_TRUE);
}
