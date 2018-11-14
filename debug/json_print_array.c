/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:59:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 21:32:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_array(t_json_value *value)
{
    t_json_array *array;
    uint32_t index;

    array = (t_json_array *)value->ptr;
    index = 0;
    putstr("(array)[\n");
    while (index < array->len)
    {
        json_print_value(&array->value[index]);
        putstr(", ");
        ++index;
    }
    putstr("\n](len)");
    putnbr(array->len);
    putchar("\n");
}