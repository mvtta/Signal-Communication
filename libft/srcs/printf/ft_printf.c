/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/08 17:55:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static fptrconv get_converter[] =
	{
		&conv_dtoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_fetoa,
		&print_str,
		&print_str,
		&print_c,
		&conv_fetoa,
		&conv_otoa,
		&print_ptr,
		&print_n,
		&print_percent,
};

int print_string(char *s, int c, int start)
{
	while (s[start] != c && s[start] != '\0')
	{
		ft_putc(s[start]);
		start++;
	}
	if (s[start] == c)
		return (start);
	else
		return (END);
}

int ft_printf(const char *format, ...)
{
	t_struct v;
	va_start(args, format);
	va_copy(args2, args);
	int i;

	i = 0;
	v.temp = ft_strdup(format);
	while (i != END)
		i = parse(v.temp, print_string(v.temp, '%', i));	
	va_end(args);
	free(v.temp);
	return (counter(0));
}

int parse(char *to_parse, int i)
{
	/* t_dir_variables dv; */
	int find_dir;
	int find_flag;
	if (i == END)
		return (END);
	find_flag = loop_through(CONV_S, to_parse, i);
	//debug_number(find_flag, "f");
	find_dir = loop_for_directives(to_parse, i);
	//debug_number(find_dir, "dir");
	//debug_number(i, "i");
	i = get_converter[find_flag](to_parse, i, find_dir, args2)  + 1;
	//debug_number(i, "RESULT OF GET CONVERTED");
	//debug_number(ft_strlen(to_parse), "len");
	if (i == END_STRING || i == END)
		return (END);
	else
		return (i);
}

/* 
** string to fetch types
** CONV_S "dixXufeEsScgopn%"
** string to fetch dir
** DIR_S "*-+ 0hljz.#123456789" 
*/