CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =   push.c pushswap.c split.c swap.c utils1.c rev_rotate.c rotate.c
OBJ = $(SRC:.c=.o)
EXEC = prog

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
