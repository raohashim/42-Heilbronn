# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libftprintf.a

# Source Files
SRCS = ft_printf.c ft_printf_char.c ft_printf_str.c ft_printf_int.c ft_printf_ptr.c ft_printf_hex.c

# All Target
all: $(NAME)

# Object Files
OBJS = $(SRCS:.c=.o)

# Build Library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean Object Files
clean:
	rm -f $(OBJS)

# Clean All
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# PHONY Targets
.PHONY: clean fclean re all
