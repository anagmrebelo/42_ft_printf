/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:01:11 by arebelo           #+#    #+#             */
/*   Updated: 2023/02/21 22:30:42 by anarebelo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_print
{
	va_list				ap;
	unsigned int		mfw;
	int					len;
	unsigned int		size;
	int					dot;
	unsigned int		str;
	int					hex;
	int					r_ident;
	char				filler;
	unsigned int		percent;
	int					sign;
	char				sign_filler;
}	t_print;

int			ft_printf(const char *format, ...);
int			conversion(const char *c, t_print *specs);

void		print_char(t_print *specs);
void		print_str(t_print *specs);
void		putstr_limited(char *s, t_print *specs);
void		print_pointer(t_print *specs);
void		print_int(t_print *specs);
void		ft_putnbr_x(int n, int fd, t_print *specs, unsigned int temp);
void		ft_putnbr_xu(unsigned int n, int fd, t_print *specs,
				unsigned int temp);
void		precision_putnbr(t_print *specs);
void		ft_putnbr_base_x(unsigned long nbr, char *base,
				t_print *specs, unsigned int temp);
void		print_percent(t_print *specs);
void		print_hex_upper(t_print *specs);
void		print_hex_lower(t_print *specs);
void		print_unsign(t_print *specs);
void		print_mfw(t_print *specs, unsigned int i);

void		counter_int(int i, t_print *specs);
void		counter_ul_base(unsigned long nbr, char *base, t_print *specs);

void		initialize_struct(t_print *specs);
void		clean_struct(t_print *specs);

int			is_id(char c);
int			format(const char *c, t_print *specs);

#endif
