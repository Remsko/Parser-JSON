/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:56:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:47:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_free.h"
#include <stdlib.h>

void json_free_object(t_json_value *value)
{
    t_json_object *obj;
    t_json_string *str;
    uint32_t len;

    if ((obj = value->ptr) != NULL)
    {
        if (obj->pair != NULL)
        {
            len = 0;
            while (len < obj->len)
            {
                if ((str = (t_json_string *)obj->pair[len].key) != NULL)
                {
                    if (str->ptr != NULL)
                        free(str->ptr);
                    free(str);
                }
                json_free_value(obj->pair[len].value);
                ++len;
            }
            free(obj->pair);
        }
        free(obj);
    }
    free(value);
}