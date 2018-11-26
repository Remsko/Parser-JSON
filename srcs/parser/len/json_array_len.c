/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_array_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:54:02 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/26 15:41:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdbool.h>
#include    <ctype.h>

uint32_t json_array_len(t_json_content *data)
{
    int32_t     *brackets;
    uint32_t    index;
    uint32_t    len;
    bool        quote;

    index = data->index;
    while (isspace((int)data->src[index]))
        ++index;
    if (data->src[index] == ']')
        return (0);
    len = 1;
    quote = false;
    brackets = (int32_t [2]){1, 0};
    while (data->src[index] != '\0' && brackets[0] > 0)
    {
        if (data->src[index] == ',' && brackets[0] == 1 && brackets[1] == 0 && quote == 0)
			++len;
		brackets[0] += (data->src[index] == '[') - (data->src[index] == ']');
		brackets[1] += (data->src[index] == '{') - (data->src[index] == '}');
		if (data->src[index] == '\"' && data->src[index - 1] != '\\')
			quote ^= true;
        ++index;
    }
    return (len);
}
