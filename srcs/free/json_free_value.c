/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:36:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 11:43:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

void    json_free_value(t_json_value *value)
{
    static void (*free_value[t_type_length])(t_json_value *) =
    {
        [none] = &json_free_none,
        [null] = &json_free_null,
        [boolean] = &json_free_boolean,
        [array] = &json_free_array,
        [object] = &json_free_object,
        [integer] = &json_free_integer,
        [number] = &json_free_number,
        [string] = &json_free_string,
    };
    t_json_value_type type;

    if (value == NULL)
        return ;
    type = value->type;
    return (free_value[type](value));
}