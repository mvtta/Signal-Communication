/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:08:31 by user              #+#    #+#             */
/*   Updated: 2021/11/02 10:46:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#   define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>

/* 
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
*/

/* display */ 
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define SEP   "\n#############\n"

/* server */
void display(int color, int what);
void put_pid(int pid, char *pid_out);
void my_handler(int signum);

/* client */
int	matoi(char *str);
int sender(int pid, char *message);

#endif