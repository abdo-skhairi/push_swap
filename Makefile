CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =   push.c pushswap.c split.c swap.c input.c rev_rotate.c rotate.c sort_all.c creat_stacks.c free.c
OBJ = $(SRC:.c=.o)
EXEC = prog

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c pushswap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
