/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaysu <yaysu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:41:05 by yaysu             #+#    #+#             */
/*   Updated: 2022/06/02 13:45:31 by yaysu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	find_signal(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c++;
	if (i == 7)
	{
		if (c == 0)
		{
			i = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0;
		i = 0;
		return ;
	}
	c <<= 1;
	i++;
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			sig_set;			

	ft_putstr_fd("Your PID is: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigemptyset(&sig_set);
	sigaddset(&sig_set, SIGUSR1);
	sigaddset(&sig_set, SIGUSR2);
	sa.sa_handler = &find_signal;
	sa.sa_mask = sig_set;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
