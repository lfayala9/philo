NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

SRCS = ./srcs/utils.c \
		./srcs/dinner.c \
		./srcs/check_input.c \

INCLUDE = -lpthread

all: $(NAME)

$(NAME): $(OBJS)
				$(CC) main.c $(SRCS) $(INLCUDE) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:
		rm -rf $(OBJS)
		rm -rf $(NAME)
re: fclean all

.PHONY: all re clean fclean