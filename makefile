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
BIN_DIR			= ./bin/

# Source Files
SRC_FILES = push_swap.c \
			sorting_algos.c \
			utils1.c \
			utils2.c \
			operations_push.c \
			operations_swap.c \
			operations_rotate.c \
			print_stacks.c \
			engine.c \
			init_stack.c

SHARED_FILES = init_stack.c \
				operations_push.c \
				operations_swap.c \
				operations_rotate.c \
				print_stacks.c \
				utils1.c \
				utils2.c

SRC_FILES_BONUS = checker.c

# Complete source lists with full paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRC_FILES_BONUS)) $(addprefix $(SRC_DIR), $(SHARED_FILES))

# Object Files
OBJS_FILES			= $(SRC_FILES:.c=.o)
OBJS_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o) $(SHARED_FILES:.c=.o)
OBJS				= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_BONUS			= $(addprefix $(OBJS_DIR), $(OBJS_FILES_BONUS))

# Binary File
BIN					= $(addprefix $(BIN_DIR), $(NAME))

all: ${NAME}

# creating executables
${NAME}: ${OBJS_DIR} ${BIN_DIR} ${OBJS}
	@echo ""
	@echo "$(YELLOW) Preparing push_swap... $(RESET)"
	@${CC} ${CFLAGS} ${OBJS} -L${LIBFT_DIR} -lft -o ${BIN}
	@echo "$(LIGHT_GREEN) push_swap successfully compiled.$(RESET)"

bonus: ${OBJS_DIR} ${BIN_DIR} ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -L${LIBFT_DIR} -lft -o ./bin/checker

# Create Object files
$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	${CC} ${CFLAGS} -c ${INCLUDE} $< -o $@

$(OBJS_DIR)%.o: $(SRC_DIR_BONUS)%.c
	${CC} ${CFLAGS} -c ${INCLUDE} $< -o $@

# Creating Objects dir
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Creating Objects dir
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	@echo ""
	@echo "$(RED)Did someone call - $(ITALIC)pause$(RESET)$(RED) - the Clean-up crew?!$(RESET)"
	@$ rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(BIN_DIR) output* ./tests/

re: fclean $(NAME)

rebonus: fclean bonus

rebonus: fclean bonus

.PHONY: all clean fclean re
