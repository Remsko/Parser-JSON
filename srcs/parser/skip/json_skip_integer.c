/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:55:38 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:58:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include    <ctype.h>

void json_skip_integer(t_json_content *data)
{
    while (isdigit((int)data->src[data->index]))
        ++data->index;
}