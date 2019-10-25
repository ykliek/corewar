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

void    dump32(t_data *data)
{
	t_arena *pointer;
	int     i;
	char    *str;
	int 	temp;

	pointer = data->arena;
	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i) % 32 == 0)
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
		if ((i + 1) % 32 == 0)
			write(1, "\n", 1);
		free(str);
		pointer++;
		i++;
	}
}

void    dumping(t_data *data)
{
	char str[2];

	if (data->dump.flag)
	{
		if (data->dump.value == data->cycle)
		{
			dump32(data);
			exit (0);
		}
	}
	if (data->dump_64.flag)
	{
		if (data->dump_64.value == data->cycle)
		{
			dump64(data);
			exit (0);
		}
	}
	if (data->s.value && (data->cycle % data->s.value) == 0)
	{
		dump64(data);
		while (read(0, str, 1))
		{
			if (str[0] == '\n')
				break ;
		}
	}
}