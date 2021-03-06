/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:56:04 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:58:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"

void json_skip_number(t_json_content *data)
{
    json_skip_integer(data);
    if (data->src[data->index] == '.')
        ++data->index;
    json_skip_integer(data);
}