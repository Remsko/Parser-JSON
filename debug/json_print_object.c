/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:15:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 09:23:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_object(t_json_value *value)
{
    t_json_object *object;
    t_json_value  key;
    uint32_t index;

    object = (t_json_object *)value->ptr;
    key.type = string;
    index = 0;
    printf("(object{\n");
    while (index < object->len)
    {
        key.ptr = (t_json_string *)object->pair[index].key;
        json_print_string(&key);
        printf(": ");
        json_print_value(object->pair[index].value);
        printf(", ");
        ++index;
    }
    printf("\n}(len)%d\n", object->len);
}