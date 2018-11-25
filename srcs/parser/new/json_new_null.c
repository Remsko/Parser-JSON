/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:58:34 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:55:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdlib.h>
#include    <string.h>

t_json_value *json_new_null(t_json_content *data)
{
    t_json_value *value;

    if ((value = (t_json_value *)malloc(sizeof(t_json_value))) == NULL)
        return (NULL);
    value->ptr = NULL;
    value->type = null;
    data->index += strlen("null");
    return (value);
}