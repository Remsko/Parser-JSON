/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_create_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:35:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/16 16:56:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include "debug.h"

uint32_t json_array_len(t_json_content *data)
{
    uint32_t len;
    uint32_t index;
    uint32_t *checker;

    checker = (uint32_t [3]){1, 0, 0};
    index = data->index;
    while (isspace((int)data->src[index]))
    {
        printf("Pass space\n");
        ++index;
    }
    if (data->src[index] == ']')
    {
        printf("Pass square\n");
        return (0);
    }
    len = 1;
    while (data->src[index] != '\0' && checker[0] > 0)
    {
        printf("%c\n", data->src[index]);
        if (data->src[index] == ',' && checker[0] == 1 && checker[1] == 0 && checker[2] == 0)
			++len;
		checker[0] += (data->src[index] == '[') - (data->src[index] == ']');
		checker[1] += (data->src[index] == '{') - (data->src[index] == '}');
		if (data->src[index] == '\"')
			checker[2] ^= 1;
        ++index;
    }
    return (len);
}

t_json_array *json_create_array(t_json_content *data)
{
    t_json_array *arr;
    size_t len;

    if ((arr = (t_json_array *)malloc(sizeof(t_json_array))) == NULL)
        return (NULL);
    arr->len = json_array_len(data);
    printf("len = %d\n", arr->len);
    if ((arr->value = (t_json_value *)malloc(sizeof(t_json_value) * arr->len)) == NULL)
    {
        free(arr);
        return (NULL);
    }
    len = 0;
    while (len < arr->len)
    {
        arr->value[len] = *json_new_value(data);
        json_skip_comma(data);
        json_print_value(&arr->value[len]);
        ++len;
    }
    return (arr);
}