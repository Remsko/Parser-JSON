/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:01:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:42:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_debug.h"

void    json_print_string(t_json_value *value)
{
    t_json_string *json_string;

    json_string = (t_json_string *)value->ptr;
    printf("(string)\"%s\" (len)%d", json_string->ptr, json_string->len);
}