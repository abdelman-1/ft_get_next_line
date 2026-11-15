CFILES = get_next_line.c get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
NAME = get_next_line.a
OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re