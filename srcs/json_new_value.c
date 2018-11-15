/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:05:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 13:43:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include "debug.h"

t_json_value    *json_new_value(t_json_content *data)
{
    static t_json_value *(*new_value[t_type_length])(t_json_content *) =
    {
        [none] = &json_new_none,
        [null] = &json_new_none,
        [boolean] = &json_new_none,
        [array] = &json_new_none,
        [object] = &json_new_none,
        [integer] = &json_new_none,
        [number] = &json_new_none,
        [string] = &json_new_none,
    };
    t_json_value_type type;
    
    type = json_get_type(data);
    json_print_type(type);
    return (new_value[type](data));
}