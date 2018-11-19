/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:43:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 17:47:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

void json_free_double(t_json_value *value)
{
    if (value->ptr != NULL)
        free(value->ptr);
    free(value);
}