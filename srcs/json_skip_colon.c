/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_colon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:17:06 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 09:43:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

void json_skip_comma(t_json_content *data)
{
    while (isspace(data->src[data->index]))
        ++data->index;
    if (data->src[data->index] == ':')
        ++data->index;
}