/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_free.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:23:24 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 15:35:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_FREE_H
#define JSON_FREE_H

#include "json_types.h"

/*
** Free feature
*/

/*
** Functions to free recursively value(s) mallocated in the parser
** Call json_free_value with the 'root' value to free all the parsed json
*/

void json_free_value(t_json_value *value);
void json_free_none(t_json_value *value);
void json_free_null(t_json_value *value);
void json_free_boolean(t_json_value *value);
void json_free_integer(t_json_value *value);
void json_free_number(t_json_value *value);
void json_free_string(t_json_value *value);
void json_free_array(t_json_value *value);
void json_free_object(t_json_value *value);

#endif
