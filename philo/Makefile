NAME = philo

FILES = philo.c \
		philo_tools.c \

OFILES = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC == CC

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

$(OFILES) :
	$(CC) $(FLAGS) $(FILES)

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all
