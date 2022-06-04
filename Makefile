NAME = eval

SRC = main.c lexer.c ft_atoi.c

OBJ = $(SRC:.c=.o)

CC_FLAGS = -Wall -Wextra -Werror -pthread

CC = cc

HEADER = node.h Token.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all