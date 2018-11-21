/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:55:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 15:51:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
#define JSON_H

#include <stdbool.h>
#include <stdint.h>

#include "json_types.h"

/*
** Parser feature
*/

/*
** The entry take a string of the potentially normed json
*/

t_json_value *json_parse(char *src);

/*
** Function that get to the next token
*/

void json_skip_spaces(t_json_content *data);
void json_skip_comma(t_json_content *data);
void json_skip_colon(t_json_content *data);
void json_skip_integer(t_json_content *data);
void json_skip_number(t_json_content *data);

/*
** Function that identify the token type
*/

t_json_value_type json_get_type(t_json_content *data);
bool json_is_boolean(const char *token);
bool json_is_integer(const char *token);
bool json_is_number(const char *token);
bool json_is_null(const char *token);

/*
** Main function of the parser that redirect to token type relative function
** Can be recall in new object/array : refere to json norm
*/

t_json_value *json_new_value(t_json_content *data);

/*
** Allocate the token and transform it relatively to the type
** Specific typedef for string, object, array
*/

t_json_value *json_new_none(t_json_content *data);
t_json_value *json_new_null(t_json_content *data);
t_json_value *json_new_boolean(t_json_content *data);
t_json_value *json_new_integer(t_json_content *data);
t_json_value *json_new_number(t_json_content *data);
t_json_value *json_new_string(t_json_content *data);
t_json_value *json_new_array(t_json_content *data);
t_json_value *json_new_object(t_json_content *data);

/*
** More complicated function to create values that have a length
*/

t_json_string *json_create_string(t_json_content *data);
t_json_array *json_create_array(t_json_content *data);
t_json_object *json_create_object(t_json_content *data);

/*
** Calculate length of special values : refere to the typedef and json norm
*/

uint32_t json_array_len(t_json_content *data);
uint32_t json_object_len(t_json_content *data);

/*
** Log a syntax error
*/

void json_throw_error(t_json_content *data, char *where);

#endif