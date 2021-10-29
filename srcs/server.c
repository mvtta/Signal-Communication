/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:15 by user              #+#    #+#             */
/*   Updated: 2021/10/29 23:00:09 by user             ###   ########.fr       */
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
    static char str[10];;;
    char *endptr;
    // str = malloc(9 * sizeof(char));
   static char c = 0;
    static int i = 0;

    // while (i < 8)
    // {
        if (signum == SIGUSR1)
        {
            str[i]= '1';
            c += (1 << (7 -i));
            // printf("Received SIGUSR1!\t%d\n", c);
            //decode(message);
        }
        if (signum == SIGUSR2)
        {
            str[i]= '0';
            // printf("Received SIGUSR2!\n");
            //decode(message);
        }
        i++;
    // }
    // str[i] = '\0';
    // c = strtol(str, (char **)NULL, 2);
    //printf("c = %s = %c\n", str, c);
    // printf("str = %s\ti %d\n", str, i);
    if (i == 8) {
        i = 0;
    write(1, &c, 1);
    c = 0;
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    printf("%s...\n", KRED);
    printf("pid: %d\n", pid);
    printf("...\n");

        signal(SIGUSR1, my_handler);
        signal(SIGUSR2, my_handler);
    while (1)
    {
    }
}