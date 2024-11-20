CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = gnl.a

SRC = get_next_line.c get_next_line_utils.c


OBJ = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o:%.c get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY : clean
