/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saxiao <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:11:07 by saxiao            #+#    #+#             */
/*   Updated: 2017/12/10 18:11:42 by saxiao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		is_format(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||\
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||\
			c == 'c' || c == 'C' || c == 'e' || c == 'E' || c == 'f' || c == 'F' ||\
			c == 'g' || c == 'G' || c == 'a' || c == 'A' || c == 'n');
}

char	*ft_strnchr(const char *s, int c, int size)
{
	while (c != *s && *s && size-- > 0)
		s++;
	if (c == *s)
		return ((char *)s);
	else
		return (NULL);
}

/*
int		d_format(const char *str, int index, int nbr)
{
	int		ct;
	char	*to_str;

	to_str = ft_itoa(nbr);
	ct = ft_strlen(to_str);
	ct = before_format(str, index, ct);
	return (ct);
}

int		before_format(const char *str, int index, int count)
{
	char	*s;
	int		i;
	int		width;

	i = 0;
}
*/

void	set_cast(t_data *fl, char *format, int size)
{
	if (ft_strnstr(format, "hh", size))
		fl->cast = hh;
	else if(ft_strnstr(format, "ll",size))
		fl->cast = ll;
	else if(ft_strnchr(format, 'h',size))
		fl->cast = h;
	else if(ft_strnchr(format, 'l',size))
		fl->cast = l;
	else if(ft_strnchr(format, 'j',size))
		fl->cast = j;
	else if(ft_strnchr(format, 'z',size))
		fl->cast = z;
	else fl->cast = none;
	//ft_putendl("inside set_cast cast =");
	//ft_putnbr(fl->cast);
	//ft_putendl("");
}

int		nb_number(int number)
{
	int		i;

	i = 1;
	while (number > 9)
	{
		i++;
		number = number / 10;
	}
	return (i);
}

int		nb_digit(char *str)
{
	int		i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_putnstr(char *s, int nbr)
{
	if (s)
	{
		while (*s && nbr-- >= 1)
			write(1, s++, 1);
	}
}

void	set_flags(t_data *fl, char *format, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	//	fl->data = data;
	//fl->ori = NULL;
	fl->positive = 1;
	ft_bzero(fl->flags, 10);
	fl->width = 0;
	//if (ft_strnchr(format, '.', size))
	//fl->precison = 0;
	//else
	//fl->precison = ft_strlen(fl->ori);
	fl->precison = -1;
//	ft_putendl("enters here ????");
	//ft_putnstr(format, size);
	while (i < size && j < 10)
	{
		if (format[i] == '0')
		{
			if (!(ft_strchr(fl->flags, '0')))
			fl->flags[j++] = '0';
			i++;
		}
		else if ('0' < format[i] && format[i] <= '9')
		{
		//ft_putendl("enter or not 99999999999999999");
			fl->width = ft_atoi(format + i);
	//ft_putnbr(i);
	//ft_putendl("");
			i = i + nb_digit(format + i);
		}
		else if (format[i] == '.')
		{
			if (format[i + 1] > '9' || format[i + 1] < '0')
				fl->precison = -1;
			else
				fl->precison = ft_atoi(format + 1 + i);
			i = i + nb_digit(format + i + 1) + 1;
		}
		else
		{
			if(ft_strchr("#-+ ", format[i]))
				fl->flags[j++] = format[i];
			i++;
		}
	}
//	ft_putendl("inside set_flags");
}
/*
char	*get_data(va_list args, char c)
{
	char	*data;
	//	if (c == 's' || c == 'S')
}
*/

/*void	ini_set(t_fu **set)
{
	*set = {
		{'s',con_s},
		{'c',con_c},
		{'d',con_d},
	};
}
*/


int		max_3(int x, int y, int z)
{
	int		max;

	max = x;
	if (y > max)
		max = y;
	if (z > max)
		max = z;
	return (max);
}


int		max_2(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	ft_putnchar(char c, int nbr)
{
	while (nbr-- >= 1)
		write(1, &c, 1);
}

/*
void	buff_vide(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
		str[i] = ' ';
}
*/

void	set_print_s(t_data *data)
{
	int		len;
//	char	buff[len + 1];
	if (data->precison != -1)
	//if (data->width >= data->precison)
	len = max_2(data->width, data->precison);
	else
		len = max_2(data->width, ft_strlen(data->ori));
	//buff = ft_strnew(len + 1);
	//buff_vide(buff, len);
	if (data->precison == -1)
		data->precison = ft_strlen(data->ori);
	//ft_putendl("set_print_s");
	//ft_putendl("data width =");
	//ft_putnbr(data->width);
	//ft_putendl("");
	if (len == (int)ft_strlen(data->ori))
		ft_putstr(data->ori);
	else
	{
		if (ft_strchr(data->flags, '-'))
		{
			ft_putnstr(data->ori, data->precison);
			ft_putnchar(' ', len - data->precison);
		}
		else
		{
			ft_putnchar(' ', len - data->precison);
		ft_putnstr(data->ori, data->precison);
		}
	}
}

void	init(t_data *data)
{
	int i;

	i = 0;
	data->ori = NULL;
	ft_bzero(data->flags, 10);
	data->width = 0;
	data->precison = 0;
	data->positive = 0;
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		args;
	va_start(args, format);
	int			i;
	int			nbr;
	int			j;
	t_data		data;
	//	char	*ori_data;
	t_fu	set[9] = {
		{'s',con_s},
		{'o',con_o},
		{'O',con_O},
		{'d',con_d},
		{'c',con_c},
		{'u',con_u},
		{'U',con_U},
		{'x',con_x},
		{'X',con_XX},
	};

	nbr = 0;
	//data = (t_data *)malloc(sizeof(*data));
	//init(data);
	while (*format)
	{
		j = 0;
		i = 0;
		if( *format == '%')
		{
			if ((format + 1) && *(format + 1) == '%')
			{
				ft_putchar('%');
				format = format + 2;
			}
			while(format[i] && !is_format(format[i]))
				i++;
			while (j < 9 && set[j].c != format[i])
				j++;
		//	if (set[j].func != NULL)
				(set[j].func)(args, &data, (char *)format, i);
	//	ft_putendl("here or not ?");
		//	else
		//		break;
			format = format + i + 1;
		}
		else
			ft_putchar(*format++);
		nbr++;
	}
	return (nbr);
}

int		main(void)
{
//	char d = 'p';
	//char *c = "nihao";
//	unsigned char c = 'a';
	//ft_printf("nihao%%%+-5.1shaiyou%-3.1s11111%-2.3s\n", "huhu", "dudu","kkkklastisherei");
//	ft_printf("nihao%-2.3xsalut%3.6x\n", 255, 368);
//	printf("nihao%-2.3xsalut%3.6x\n", 255, 368);
//	printf("nihao %#-11.3x salut%#06.0x\n", 255, 865);
//	printf("nihao %#-11.3x salut%#6.0x\n", 255, 0);
	ft_printf("nihao %#+-11.3x salut%#6.0x\n", 255, 0);
//	printf("nihao %-+10.2d\n",a);
//	printf("nihao %-+10.2d salut %+8.d\n", 2, 0);
//	ft_putstr(&c);
	return (0);
}
