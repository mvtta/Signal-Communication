/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:22 by user              #+#    #+#             */
/*   Updated: 2021/10/30 21:03:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/42/42Cursus/02.minitalk/includes/minitalk.h"

int sender(int pid, char *message)
{
    int i = 0;
	int k = 0;
	int r;
    while (message[k] != '\0')
    {
        i = 6;
        while(i >= 0)
        {
			r = ((message[k] >> i) & 1);
			printf("%d", r);
            if (r)
                kill(pid, SIGUSR1);
            else
                 kill(pid, SIGUSR2);
            i--;
			usleep(1000);
        }
		printf("%c\n", message[k]);
        k++;
    }
    return (0);
}

int main(int ac, char **av)
{
	(void)ac;
    pid_t pid;
	/* get rid of atoi */
    pid = atoi(av[1]);
    sender(pid, (av[2]));   
}