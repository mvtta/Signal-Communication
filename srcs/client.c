/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:22 by user              #+#    #+#             */
/*   Updated: 2021/10/29 22:40:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/42/42Cursus/02.minitalk/includes/minitalk.h"

int sender(int pid, char *message)
{
    int i = 0;
	int k;
	int r;
    while (message[k] != '\0')
    {
        i = 7;
        while(i >= 0)
        {
			r = ((message[k] >> i) & 1);
			printf("%d\n", r);
            if (r)
                kill(pid, SIGUSR1);
            else
                 kill(pid, SIGUSR2);
            i--;
			usleep(100);
        }
        k++;
    }
    return (0);
}

int main(int ac, char **av)
{
    pid_t pid;
    pid = atoi(av[1]);
    sender(pid, (av[2]));   
}