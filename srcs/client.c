/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:22 by user              #+#    #+#             */
/*   Updated: 2021/10/27 15:37:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/42/42Cursus/02.minitalk/includes/minitalk.h"

#include <signal.h>
#include <unistd.h>

static int	send_ascii(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

static int	sender(pid_t pid_server, char *str)
{
	int i;

	i = 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		if (send_ascii(pid_server, str[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		kill(pid_server, SIGUSR1);
		usleep(1000);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    pid_t pid;
    pid = atoi(av[1]);
    sender(pid, (av[2]));   
}