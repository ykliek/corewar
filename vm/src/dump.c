//
// Created by Eduard AMIELIN on 2019-10-20.
//

#include "../virtual_machine.h"

char	*ft_itoa_base(long long int value, int base, char type)
{
    char			*s;
    unsigned long	n;
    int				sign;
    int				i;

    n = (value < 0) ? 4294967296 + value : (unsigned long)value;
    sign = (value < 0 && base == 10) ? -1 : 0;
    i = (sign == -1) ? 2 : 1;
    while ((n /= base) >= 1)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    n = (value < 0) ? 4294967296 + value : (unsigned long)value;
    while (i-- + sign)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
        n /= base;
    }
    (i == 0) ? s[i] = '-' : 0;
    (type == 'X') ? s = str_toupper(s) : 0;
    return (s);
}

void    dump64(t_data *data)
{
    t_arena *pointer;
    int     i;
    char    *str;

    pointer = data->arena;
    i = 0;
    while (i < MEM_SIZE)
    {
        str = ft_itoa_base(pointer->hex, 16, 'x');
        write(1, &str, 2);
        write(1, " ", 1);
        if (i % 64 == 0)
            write(1, "\n", 1);
        free(str);
        pointer++;
        i++;
    }
}

void    dumping(t_data *data)
{
    dump64(data);
    exit (0);
}