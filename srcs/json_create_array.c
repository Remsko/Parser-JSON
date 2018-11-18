/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:35:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/18 21:24:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

uint32_t json_array_len(t_json_content *data)
{
    int32_t     *brackets;
    uint32_t    index;
    uint32_t    len;
    bool        quote;

    brackets = (int32_t [2]){1, 0};
    index = data->index;
    while (isspace((int)data->src[index]))
        ++index;
    if (data->src[index] == ']')
        return (0);
    len = 1;
    while (data->src[index] != '\0' && brackets[0] > 0)
    {
        if (data->src[index] == ',' && brackets[0] == 1 && brackets[1] == 0 && quote == 0)
			++len;
		brackets[0] += (data->src[index] == '[') - (data->src[index] == ']');
		brackets[1] += (data->src[index] == '{') - (data->src[index] == '}');
		if (data->src[index] == '\"')
			quote ^= 1;
        ++index;
    }
    return (len);
}

t_json_array *json_create_array(t_json_content *data)
{
    t_json_array *arr;
    size_t len;

    if ((arr = (t_json_array *)malloc(sizeof(t_json_array))) == NULL)
        return (NULL);
    arr->len = json_array_len(data);
    if ((arr->value = (t_json_value *)malloc(sizeof(t_json_value) * arr->len)) == NULL)
    {
        free(arr);
        return (NULL);
    }
    len = 0;
    while (len < arr->len)
    {
        arr->value[len] = *json_new_value(data);
        if (len < arr->len - 1)
            json_skip_comma(data);
        ++len;
    }
    return (arr);
}