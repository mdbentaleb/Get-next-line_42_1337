CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = gnl.a

SRC = get_next_line.c get_next_line_utils.c

OSRC = get_next_line_bonus.c get_next_line_utils_bonus.c


OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o:%.c get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus: ${OBJBONUS}
	ar rcs ${NAME} ${OBJBONUS}

clean:
	rm -rf ${OBJ} ${OBJBONUS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY : clean
