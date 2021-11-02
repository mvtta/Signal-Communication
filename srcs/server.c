/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:06:15 by user              #+#    #+#             */
/*   Updated: 2021/11/01 18:49:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void display(int color, int what)
{
    if (color == 1 && what == 0)
        write(1, KWHT, 5);
    if (color == 2)
        write(1, KCYN, 5);
    if (what == 1)
        write(1, SEP, 16);
    if (what == 2)
        write(1, "\n", 1);
}

void put_pid(int pid, char *pid_out)
{
    int aux;
    int i = 0;

    while (pid)
    {
        aux = pid % 10;
        pid = pid / 10;
        pid_out[i] = aux + '0';
        i += 1;
    }
    i = 5;
    write(1, "pid : ", 6);
    while (i > -1)
    {
        write(1, &pid_out[i], 1);
        i -= 1;
    }
    return;
}

void my_handler(int signum)
{
    static char c = 0;
    static int i = 0;

    if (signum == SIGUSR1)
    {
        //write(1, "1", 1);
        c += (1 << (6 - i));
    }
    if (signum == SIGUSR2)
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
    int aux;
    int i;
    char pid_out[5];

    i = 0;
    aux = 0;
    pid = getpid();
    display(2, 1);
    put_pid(pid, pid_out);
    display(2, 1);
    display(1, 0);
    signal(SIGUSR1, my_handler);
    signal(SIGUSR2, my_handler);
    while (1)
    {
        pause();
    }
}