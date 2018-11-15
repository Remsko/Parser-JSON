/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:55:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 14:30:33 by rpinoit          ###   ########.fr       */
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
    uint32_t len;
    uint32_t index;
} t_json_content;

typedef struct s_json_string
{
    char *str;
    uint32_t len;
} t_json_string;

typedef struct s_json_array
{
    t_json_value *value;
    uint32_t len;
} t_json_array;

typedef struct s_json_pair
{
    t_json_value *value;
    t_json_string *key;
} t_json_pair;

typedef struct s_json_object
{
    t_json_pair *pair;
    uint32_t len;
} t_json_object;

t_json_value *json_parse(char *src);
t_json_value *json_new_value(t_json_content *data);

void json_skip_spaces(t_json_content *data);

t_json_value_type json_get_type(t_json_content *data);

t_json_value *json_new_none(t_json_content *data);
t_json_value *json_new_null(t_json_content *data);
t_json_value *json_new_boolean(t_json_content *data);

#endif