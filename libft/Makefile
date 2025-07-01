NAME = libft.a
AR = ar -rcs
CC = gcc

# Directories
SRC_DIR = #./src/
OBJS_DIR = #./objs/
BIN_DIR	= #./bin/

SRC_FILES = $(wildcard $(SRC_DIR)*.c)

# CC Flags
CFLAGS = -Wall -Wextra -Werror

# Add directory prefix to source files
#SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))
#SRC_BONUS = $(addprefix $(SRC_DIR),$(BONUS_FILES))

# Include directory flags
INCLUDES = #-I ./includes/

# Object files
OBJS_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
OBJS_BONUS_FILES = $(SRC_BONUS_FILES:.c=.o)
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(OBJS_BONUS_FILES))
#OBJS_TEST_FILE = $(addprefix $(OBJS_DIR), $(TESTFILE:.c=.o))

# Binaries
#BIN_TEST = $(addprefix $(BIN_DIR), test)

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

#test: ${OBJS_DIR} ${BIN_DIR} ${OBJS} ${OBJS_BONUS} ${OBJS_TEST_FILE}
#	${CC} ${CFLAGS} ${OBJS} ${OBJS_BONUS} ${OBJS_TEST_FILE} -o ${BIN_TEST} -lbsd

#$(OBJS_DIR):
#	mkdir -p $(OBJS_DIR)

#$(BIN_DIR):
#	mkdir -p $(BIN_DIR)

%.o: %.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

clean:
	rm -f $(addprefix ${SRC_DIR},${OBJS_FILES}) ${OBJS} ${OBJS_TEST} ${OBJS_BONUS}

fclean: clean
	rm -rf ${BIN_DIR} ${OBJS_DIR}
	rm -f ${NAME} test

re: fclean all

#retest: fclean test

.PHONY: all clean fclean re
