NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread 

SOURCE_FILES = philo.c monitor.c routine.c time.c pars.c main.c create_join_threads.c free_destroy_data.c initialize_data.c 

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

all:$(NAME)

$(NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT_FILES) 

clean:
	@rm -f $(OBJECT_FILES)
fclean: clean
	@rm -f $(NAME)
re: fclean all
