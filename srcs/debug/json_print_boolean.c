/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_boolean.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:59:56 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 15:46:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_debug.h"
#include <stdbool.h>

void    json_print_boolean(t_json_value *value)
{
    printf("(bool)%s", *(bool *)(value->ptr) ? "true" : "false");
}