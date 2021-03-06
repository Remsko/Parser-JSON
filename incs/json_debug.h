/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_json_debug.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:06:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 15:35:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "json_types.h"
#include <stdio.h>

/*
** Debug feature
*/

/*
** Function that return a stringified type
*/

char    *json_type_to_char(t_json_value_type type);

/*
** Recursive print functions for parsed value(s)
** Call json_print_value with the 'root' value to print all the parsed json
*/

void    json_print_value(t_json_value *value);
void    json_print_type(t_json_value_type type);
void    json_print_string(t_json_value *value);
void    json_print_object(t_json_value *value);
void    json_print_array(t_json_value *value);
void    json_print_number(t_json_value *value);
void    json_print_integer(t_json_value *value);
void    json_print_boolean(t_json_value *value);
void    json_print_null(t_json_value *value);
void    json_print_none(t_json_value *value);

#endif