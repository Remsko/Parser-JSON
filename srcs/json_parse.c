/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:42:41 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 11:44:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_parse(char *src)
{
    t_json_value *value;
    t_json_content *data;

    if (src == NULL)
        return (NULL);
    if ((data = (t_json_content *)malloc(sizeof(t_json_content))) == NULL)
        return (NULL);
    data->index = 0;
    data->src = (const char *)src;
    value = json_new_value(data);
    free(data);
    json_free_value(value);
    return (value);
}