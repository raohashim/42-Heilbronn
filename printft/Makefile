# Compiler
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

# Library Name
NAME = libftprintf.a

# Source Files
SRCS = ft_printf.c ft_printf_char.c ft_printf_str.c ft_printf_int.c ft_printf_utils.c ft_printf_ptr.c ft_printf_un_sig.c ft_printf_hex.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Executable Name
#EXEC = ft_printf_exec

# All Target
#all: $(NAME) $(EXEC)
all: $(NAME)

# Build Library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Build Executable
#$(EXEC): $(OBJS)
#	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compile Object Files
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@

# Clean Object Files
clean:
	rm -f $(OBJS)

# Clean All
fclean: clean
#	rm -f $(NAME) $(EXEC)
	rm -f $(NAME)

# Rebuild
re: fclean all

# PHONY Targets
.PHONY: clean fclean re all
