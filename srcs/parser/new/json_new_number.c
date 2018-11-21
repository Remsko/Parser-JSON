/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:26:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 16:14:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_new_number(t_json_content *data)
{
    t_json_value *value;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((value->ptr = malloc(sizeof(double))) == NULL)
    {
        free(value);
        return (NULL);
    }
    *(double *)value->ptr = atof(&data->src[data->index]);
    value->type = number;
    json_skip_number(data);
    return (value);
}