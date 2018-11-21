/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:37:43 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 14:54:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_object *json_create_object(t_json_content *data)
{
    t_json_object *obj;
    size_t len;

    data->index += 1;
    if ((obj = (t_json_object *)malloc(sizeof(t_json_object))) == NULL)
        return (NULL);
    obj->len = json_object_len(data);
    if ((obj->pair = (t_json_pair *)malloc(sizeof(t_json_pair) * obj->len)) == NULL)
    {
        free(obj);
        return (NULL);
    }
    len = 0;
    while (len < obj->len)
    {
        json_skip_spaces(data);
        obj->pair[len].key = json_create_string(data);
        data->index += obj->pair[len].key->len;
        json_skip_colon(data);
        obj->pair[len].value = json_new_value(data);
        if (len < obj->len - 1)
            json_skip_comma(data);
        ++len;
    }
    json_skip_spaces(data);
    data->index += 1;
    return (obj);
}