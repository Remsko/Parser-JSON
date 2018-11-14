/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:42:41 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 20:54:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_parse(char *file)
{
    t_json_value *object;

    if (file != NULL)
    {
        object = json_get_value(file);
    }
    return (object);
}