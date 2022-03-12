/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:16:29 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 13:04:43 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef enum		e_print
{
	E_ERROR = -1,
	E_STOP,
	E_TRUE,
}					t_error;

typedef enum		e_fmt
{
	F_OTHER = 0,
	F_FLAG,
	F_WIDTH,
	F_PRECI,
}					t_flg;

typedef struct		s_print
{
	int				dot;
	int				dash;
	int				zero;
	int				hash;
	int				sp;
	int				plus;
	unsigned int	width;
	unsigned int	preci;
	int				ptsize;
	char			c;
	int				i;
	char			*sspec;
}					t_print;

char				*ft_addpfx(char *str, char *prfx, t_print *ptf);
void				ft_prt_addflgs(t_print *ptf, t_error e);
t_error				ft_chk(const char *str, t_print *ptf, va_list lst);
t_flg				ft_chk_flag(char c, t_print *ptf);
int					ft_chk_fmt(const char *str, t_print *ptf, va_list lst);
t_flg				ft_chk_nbr(const char *str, t_print *ptf,
					va_list lst, t_flg f);
t_error				ft_chk_negdash(t_print *ptf, int d, t_flg f);
t_error				ft_chk_spec(const char *str, t_print *ptf, va_list lst);
t_flg				ft_chk_waited(char c, t_print *ptf, t_flg f);
t_error				ft_clean(t_print *ptf, t_error e);
size_t				ft_count_base(size_t nb, size_t base);
size_t				ft_count_digit(char *str);
t_error				ft_ischstr(char c);
t_flg				ft_isflag(char c);
t_error				ft_isiduxpn(char c);
t_error				ft_mod_chr(t_print *ptf, unsigned char chr);
t_error				ft_mod_id(t_print *ptf, signed int id);
t_error				ft_mod_p(t_print *ptf, uintptr_t u);
t_error				ft_mod_str(t_print *ptf, const char *str);
t_error				ft_mod_u(t_print *ptf, unsigned int u);
t_error				ft_mod_x(t_print *ptf, unsigned int x, char c);
t_error				ft_mod_n(t_print *ptf, int *n);
t_error				ft_mod_nullstr(t_print *ptf);
int					ft_printf(const char *str, ...);
t_error				ft_prt(t_print *ptf);
t_error				ft_prt_chr(t_print *ptf);
t_error				ft_prt_digit(t_print *ptf);
t_error				ft_prt_addrs(t_print *ptf);
t_error				ft_prt_str(t_print *ptf);
t_error				ft_prt_zero(t_print *ptf, char spec);
char				*ft_prt_widthflg(t_print *ptf, int ssize);
char				*ft_prt_mod_width(t_print *ptf, int ssize, char c, int ord);
char				*ft_prt_mod_preci(t_print *ptf, int ssize);
char				*ft_prt_negnum(t_print *ptf, int ssize, int odr);
t_error				ft_prt_fmt(const char *start,
					const char *end, t_print *ptf);
t_error				ft_prt_sizechk(t_print *ptf, int ssize, char spe);
t_error				ft_prt_chknegnum(t_print *ptf);
char				*ft_prt_neg0wd(t_print *ptf, int ssize);
char				*ft_prt_negwp(t_print *ptf, int ssize);
char				*ft_prt_negpre(t_print *ptf, size_t ssize);
int					ft_putnstr(const char *start, const char *end);
t_error				ft_spec_chstr(const char *str, t_print *ptf, va_list lst);
t_error				ft_spec_digit(const char *str, t_print *ptf, va_list lst);
t_error				ft_spec_perct(const char *str, t_print *ptf);
t_error				ft_spec_nulz(t_print *ptf);
void				ft_stoupper(char *str);

#endif
