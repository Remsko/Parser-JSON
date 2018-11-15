/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:57:42 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 19:45:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

static size_t string_len(const char *src)
{
    size_t len;

    len = 0;
    while (src[len] != '"')
    {
        if (src[len] == '\0')
            return (0); /* Need to throw an error */
        ++len;
    }
    return (len);
}

t_json_value *json_new_string(t_json_content *data)
{
    t_json_value *value;
    t_json_string *json_str;

    data->index += 1;
    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((json_str = (t_json_string *)malloc(sizeof(t_json_string))) == NULL)
    {
        free(value);
        return (NULL);
    }
    json_str->len = string_len(&data->src[data->index]);
    json_str->str = strndup(&data->src[data->index], json_str->len);
    if (json_str->str == NULL)
    {
        free(value);
        free(json_str);
        return (NULL);
    }
    value->ptr = (void *)json_str;
    value->type = string;
    data->index += json_str->len;
    data->index += 1;
    return (value);
}