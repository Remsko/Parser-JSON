/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:15:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 21:33:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_object(t_json_value *value)
{
    t_json_object *object;
    uint32_t index;

    object = (t_json_object *)value->ptr;
    index = 0;
    putstr("(object{\n");
    while (index < object->len)
    {
        putstr(": ");
        json_print_value(&object->pair[index].key);
        json_print_value(&object->pair[index].value);
        putstr(", ");
        ++index;
    }
    putstr("\n}(len)");
    putnbr(object->len);
    putchar("\n"); 
}