/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_none.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:28:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 13:42:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_new_none(t_json_content *data)
{
    printf("Parsing error near: '%c' at position %d\n", data->src[data->index], data->index);
    return (NULL);
}