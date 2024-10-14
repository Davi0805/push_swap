NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ./Libft
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = main.c parsing.c lst_movements.c lst_utils.c\

all: push_swap

$(NAME): $(LIBFTDIR)/$(LIBFTNAME)
		cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
		make -C $(LIBFTDIR)

push_swap: $(NAME) main.o $(OBJS)
		$(CC) $(FLAGS) -o push_swap $(OBJS) $(NAME)
%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	rm -f push_swap
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
