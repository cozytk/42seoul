/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekkim <taekkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:54:25 by taekkim           #+#    #+#             */
/*   Updated: 2020/06/09 05:46:47 by taekkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		sort_spec(char *buff, va_list ap, t_fmt *fmt)
{
	if (fmt->spec == 's')
		print_s(buff, ap, fmt);
	else if ((fmt->spec == 'd') || (fmt->spec == 'i'))
		print_d_i(buff, ap, fmt);
	else if (fmt->spec == 'u')
	    print_u(buff, ap, fmt);
	else if (fmt->spec == 'c')
		print_c(buff, ap, fmt);
	else if (fmt->spec == 'p')
		print_p(buff, ap, fmt);
	else if (fmt->spec == 'x' || fmt->spec == 'X')
		print_hex(buff, ap, fmt);
	else if (fmt->spec == '%')
		print_per(buff, ap, fmt);
	return (0);
}

static int		con_per(char *f, va_list ap, t_fmt *fmt)
{
	char    *buff;
	int     end;

	init_fmt(fmt);
	end = find_spec(f);
	buff = strndup(f + 1, end);
	fmt->spec = buff[end - 1];
	if (!(set_fmt(buff, fmt)))
		return (-1);
	sort_spec(buff, ap, fmt);
	free(buff);
	return (end);
}

static int		find_per(va_list ap, char *f)
{
	int		i;
	int     res;
	int     printed;
	t_fmt	fmt;

	i = 0;
	printed = 0;
	while (f[i])
	{
		if (f[i] == '%')
        {
		    if ((res = con_per(f + i, ap, &fmt)) < 0)
		        return (-1);
            i = i + res;
            printed += fmt.res;
        }
		else
        {
            write(1, (f + i), 1);
            printed++;
        }
		i++;
	}
	return (printed);
}


static int		find_spec(char *f)
{
	char    *str;
	int     i;

	str = strdup(f);
	i = 1;
	while (str[i])
	{
		if (is_spec(str[i]))
		{
			free(str);
			return (i);
		}
		else
			i++;
	}
	free(str);
	return (0);
}

static int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			result;
	char		*f;

	f = (char *)fmt;
	va_start(ap, fmt);
	if ((result = find_per(ap, f)) < 0)
	    return (-1);
	va_end(ap);
	return (result);
}

int	main(void)
{
	char *s1 = "Hello";
	int	num1 = 10;
	int res = 0;
	//char *s2 = "Bye";

	//ft_printf("Hello");

   // printf("printf, %03%, I want you to say %0*u my lady %-*.4s wow %-5.4c %p %x %X\n", num1, 5, 6, s1, 'a', s1, 100, 5678876);
    //ft_printf("ft printf, %03%, I want you to say %0*u my lady %-*.4s wow %-5.4c %p %x %X\n", num1, 5, 6, s1, 'a', s1, 100, 5678876);
    printf("%d\n", printf("%3c %-6.4s %16p %012x %014X %10d %-7u %0i\n", 'a', s1, s1, 300, 256, 745, 4623, 452, 4545));
    ft_printf("%d\n", ft_printf("%3c %-6.4s %16p %012x %014X %10d %-7u %0i\n", 'a', s1, s1, 300, 256, 745, 4623, 452, 4545));
    //printf("%d\n", ft_printf("\n", num1, s1, s1, 100, 5678876));
    //printf("printf, I want you to say %010i my lady %-*.4s wow %p %x %X\n", num1, 6, s1, s1, 100, 5678876);
    //ft_printf("ft printf, I want you to say %010i my lady %-*.4s wow %p %x %X\n", num1, 6, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %*.*s wow %p %x %X\n", num1, 10, 3, s1, s1, 100, 5678876);
//    ft_printf("ft printf, I want you to say %i my lady %*.*s wow %p %x %X\n", num1, 10, 3, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %*.4s wow %p %x %X\n", num1, 10, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %*.4s wow %p %x %X\n", num1, 10, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %6.*s wow %p %x %X\n", num1, 4, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %6.*s wow %p %x %X\n", num1, 4, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %11.2s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
//    ft_printf("ft printf, I want you to say %i my lady %11.2s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %*.*s wow %p %x %X\n", num1, 10, 3, s1, s1, 100, 5678876);
//    ft_printf("ft printf, I want you to say %i my lady %*.*s wow %p %x %X\n", num1, 10, 3, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %*.4s wow %p %x %X\n", num1, 10, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %*.4s wow %p %x %X\n", num1, 10, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %6.*s wow %p %x %X\n", num1, 4, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %6.*s wow %p %x %X\n", num1, 4, s1, s1, 100, 5678876);
//    printf("printf, I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
//    ft_printf("ft_printf, I want you to say %i my lady %6s wow %p %x %X\n", num1, s1, s1, 100, 5678876);
	return (0);
}
