/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_by_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:12:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 13:03:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "string.h"
#include "json_types.h"

t_json_value *getter_by_key(t_json_object *obj, char *key)
{
    t_json_string *str;
    uint32_t index;

    if (obj == NULL || obj->pair == NULL || key == NULL)
        return (NULL);
    index = 0;
    while (index < obj->len)
    {
        str = obj->pair[index].key;
        if (str == NULL || str->ptr == NULL)
            continue ;
        else if (strcmp(key, str->ptr) == 0)
            return (obj->pair[index].value);
        ++index;
    }
    return (NULL);
}