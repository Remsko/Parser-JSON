/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free_boolean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:41:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:45:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdlib.h>

void json_free_boolean(t_json_value *value)
{
    if (value->ptr != NULL)
        free(value->ptr);
    free(value);
}