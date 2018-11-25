/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_is_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:50:58 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 15:00:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdbool.h>
#include    <ctype.h>

bool json_is_number(const char *token)
{
    uint32_t i;

    i = 0;
    if (token[i] == '-')
        ++i;
    while (isdigit((int)token[i]))
        ++i;
    if (token[i] == '.')
        return (true);
    return (false);
}