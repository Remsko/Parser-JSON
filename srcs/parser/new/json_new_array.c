/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:10:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:53:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"
#include <stdlib.h>

t_json_value    *json_new_array(t_json_content *data)
{
    t_json_value *value;
    t_json_array *arr;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    if ((arr = json_create_array(data)) == NULL)
    {
        free(value);
        return (NULL);
    }
    value->ptr = (void *)arr;
    value->type = array;
    return (value);
}