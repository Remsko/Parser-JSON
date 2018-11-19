SRC_PATH = srcs
DEBUG_PATH = debug

SRC_NAME = json_parse.c \
			\
			json_get_type.c \
			\
			json_new_value.c \
			json_new_none.c \
			json_new_null.c \
			json_new_boolean.c \
			json_new_integer.c \
			json_new_number.c \
			json_new_string.c \
			json_new_array.c \
			json_new_object.c \
			\
			json_skip_spaces.c \
			json_skip_comma.c \
			json_skip_colon.c \
			\
			json_create_string.c \
			json_create_array.c \
			json_create_object.c \
			\
			json_throw_error.c \

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
				json_get_type.c \

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