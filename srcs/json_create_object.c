/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:37:43 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 10:55:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

uint32_t json_object_len(t_json_content *data)
{
    int32_t     *brackets;
    uint32_t    index;
    uint32_t    len;
    bool        quote;

    index = data->index;
    while (isspace((int)data->src[index]))
        ++index;
    if (data->src[index] == '}')
        return (0);
    len = 1;
    quote = false;
    brackets = (int32_t [2]){0, 1};
    while (data->src[index] != '\0' && brackets[1] > 0)
    {
        if (data->src[index] == ',' && brackets[0] == 0 && brackets[1] == 1 && quote == 0)
			++len;
		brackets[0] += (data->src[index] == '[') - (data->src[index] == ']');
		brackets[1] += (data->src[index] == '{') - (data->src[index] == '}');
		if (data->src[index] == '\"')
			quote ^= true;
        ++index;
    }
    return (len);
}

t_json_object *json_create_object(t_json_content *data)
{
    t_json_object *obj;
    size_t len;

    if ((obj = (t_json_object *)malloc(sizeof(t_json_object))) == NULL)
        return (NULL);
    obj->len = json_object_len(data);
    if ((obj->pair = (t_json_pair *)malloc(sizeof(t_json_pair) * obj->len)) == NULL)
    {
        free(obj);
        return (NULL);
    }
    printf("%u\n", obj->len);
    len = 0;
    while (len < obj->len)
    {
        //obj->pair[len].key = json_new_value(data);
        //json_skip_colon(data);
        obj->pair[len].value = json_new_value(data);
        if (len < obj->len - 1)
            json_skip_comma(data);
        ++len;
    }
    return (obj);
}