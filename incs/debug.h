/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:06:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 16:59:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

#include "json.h"
#include <string.h>
#include <stdio.h>

char    *json_type_to_char(t_json_value_type type);
void    json_print_string(t_json_string *json_string);
void    json_print_type(t_json_value_type type);
void    json_print_number(t_json_value *number);
void    json_print_integer(t_json_value *integer);


#endif