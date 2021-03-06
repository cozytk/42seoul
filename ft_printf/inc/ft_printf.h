/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:36:40 by taekkim           #+#    #+#             */
/*   Updated: 2020/07/24 00:56:53 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_fmt
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			len;
	int			ast;
	int			minus_w;
	int			minus_l;
	int			digit;
	int			res;
	int			s_len;
	char		spec;
	char		*str;
	char		*str_d_l;
	char		*str_temp;
	char		*num_d_l;
	long long	num;
	int			num_len;
}				t_fmt;

int				ft_numlen(long long n);
int				con_ast_pos(t_fmt *fmt, int i);
int				print_minus_w(t_fmt *fmt);
int				print_c(va_list ap, t_fmt *fmt);
int				print_d_i(va_list ap, t_fmt *fmt);
int				print_u(va_list ap, t_fmt *fmt);
int				print_s(va_list ap, t_fmt *fmt);
int				print_p(va_list ap, t_fmt *fmt);
int				print_hex(va_list ap, t_fmt *fmt);
int				print_per(va_list ap, t_fmt *fmt);
int				no_num_and_len(t_fmt *fmt);
void			init_fmt(t_fmt *fmt);
int				ft_printing(long long nbr, char *base, int length);
int				ft_intlen(long long num, int sign);
char			*ft_itoa(long long n);
int				con_per(char *f, va_list ap, t_fmt *fmt);
int				hex_len(long long n);
int				con_d_l(t_fmt *fmt);
int				con_hex(t_fmt *fmt, char **str);
int				sort_spec(va_list ap, t_fmt *fmt);
int				con_width_s(t_fmt *fmt);
int				con_width_p(t_fmt *fmt);
int				find_per(va_list ap, char *f);
int				is_spec(char c);
int				find_spec(char *f);
int				minus_zero(char *s, t_fmt *fmt);
int				ast_dot(char *buff, t_fmt *fmt);
int				width_len(char *buff, t_fmt *fmt);
int				set_fmt(char *buff, t_fmt *fmt);
int				con_ast(va_list ap, t_fmt *fmt);
int				ft_printf(const char *fmt, ...);
int				ft_isdigit(int c);
int				ft_intlen_2(long long n);
int				num_neg(t_fmt *fmt, int *i, int *diff);
size_t			ft_strlen(const char *s);
int				ft_atoi(char *buff, t_fmt *fmt);
char			*ft_strndup(const char *s1, size_t n);
int				width_zero_d(t_fmt *fmt);
int				decimal_to_hex(t_fmt *fmt);
int				width_neg_d(t_fmt *fmt);
int				no_len(t_fmt *fmt);

#endif
