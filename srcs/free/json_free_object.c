/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:56:08 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 18:03:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

void    json_free_object(t_json_value *value)
{
    t_json_object *obj;
    uint32_t len;

    if ((obj = value->ptr) != NULL)
        if (obj->pair != NULL)
        {
            len = 0;
            while (len < obj->len)
            {
                if (obj->pair[len] != NULL)
                {
                    if (obj->pair[len]->key != NULL)
                    {
                        if (obj->pair[len]->key->ptr != NULL)
                            free(obj->pair[len]->key->ptr);
                        free(obj->pair[len]->key);
                    }
                    json_free_value(obj->pair[len]->value);
                }
                ++len;
            }
            free(obj->pair);
        }
        free(obj);
    }
    free(value);
}