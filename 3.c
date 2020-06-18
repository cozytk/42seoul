
#include "ft_printf.h"

static int		minus_zero(char *s, t_fmt *fmt)
{
    if ((s[0] == '-' || s[0] == '0'))
    {
        if (s[0] == '-')
        {
            if (s[1] == 0)
                return (0);
            fmt->minus = 1;
        }
        else
        {
            if (fmt->spec == 'c' || fmt->spec == 's' || fmt->spec == 'p')
                return (0);
            fmt->zero = 1;
        }
    }
    return (1);
}

static int      con_ast_pos(char *buff, t_fmt *fmt, int i)
{
    if (fmt->ast == 0 && fmt->dot == -1 && i == 0)
        fmt->ast = 10;
    else if (fmt->ast == 0 && fmt->dot >= 0)
        fmt->ast = 01;
    else if (fmt->ast == 10 && fmt->dot == i - 1)
        fmt->ast = 11;
    else
        return (0);
    return (1);
}

static int		ast_dot(char *buff, t_fmt *fmt)
{
    int i;

    i = 0;
    while (buff[i])
    {
        if (buff[i] == '*')
        {
            if (!(con_ast_pos(buff, fmt, i)))
                return (0);
        }
        else if (buff[i] == '.')
        {
            if (fmt->dot >= 0)
                return (0);
            fmt->dot = i;
        }
        else if (is_spec(buff[i]))
            return (1);
        else if (!(ft_isdigit(buff[i])))
            return (0);
        fmt->digit = 1;
        i++;
    }
    return (1);
}

static int		width_len(char *buff, t_fmt *fmt)
{
    if (fmt->digit == 0)
        return (1);
    if (buff[0] == fmt->spec)
        return (1);
    if (!(ft_atoi(buff, fmt)))
        return (0);
    return (1);
}

static int		set_fmt(char *buff, t_fmt *fmt)
{
    if (!(minus_zero(buff, fmt)))
        return (0);
    if (fmt->minus || fmt->zero)
        buff++;
    if (!(ast_dot(buff, fmt)))
        return (0);
    if (!(width_len(buff, fmt)))
        return (0);
    return (1);
}
