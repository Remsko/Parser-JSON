/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_print_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:57:30 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 21:18:42 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void    json_print_number(t_json_value *value)
{
    printf("(number)%f", *(double *)value->ptr);
}