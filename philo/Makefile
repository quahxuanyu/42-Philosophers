# Directories
SRCDIR = src/
OBJDIR = objs/
SRC_FILES = main.c \
			initialize.c \
			utils.c

SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

#FLAGS = -Wall -Wextra -Werror
FLAGS =

PHILO = philosophers
NAME = $(PHILO)

# Rules
all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft