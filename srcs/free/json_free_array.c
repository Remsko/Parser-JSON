/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:48:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:45:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_free.h"
#include <stdlib.h>

void json_free_array(t_json_value *value)
{
    t_json_array *arr;
    uint32_t len;

    if ((arr = value->ptr) != NULL)
    {
        if (arr->value != NULL)
        {
            len = 0;
            while (len < arr->len)
            {
                json_free_value(arr->value[len]);
                ++len;
            }
            free(arr->value);
        }
        free(arr);
    }
    free(value);
}