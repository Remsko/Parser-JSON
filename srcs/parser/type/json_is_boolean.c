/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_is_boolean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:52:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:59:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdbool.h>
#include    <string.h>

bool json_is_boolean(const char *token)
{
    return (strncmp(token, "true", strlen("true")) == 0
        || strncmp(token, "false", strlen("false")) == 0);
}