/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:55:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 11:42:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
#define JSON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

typedef enum e_json_value_type
{
    none = 0,
    null = 1,
    boolean = 2,
    array = 3,
    object = 4,
    integer = 5,
    number = 6,
    string = 7,
    t_type_length
} t_json_value_type;

typedef struct s_json_value
{
    void *ptr;
    t_json_value_type type;
} t_json_value;

typedef struct s_json_content
{
    const char *src;
    uint32_t index;
} t_json_content;

typedef struct s_json_string
{
    char *ptr;
    uint32_t len;
} t_json_string;

typedef struct s_json_array
{
    t_json_value **value;
    uint32_t len;
} t_json_array;

typedef struct s_json_pair
{
    t_json_string *key;
    t_json_value *value;
} t_json_pair;

typedef struct s_json_object
{
    t_json_pair *pair;
    uint32_t len;
} t_json_object;

t_json_value *json_parse(char *src);

void json_skip_spaces(t_json_content *data);
void json_skip_comma(t_json_content *data);
void json_skip_colon(t_json_content *data);
void json_skip_integer(t_json_content *data);
void json_skip_number(t_json_content *data);

t_json_value_type json_get_type(t_json_content *data);
bool json_is_boolean(const char *token);
bool json_is_integer(const char *token);
bool json_is_number(const char *token);
bool json_is_null(const char *token);


t_json_value *json_new_value(t_json_content *data);
t_json_value *json_new_none(t_json_content *data);
t_json_value *json_new_null(t_json_content *data);
t_json_value *json_new_boolean(t_json_content *data);
t_json_value *json_new_integer(t_json_content *data);
t_json_value *json_new_number(t_json_content *data);
t_json_value *json_new_string(t_json_content *data);
t_json_value *json_new_array(t_json_content *data);
t_json_value *json_new_object(t_json_content *data);

t_json_string *json_create_string(t_json_content *data);
t_json_array *json_create_array(t_json_content *data);
t_json_object *json_create_object(t_json_content *data);

uint32_t json_array_len(t_json_content *data);
uint32_t json_object_len(t_json_content *data);

void json_throw_error(t_json_content *data, char *where);

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