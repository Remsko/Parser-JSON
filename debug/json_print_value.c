/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:05:30 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 13:19:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_value(t_json_value *value)
{
    static void (*printer[t_type_length])(t_json_value *) = {
        [none] = &json_print_none,
        [null] = &json_print_null,
        [boolean] = &json_print_boolean,
        [array] = &json_print_array,
        [object] = &json_print_object,
        [integer] = &json_print_integer,
        [number] = &json_print_number,
        [string] = &json_print_string,
    };

    if (value == NULL)
        return ;
    printer[value->type](value);
}