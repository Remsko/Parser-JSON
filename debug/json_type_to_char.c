/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_type_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:44:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 09:15:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

char *json_type_to_char(t_json_value_type type)
{
    static char *str[] = {
        [none] = "none",
        [null] = "null",
        [boolean] = "boolean",
        [array] = "array",
        [object] = "object",
        [integer] = "integer",
        [number] = "number",
        [string] = "string",
    };

    return (str[type]);
}