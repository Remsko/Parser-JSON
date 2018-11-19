/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:05:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 10:47:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value    *json_new_value(t_json_content *data)
{
    static t_json_value *(*new_value[t_type_length])(t_json_content *) =
    {
        [none] = &json_new_none,
        [null] = &json_new_null,
        [boolean] = &json_new_boolean,
        [array] = &json_new_array,
        [object] = &json_new_object,
        [integer] = &json_new_integer,
        [number] = &json_new_number,
        [string] = &json_new_string,
    };
    t_json_value_type type;
    
    type = json_get_type(data);
    return (new_value[type](data));
}