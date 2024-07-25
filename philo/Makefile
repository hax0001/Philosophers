NAME = philo

FILES = philo.c \
		philo_tools.c \
		free.c \
		error.c \
		check.c \
		get_info.c \
		allocations.c \

OFILES = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all
