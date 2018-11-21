/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_new_none.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:28:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/15 21:17:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"

t_json_value *json_new_none(t_json_content *data)
{
    json_throw_error(data, "token");
    return (NULL);
}