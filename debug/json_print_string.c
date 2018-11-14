/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:01:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 16:08:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_string(t_json_string *json_string)
{
    putstr("(string)");
    putstr(json_string->str);
    putchar(' ');
    putstr("(len)");
    putnbr(json_string->len);
    putchar(' ');
}