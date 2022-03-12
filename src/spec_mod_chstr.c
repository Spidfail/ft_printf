/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_mod_chstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:43:13 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/09 13:03:55 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error	ft_mod_chr(t_print *ptf, unsigned char chr)
{
	char	*temp;

	temp = NULL;
	if (chr == 0 && ptf->preci == 0 && ptf->dot == 1)
		return (ft_spec_nulz(ptf));
	if (!(temp = ft_calloc(2, sizeof(char))))
	{
		ft_clean(ptf, E_ERROR);
		return (E_ERROR);
	}
	temp[0] = chr;
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}

t_error	ft_mod_str(t_print *ptf, const char *str)
{
	char	*temp;

	temp = NULL;
	if (str && !ptf->dot)
		temp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	else if (str && ptf->dot)
		temp = ft_calloc(ptf->preci + 1, sizeof(char));
	else
		return (ft_mod_nullstr(ptf));
	if (temp == NULL)
		return (E_ERROR);
	if (ptf->dot)
		ft_memccpy(temp, str, '\0', ptf->preci);
	else
		ft_strlcpy(temp, str, ft_strlen(str) + 1);
	free(ptf->sspec);
	ptf->sspec = temp;
	if (ptf->sspec == NULL)
		return (E_ERROR);
	return (E_TRUE);
}

t_error	ft_mod_nullstr(t_print *ptf)
{
	char	*temp;

	temp = ft_calloc(ft_strlen("(null)") + 1, sizeof(char));
	if (ptf->dot)
		ft_memccpy(temp, "(null)", '\0', ptf->preci);
	else
		ft_strlcpy(temp, "(null)", ft_strlen("(null)") + 1);
	if (temp == NULL)
		return (E_ERROR);
	free(ptf->sspec);
	ptf->sspec = temp;
	return (E_TRUE);
}
