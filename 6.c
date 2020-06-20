
#include "ft_printf.h"

int	main(void)

static int      width_zero_d(t_fmt *fmt)
{
    if (fmt->s_len >= fmt->width)
        return (0);
    fmt->width -= fmt->s_len;
    if (fmt->minus)
        fmt->minus_w = fmt->width;
    else
    {
        fmt->res += fmt->width;
        while ((fmt->width)--)
        {
            if (fmt->zero)
                write(1, "0", 1);
            else
                write(1, " ", 1);
        }
    }
    return (0);
}

static int      print_minus_w(t_fmt *fmt)
{
    if (fmt->minus_w)
    {
        fmt->res += fmt->width;
        while ((fmt->width)--)
            write(1, " ", 1);
    }
    return (0);
}

static char      *decimal_to_hex(long long n)
{
    char    *str;
    int     position;
    int     mod;

    if (!(str = (char *)malloc(sizeof(char *) * 20)))
        return (0);
    position = 0;
    while (1)
    {
        mod = n % 16;
        if (mod < 10)
            str[position] = 48 + mod;
        else
            str[position] = 65 + (mod - 10);
        n = n / 16;
        position++;
        if (n == 0)
            break;
    }
    return (str);
}
