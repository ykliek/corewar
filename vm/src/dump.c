//
// Created by Eduard AMIELIN on 2019-10-20.
//

#include "../virtual_machine.h"

void    dump64(t_data *data)
{
    t_arena *pointer;
    int     i;
    char    *str;

    pointer = data->arena;
    i = 0;
    while (i < MEM_SIZE)
    {
		if ((i) % 64 == 0)
		{
			write(1, "0x", 2);
			str = ft_itoa_base(i, 16, 'x', 4);
			write(1, str, 4);
			write(1, " : ", 3);
		}
        str = ft_itoa_base(pointer->hex, 16, 'x', 2);
		write(1, str, 2);
        write(1, " ", 1);
        if ((i + 1) % 64 == 0)
            write(1, "\n", 1);
        free(str);
        pointer++;
        i++;
    }
}

void    dumping(t_data *data)
{
    dump64(data);
 //   exit (0);
}