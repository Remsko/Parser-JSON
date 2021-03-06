/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_is_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:51:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:59:39 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdbool.h>
#include    <ctype.h>

bool json_is_integer(const char *token)
{
    uint32_t i;

    i = 0;
    if (token[i] == '-')
        ++i;
    if (isdigit((int)token[i]))
        return (true);
    return (false);
}