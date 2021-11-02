/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:22 by user              #+#    #+#             */
/*   Updated: 2021/11/02 12:03:02 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	matoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int	sender(int pid, char *message)
{
	int	i;
	int	k;
	int	r;

	i = 0;
	k = 0;
	while (message[k] != '\0')
	{
		i = 6;
		while (i >= 0)
		{
			r = ((message[k] >> i) & 1);
			if (r)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(600);
		}
		k++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac <= 2)
	{
		write(1, KCYN, 5);
		write(1, SEP, 16);
		write(1, "Error\n", 6);
		write(1, "Usage: ./client <pid> <message>", 31);
		write(1, SEP, 16);
		return (0);
	}
	pid = matoi(av[1]);
	sender(pid, (av[2]));
}
