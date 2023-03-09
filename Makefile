NAME = push_swap
CC = cc
CFLAGS =-Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_DIR = libft

LIB = $(addprefix $(LIBFT_DIR)/, $(LIBFT))

MY_SOURCES = main.c \
	push_swap.c \
	parsing.c \
	ft_lists.c \
	rank.c \
	instruction.c \
	instruction_1.c \
	instruction_2.c \
	instruction_3.c \
	utils_algo.c \
	utils_algo2.c \
	algo.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(MY_OBJECTS) $(LIB)

clean:
	rm -r $(MY_OBJECTS)
	make clean -C libft

fclean: clean
	rm -r $(NAME)
	rm -r libft/libft.a

re: all
