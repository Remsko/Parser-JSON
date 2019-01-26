/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_getter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 12:48:31 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/26 12:49:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_GETTER_H
# define JSON_GETTER_H

#include "json_types.h"

t_json_value *getter_by_key(t_json_object *obj, char *key);

#endif