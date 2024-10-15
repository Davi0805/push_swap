MAKEFLAGS += -s

NAME = libftprintf.a
CC = gcc
LIBFTNAME = libft.a
LIBFTDIR = ./Libft
FLAGS = -Wall -Wextra -Werror
AR = ar

GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

SRCS = ft_putchar.c ft_putint.c ft_putstr.c ft_putpercent.c ft_puthexupcase.c \
		ft_putpointer.c ft_putunsint.c ft_puthexlowcase.c ft_printf.c \

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJ)
	@echo "# $(GREEN)Building printf...$(NC)"
	@$(AR) -r $(NAME) $(OBJ)

clean:
	@rm -f *.o
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
