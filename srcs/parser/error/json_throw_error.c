/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_throw_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:15:44 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:50:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include    <stdio.h>

void    json_throw_error(t_json_content *data, char *where)
{
    printf("Parsing %s error near: '%c' at position %d\n",
        where, data->src[data->index], data->index);
}