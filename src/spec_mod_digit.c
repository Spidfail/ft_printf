/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_mod_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:13:08 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 13:06:37 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error		ft_mod_n(t_print *ptf, int *n)
{
	if (n == NULL)
		return (E_STOP);
	*n = ptf->ptsize;
	return (E_STOP);
}

t_error		ft_mod_id(t_print *ptf, signed int id)
{
	char	*temp;

	temp = NULL;
	if (id == 0 && ptf->preci == 0 && ptf->dot == 1)
		return (ft_spec_nulz(ptf));
	temp = ft_itoa(id);
	if (temp == NULL)
		return (ft_clean(ptf, E_ERROR));
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}

t_error		ft_mod_u(t_print *ptf, unsigned int u)
{
	char	*temp;

	temp = NULL;
	if (u == 0 && ptf->preci == 0 && ptf->dot == 1)
		return (ft_spec_nulz(ptf));
	temp = ft_uitoa(u);
	if (temp == NULL)
		return (ft_clean(ptf, E_ERROR));
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}

t_error		ft_mod_x(t_print *ptf, unsigned int x, char c)
{
	unsigned int	u;
	char			*temp;

	temp = NULL;
	u = 0;
	if (x == 0)
		ptf->hash = 0;
	if (x == 0 && ptf->preci == 0 && ptf->dot == 1)
		return (ft_spec_nulz(ptf));
	u = ft_count_base(x, 16);
	if (!(temp = ft_calloc(u + 1, sizeof(char))))
		return (ft_clean(ptf, E_ERROR));
	if (-1 == (ft_putnbr_base(x, "0123456789abcdef", &temp, u - 1)))
	{
		free(temp);
		return (ft_clean(ptf, E_ERROR));
	}
	if (c == 'X')
		ft_stoupper(temp);
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}

t_error		ft_mod_p(t_print *ptf, uintptr_t u)
{
	unsigned int	size;
	char			*temp;

	temp = NULL;
	if (u == 0 && ptf->preci == 0 && ptf->dot == 1)
		return (ft_spec_nulz(ptf));
	size = ft_count_base(u, 16);
	if (size == 0)
		size += 1;
	temp = ft_calloc(size + 1, sizeof(char));
	if (temp == NULL)
		return (ft_clean(ptf, E_ERROR));
	if (u == 0)
		temp[0] = '0';
	ft_putnbr_base(u, "0123456789abcdef", &temp, size - 1);
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}
