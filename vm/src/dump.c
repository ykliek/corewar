//
// Created by Eduard AMIELIN on 2019-10-20.
//

#include "../includes/virtual_machine.h"

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