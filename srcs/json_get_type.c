/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_get_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:20:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 13:21:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

bool is_number(const char *token)
{
    uint32_t i;

    i = 0;
    if (token[i] == '-')
        ++i;
    while (isdigit((int)token[i]))
        ++i;
    if (token[i] == '.')
        return (true);
    return (false);
}

bool is_integer(const char *token)
{
    uint32_t i;

    i = 0;
    if (token[i] == '-')
        ++i;
    if (isdigit((int)token[i]))
        return (true);
    return (false);
}

bool is_boolean(const char *token)
{
    return (strncmp(token, "true", strlen("true")) == 0
        || strncmp(token, "false", strlen("false")) == 0);
}

bool is_null(const char *token)
{
    return (strncmp(token, "null", strlen("null")) == 0);
}

t_json_value_type json_get_type(t_json_content *data)
{
    t_json_value_type type;

    json_skip_spaces(data);
    if (data->src[data->index] == '{')
        type = object;
    else if (data->src[data->index] == '[')
        type = array;
    else if (data->src[data->index] == '\"')
        type = string;
    else if (is_number(&data->src[data->index]))
        type = number;
    else if (is_integer(&data->src[data->index]))
        type = integer;
    else if (is_boolean(&data->src[data->index]))
        type = boolean;
    else if (is_null(&data->src[data->index]))
        type = null;
    else
        type = none;
    return (type);
}