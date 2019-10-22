//
// Created by Eduard AMIELIN on 2019-10-20.
//

#include "../includes/virtual_machine.h"

void    dump64(t_data *data)
{
    t_arena *pointer;
    int     i;
    char    *str;
    int 	temp;

    pointer = data->arena;
    i = 0;
    while (i < MEM_SIZE)
    {
		if ((i) % 64 == 0)
		{
			str = ft_itoa_base(i, 16, 'x');
			temp = 6 - ft_strlen(str);
			write(1, "0x0000", temp);
			write(1, str, ft_strlen(str));
			write(1, " : ", 3);
		}
        str = ft_itoa_base(pointer->hex, 16, 'x');
		if (ft_strlen(str) < 2)
		{
			write(1, "0", 1);
			write(1, str, 1);
		}
		else
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