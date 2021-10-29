/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:15 by user              #+#    #+#             */
/*   Updated: 2021/10/29 22:14:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../includes/minitalk.h" */

#include "/Users/mvaldeta/42/42Cursus/02.minitalk/includes/minitalk.h"

/*    The sigaction structure is defined as something like:

           struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
            */


void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

int sig_sethandler(int sig, void *handler)
{
    struct sigaction *act;
    act = malloc(sizeof(struct sigaction));
    act->sa_sigaction = handler;
    act->sa_flags = SA_SIGINFO;

    sigaction(sig, act, NULL);
    return (0);
}

void my_handler(int signum)
{
    static char buf[100];
    static int i;
    static int bit;

    if (--bit == -1)
    {
        bit = 6;
        ++i;
    }
    buf[i] &= ~(1 << 7);
    if (signum == SIGUSR1)
        buf[i] |= (1 << bit);
    else if (signum == SIGUSR2)
        buf[i] &= ~(1 << bit);
    if (i == 99 || buf[i] == 127)
    {
        buf[i] = 0;
        write(STDOUT_FILENO, buf, i + 1);
        ft_memset(buf, '\0', 99);
        i = 0;
        bit = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    printf("%s...\n", KRED);
    printf("pid: %d\n", pid);
    printf("...\n");

    while (1)
    {
        signal(SIGUSR1, my_handler);
        signal(SIGUSR2, my_handler);
    }
    //sleep(1000);
}