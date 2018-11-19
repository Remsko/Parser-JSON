/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_is_boolean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:52:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/19 14:52:55 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

bool is_boolean(const char *token)
{
    return (strncmp(token, "true", strlen("true")) == 0
        || strncmp(token, "false", strlen("false")) == 0);
}