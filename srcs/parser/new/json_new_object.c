/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 20:37:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:56:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"
#include <stdlib.h>

t_json_value    *json_new_object(t_json_content *data)
{
    t_json_value *value;
    t_json_object *obj;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((obj = json_create_object(data)) == NULL)
    {
        free(value);
        return (NULL);
    }
    value->ptr = (void *)obj;
    value->type = object;
    return (value);
}