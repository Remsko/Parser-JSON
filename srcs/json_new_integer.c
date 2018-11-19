/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:32:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 13:23:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

static void skip_integer(t_json_content *data)
{
    while (isdigit((int)data->src[data->index]))
        ++data->index;
}

t_json_value *json_new_integer(t_json_content *data)
{
    t_json_value *value;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((value->ptr = malloc(sizeof(int))) == NULL)
    {
        free(value);
        return (NULL);
    }
    *(int *)value->ptr = atoi(&data->src[data->index]);
    value->type = integer;
    skip_integer(data);
    return (value);
}