/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_colon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:17:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:57:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include "json_parser.h"

void json_skip_colon(t_json_content *data)
{
    json_skip_spaces(data);
    if (data->src[data->index] == ':')
        ++data->index;
}