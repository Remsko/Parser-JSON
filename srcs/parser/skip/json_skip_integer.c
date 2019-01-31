/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:55:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/31 13:25:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include    <ctype.h>

void json_skip_integer(t_json_content *data)
{
    if (data->src[data->index] == '-')
        ++data->index;
    while (isdigit((int)data->src[data->index]))
        ++data->index;
}