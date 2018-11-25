/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:35:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:49:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"
#include <stdlib.h>

t_json_array *json_create_array(t_json_content *data)
{
    t_json_array *arr;
    size_t len;

    data->index += 1;
    if ((arr = (t_json_array *)malloc(sizeof(t_json_array))) == NULL)
        return (NULL);
    arr->len = json_array_len(data);
    if ((arr->value = (t_json_value **)malloc(sizeof(t_json_value *) * arr->len)) == NULL)
    {
        free(arr);
        return (NULL);
    }
    len = 0;
    while (len < arr->len)
    {
        arr->value[len] = json_new_value(data);
        if (len < arr->len - 1)
            json_skip_comma(data);
        ++len;
    }
    json_skip_spaces(data);
    data->index += 1;
    return (arr);
}