/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:22 by user              #+#    #+#             */
/*   Updated: 2021/11/01 18:43:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	matoi(char *str)
{
	int nbr = 0;
	int i = 0;

	while(str[i])
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return(nbr);
}

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
			//printf("%d", r);
            if (r)
                kill(pid, SIGUSR1);
            else
                 kill(pid, SIGUSR2);
            i--;
			usleep(600);
        }
		//printf("%c\n", message[k]);
        k++;
    }
    return (0);
}

int main(int ac, char **av)
{
	(void)ac;
    pid_t pid;
    pid = matoi(av[1]);
    sender(pid, (av[2]));   
}