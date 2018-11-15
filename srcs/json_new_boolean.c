/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:12:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 14:35:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_new_boolean(t_json_content *data)
{
    t_json_value *value;
    bool is_true;

    is_true = (data->src[data->index] == 't');
    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((value->ptr = malloc(sizeof(bool *))) == NULL)
    {
        free(value);
        return (NULL);
    }
    *(bool *)value->ptr = is_true;
    value->type = boolean;
    data->len += is_true ? strlen("true") : strlen("false");
    return (value);
}