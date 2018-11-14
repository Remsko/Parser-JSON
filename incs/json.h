/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:55:16 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/14 18:06:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_H
#define JSON_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

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
    e_type_length
} t_json_value_type;

typedef struct s_json_value
{
    void *ptr;
    t_json_value_type type;
} t_json_value;

typedef struct s_json_file
{
    const char *src;
    uint32_t len;
    uint32_t pos;
    uint32_t index;
} t_json_file;

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

#endif