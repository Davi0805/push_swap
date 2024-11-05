MAKEFLAGS += -s

NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ./Libft
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
SRCS = main.c parsing.c lst_movements.c lst_movements_2.c lst_utils.c sort_funcs.c lst_utils_2.c Error.c sort_utils.c\

GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

all: push_swap

$(NAME): $(LIBFTDIR)/$(LIBFTNAME)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
	@make -C $(LIBFTDIR)

push_swap: $(NAME) $(OBJS)
	@echo "# $(GREEN)Building project...$(NC)"
	@$(CC) $(FLAGS) -o push_swap $(OBJS) $(NAME) && echo "$(GREEN)Done!$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@cd $(LIBFTDIR) && make clean
	@echo "# $(YELLOW)Cleaning...$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@rm -f push_swap
	@cd $(LIBFTDIR) && make fclean
	@echo "# $(RED)Fully Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re
