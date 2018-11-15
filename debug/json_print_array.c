/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:59:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 09:05:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_array(t_json_value *value)
{
    t_json_array *array;
    uint32_t index;

    array = (t_json_array *)value->ptr;
    index = 0;
    printf("(array)[\n");
    while (index < array->len)
    {
        json_print_value(&array->value[index]);
        printf(", ");
        ++index;
    }
    printf("\n](len)%d\n", array->len);
}