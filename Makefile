SRC_PATH = srcs
DEBUG_PATH = debug

SRC_NAME =		json_parse.c \
				create/json_create_array.c \
				create/json_create_object.c \
				create/json_create_string.c \
				error/json_throw_error.c \
				len/json_array_len.c \
				len/json_object_len.c \
				new/json_new_array.c \
				new/json_new_boolean.c \
				new/json_new_integer.c \
				new/json_new_none.c \
				new/json_new_null.c \
				new/json_new_number.c \
				new/json_new_object.c \
				new/json_new_string.c \
				new/json_new_value.c \
				skip/json_skip_colon.c \
				skip/json_skip_comma.c \
				skip/json_skip_integer.c \
				skip/json_skip_number.c \
				skip/json_skip_spaces.c \
				type/json_get_type.c \
				type/json_is_boolean.c \
				type/json_is_integer.c \
				type/json_is_null.c \
				type/json_is_number.c \
				free/json_free_array.c \
				free/json_free_boolean.c \
				free/json_free_number.c \
				free/json_free_integer.c \
				free/json_free_none.c \
				free/json_free_null.c \
				free/json_free_object.c \
				free/json_free_string.c \
				free/json_free_value.c \

DEBUG_NAME =	json_print_array.c \
				json_print_boolean.c \
				json_print_integer.c \
				json_print_none.c \
				json_print_null.c \
				json_print_number.c \
				json_print_object.c \
				json_print_string.c \
				json_print_type.c \
				json_print_value.c \
				json_type_to_char.c \

OBJ_PATH = obj

CPPFLAGS = -Iincs \

LDFLAGS = 

LDLIBS = 

NAME = libjson.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra


OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME += $(DEBUG_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC += $(addprefix $(DEBUG_PATH)/,$(DEBUG_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: dir $(NAME)

dir:
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/create
	@mkdir -p $(OBJ_PATH)/error
	@mkdir -p $(OBJ_PATH)/len
	@mkdir -p $(OBJ_PATH)/new
	@mkdir -p $(OBJ_PATH)/skip
	@mkdir -p $(OBJ_PATH)/type
	@mkdir -p $(OBJ_PATH)/free

$(NAME): $(OBJ) $(LDLIBS)
	ar -rc $(NAME) $(OBJ) $(LDLIBS)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(DEBUG_PATH)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
