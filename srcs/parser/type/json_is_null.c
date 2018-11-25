/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_is_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:53:15 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 14:59:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_types.h"
#include <stdbool.h>
#include    <string.h>

bool json_is_null(const char *token)
{
    return (strncmp(token, "null", strlen("null")) == 0);
}