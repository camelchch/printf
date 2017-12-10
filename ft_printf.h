/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:54:36 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 14:55:19 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdint.h>
#include <stdarg.h>

#define is_hash(x) ((x == '#')? 1 : 0)
#define is_zero(x) ((x == '0')? 1 : 0)
#define is_minus(x) ((x == '-')? 1 : 0)
#define is_plus(x) ((x == '+')? 1 : 0)
//#define is_width(x) x
//#define is_precison(x) x
#define is_end(x) ((x == '\0')? 1 : 0)

//#define is_hh(x) ((x == '#')? 1 : 0)
//#define is_h(x) ((x == 'h')? 1 : 0)
//#define is_l(x) ((x == 'l')? 1 : 0)
//#define is_ll(x) ((x == "ll")? 1 : 0)
//#define is_j(x) ((x == 'j')? 1 : 0)
//#define is_z(x) ((x == 'z')? 1 : 0)
//#define is_star(x) ((x == '*')? 1 : 0)
//#define is_dollar(x) ((x == '$')? 1 : 0)
//#define is_L(x) ((x == 'L')? 1 : 0)
//#define is_dot(x) ((x == ''')? 1 : 0)
typedef enum	s_cast
{
	none = 1,
	hh,
	h,
	l,
	ll,
	j,
	z,
}		t_cast;

typedef	struct	s_data
{
	char	*ori;
	char	flags[10];
	int		width;
	int		precison;
	int		positive;
	t_cast	cast;
}			t_data;

#define NB_CON	16

typedef struct s_fu
{
	char	c;

	void (*func)(va_list, t_data *, char *, int);
}				t_fu;


void	con_d(va_list args, t_data *data, char *foamat, int size);
void	con_c(va_list args, t_data *data, char *foamat, int size);
void	con_s(va_list args, t_data *data, char *foamat, int size);
void	con_o(va_list args, t_data *data, char *foamat, int size);
void	con_O(va_list args, t_data *data, char *foamat, int size);
void	con_u(va_list args, t_data *data, char *foamat, int size);
void	con_U(va_list args, t_data *data, char *foamat, int size);
void	con_x(va_list args, t_data *data, char *foamat, int size);
void	con_XX(va_list args, t_data *data, char *foamat, int size);
void	set_flags(t_data *fl, char *format, int size);
void	set_print_s(t_data *data);
void	set_print_d(t_data *data);
void	set_print_c(va_list args, t_data *data);
void	set_print_oxu(t_data *data);
char	*ft_itoa_max(intmax_t n);
char	*itoa_base(intmax_t nb, int from, int to);
char	*itoa_hex(intmax_t nb, char x);
int		max_2(int x, int y);
int		max_3(int x, int y, int z);
int		nb_digit(char *str);
void	ft_putnstr(char *s, int nbr);
void	ft_putnchar(char c, int nbr);
void	set_cast(t_data *fl, char *foamat, int size);

#endif
