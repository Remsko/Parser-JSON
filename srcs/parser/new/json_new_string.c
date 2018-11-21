/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:57:42 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 12:48:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_new_string(t_json_content *data)
{
    t_json_value *value;
    t_json_string *str;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((str = json_create_string(data)) == NULL)
    {
        free(value);
        return (NULL);
    }
    value->ptr = (void *)str;
    value->type = string;
    data->index += str->len;
    return (value);
}