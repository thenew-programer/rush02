CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(HEAD)
TESTCFLAGE = $(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer

HEAD = $(HEAD_DIR)
HEAD_DIR = includes
SRC_DIR = src
HEAD = $(SRC_DIR)/rush.h
SRCS = $(wildcard $(SRC_DIR)/*.c)

NAME = rush-02
TEST = test

all: $(NAME)

$(TEST): $(SRCS)
	$(CC) $(TESTCFLAGS) -o $@ $^
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean $(NAME) $(TEST)
