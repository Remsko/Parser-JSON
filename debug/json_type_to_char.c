/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_type_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:44:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 16:12:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

char *json_type_to_char(t_json_value_type type)
{
    char *ret;

    ret = NULL;
    if (type == 0)
        ret = strdup("none");
    if (type == 1)
        ret = strdup("null");
    if (type == 2)
        ret = strdup("boolean");
    if (type == 3)
        ret = strdup("array");
    if (type == 4)
        ret = strdup("object");
    if (type == 5)
        ret = strdup("integer");
    if (type == 6)
        ret = strdup("number");
    if (type == 7)
        ret = strdup("string");
    return (ret);
}