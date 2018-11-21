/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:33:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/21 15:52:24 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_TYPES_H
#define JSON_TYPES_H

#include <stdint.h>

/*
** Main structures of the parser
** Relative to the json norm
*/

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

#endif