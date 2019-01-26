NAME = libjson.a
CC = gcc
RM = rm -rf

INC_PATH = incs
INC_NAME += json_types.h
INC_NAME += json_parser.h
INC_NAME += json_debug.h
INC_NAME += json_free.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = $(addprefix -I,$(INC_PATH))

SRC_PATH = srcs

SRC_SUB += debug
SRC_NAME += json_print_array.c
SRC_NAME += json_print_boolean.c
SRC_NAME += json_print_integer.c
SRC_NAME += json_print_none.c
SRC_NAME += json_print_null.c
SRC_NAME += json_print_number.c
SRC_NAME += json_print_object.c
SRC_NAME += json_print_string.c
SRC_NAME += json_print_type.c
SRC_NAME += json_print_value.c
SRC_NAME += json_type_to_char.c

SRC_SUB += free
SRC_NAME += json_free_array.c
SRC_NAME += json_free_boolean.c
SRC_NAME += json_free_integer.c
SRC_NAME += json_free_none.c
SRC_NAME += json_free_null.c
SRC_NAME += json_free_number.c
SRC_NAME += json_free_object.c
SRC_NAME += json_free_string.c
SRC_NAME += json_free_value.c

SRC_SUB += parser
SRC_NAME += json_parse.c

SRC_SUB += parser/create
SRC_NAME += json_create_array.c
SRC_NAME += json_create_object.c
SRC_NAME += json_create_string.c

SRC_SUB += parser/error
SRC_NAME += json_throw_error.c

SRC_SUB += parser/len
SRC_NAME += json_array_len.c
SRC_NAME += json_object_len.c

SRC_SUB += parser/new
SRC_NAME += json_new_array.c
SRC_NAME += json_new_boolean.c
SRC_NAME += json_new_integer.c
SRC_NAME += json_new_none.c
SRC_NAME += json_new_null.c
SRC_NAME += json_new_number.c
SRC_NAME += json_new_object.c
SRC_NAME += json_new_string.c
SRC_NAME += json_new_value.c

SRC_SUB += parser/skip
SRC_NAME += json_skip_colon.c
SRC_NAME += json_skip_comma.c
SRC_NAME += json_skip_integer.c
SRC_NAME += json_skip_number.c
SRC_NAME += json_skip_spaces.c

SRC_SUB += parser/type
SRC_NAME += json_get_type.c
SRC_NAME += json_is_boolean.c
SRC_NAME += json_is_integer.c
SRC_NAME += json_is_null.c
SRC_NAME += json_is_number.c

SRC_SUB += getter
SRC_NAME += getter_by_key.c

vpath %.c $(addprefix $(SRC_PATH)/,$(SRC_SUB))

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

$(OBJ): $(INC) | $(OBJ_PATH)
$(OBJ): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
