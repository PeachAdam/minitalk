/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:39:22 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/02 13:45:21 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	send_it_binary(char *s, int pid)
{
	int		i;
	char	c;

	while (*s)
	{
		c = *s++;
		i = 8;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		if (argc != 3)
			ft_putstr_fd("Bad usage of parameters.", 1);
		else if (!ft_strlen(argv[2]))
			ft_putstr_fd("There is no message to signal.", 1);
		return (1);
	}
	send_it_binary(argv[2], ft_atoi(argv[1]));
	return (0);
}
