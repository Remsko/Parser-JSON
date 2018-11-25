/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:45:15 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:50:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"
#include <stdlib.h>
#include    <string.h>

t_json_string *json_create_string(t_json_content *data)
{
    t_json_string *str;
    size_t len;

    len = 0;
    data->index += 1;
    while (data->src[data->index + len] != '"')
    {
        if (data->src[data->index + len] == '\0')
        {
            json_throw_error(data, "quote");
            return (NULL);
        }
        ++len;
    }
    if ((str = (t_json_string *)malloc(sizeof(t_json_string))) == NULL)
        return (NULL);
    str->len = len;
    if ((str->ptr = strndup(&data->src[data->index], len)) == NULL)
    {
        free(str);
        return (NULL);
    }
    data->index += 1;
    return (str);
}