
#include "ft_printf.h"

static int		print_d_i(const char *buff, va_list ap, t_fmt *fmt)
{
    if (fmt->zero && (fmt->len || fmt->dot >= 0))
        return (0);
    if (fmt->ast)
        con_ast(ap, fmt);
    va_copy(fmt->cp, ap);
    fmt->s_len = ft_intlen_2(va_arg(fmt->cp, int));
    width_zero_d(fmt);
    fmt->num = va_arg(ap, int);
    fmt->str = ft_itoa(fmt->num);
    write(1, fmt->str, fmt->s_len);
    fmt->res += fmt->s_len;
    print_minus_w(fmt);
    free(fmt->str);
    return (fmt->res);
}

static int		print_u(const char *buff, va_list ap, t_fmt *fmt)
{
    if (fmt->zero && (fmt->len || fmt->dot >= 0))
        return (0);
    if (fmt->ast)
        con_ast(ap, fmt);
    va_copy(fmt->cp, ap);
    fmt->s_len = ft_intlen_2(va_arg(fmt->cp, unsigned int));
    width_zero_d(fmt);
    fmt->num = va_arg(ap, unsigned int);
    fmt->str = ft_itoa(fmt->num);
    write(1, fmt->str, fmt->s_len);
    fmt->res += fmt->s_len;
    print_minus_w(fmt);
    free(fmt->str);
}

static int		print_c(const char *buff, va_list ap, t_fmt *fmt)
{
    char chr;

    if (fmt->ast)
        con_ast(ap, fmt);
    fmt->s_len = 1;
    con_width_s(fmt);
    chr = va_arg(ap, int);
    write(1, &chr, 1);
    fmt->res += fmt->s_len;
    print_minus_w(fmt);
    return (fmt->res);
}

static int		print_p(const char *buff, va_list ap, t_fmt *fmt)
{
    unsigned long	n;

    if (fmt->dot >= 0)
        return (0);
    if (fmt->ast)
        con_ast(ap, fmt);
    fmt->s_len = 12;
    con_width_s(fmt);
    n = va_arg(ap, unsigned long);
    write(1, "0x", 2);
    ft_putnbr_base(n, "0123456789abcdef");
    fmt->res += 14;
    print_minus_w(fmt);
    return (fmt->res);
}
