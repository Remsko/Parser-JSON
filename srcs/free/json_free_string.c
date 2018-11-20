/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:43:56 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/20 10:04:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

void json_free_string(t_json_value *value)
{
    t_json_string *str;

    if ((str = (t_json_string *)value->ptr) != NULL)
    {
        if (str->ptr != NULL)
            free(str->ptr);
        free(str);
    }
    free(value);
}