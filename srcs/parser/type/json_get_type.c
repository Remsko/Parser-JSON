/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_get_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:20:45 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:58:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"

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
    else if (json_is_number(&data->src[data->index]))
        type = number;
    else if (json_is_integer(&data->src[data->index]))
        type = integer;
    else if (json_is_boolean(&data->src[data->index]))
        type = boolean;
    else if (json_is_null(&data->src[data->index]))
        type = null;
    else
        type = none;
    return (type);
}