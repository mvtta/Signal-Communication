/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:15 by user              #+#    #+#             */
/*   Updated: 2021/10/30 21:03:23 by user             ###   ########.fr       */
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

// int sig_sethandler(int sig, void *handler)
// {
//     struct sigaction *act;
//     act = malloc(sizeof(struct sigaction));
//     act->sa_sigaction = handler;
//     act->sa_flags = SA_SIGINFO;

//     sigaction(sig, act, NULL);
//     return (0);
// }

void my_handler(int signum)
{
    //static char str[10];
    static char c = 0;
    static int i = 0;

    if (signum == SIGUSR1)
    {
        //write(1, "1", 1);
        c += (1 << (6 - i));
    }
    if(signum == SIGUSR2)
    {
        //write(1, "0", 1);
    }
    i++;

    if (i == 7)
    {
        i = 0;
        write(1, &c, 1);
        //write(1, "\n",1);
        c = 0;
    }
}

int main(void)
{
    int pid;
    char sep[] = "\x1B[34m#############\n"; 
    char *pid_out;

    /* get rid of the last printf */
    pid = getpid();
    write(1, sep, 15);
    printf("\npid:%d\n", pid);
    write(1, sep, 15);
    write(1, "\n...", 4);

    signal(SIGUSR1, my_handler);
    signal(SIGUSR2, my_handler);
    while (1)
    {
        pause();
    }
}