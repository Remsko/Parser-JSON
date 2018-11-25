/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_skip_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:47:18 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:58:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include    <ctype.h>

void    json_skip_spaces(t_json_content *data)
{
    while (isspace((int)data->src[data->index]))
        ++data->index;
}