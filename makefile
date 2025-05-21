GREEN		=	\033[1;32m
LIGHT_GREEN	=	\033[0;32m
RED			=	\033[1;31m
YELLOW		=	\033[0;33m
ITALIC		=	\033[3m
RESET		=	\033[0m


NAME 		= push_swap

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

# Includes
INCLUDE		= -I ./includes/

# Directories
SRC_DIR			= ./src/
SRC_DIR_BONUS	= ./src_bonus/
OBJS_DIR		= ./objs/
LIBFT_DIR		= ./libft/

# Source Files
SRC_FILES = push_swap.c \
			sorting_algos.c \
			utils1.c \
			operations_push.c \
			operations_swap.c \
			operations_rotate.c \
			print_stacks.c

SRC_FILES_BONUS = 

# Object Files
OBJS_FILES			= $(SRC_FILES:.c=.o)
OBJS_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)
OBJS				= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_BONUS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES_BONUS))

all: ${NAME}

# creating executables
${NAME}: ${OBJS_DIR} ${OBJS}
	@echo ""
	@echo "$(YELLOW) Preparing push_swap... $(RESET)"
	@${CC} ${CFLAGS} ${OBJS} -L${LIBFT_DIR} -lft -o ${NAME}
	@echo "$(LIGHT_GREEN) push_swap successfully compiled.$(RESET)"

bonus: ${OBJS_DIR} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -L${LIBFT_DIR} -lft -o ${NAME}

# Create Object files
$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	${CC} ${CFLAGS} -c ${INCLUDE} $< -o $@

$(OBJS_DIR)%.o: $(SRC_DIR_BONUS)%.c
	${CC} ${CFLAGS} -c ${INCLUDE} $< -o $@

# Creating Objects dir
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	@echo ""
	@echo "$(RED)Did someone call - $(ITALIC)pause$(RESET)$(RED) - the Clean-up crew?!$(RESET)"
	@$ rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

rebonus: fclean bonus

.PHONY: all clean fclean re
