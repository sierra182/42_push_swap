CC = cc
CFLAGS = -Iinclude #-Wall -Wextra -Werror
LDFLAGS = ft_printf/libftprintf.a
SRC_DIR = sources
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/setup.c $(SRC_DIR)/push.c $(SRC_DIR)/swap.c \
$(SRC_DIR)/rotate.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate_utils.c
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap

.PHONY : all

%.o : %.cc
	$(CC) $(CFLAGS) $< -c -o $@

all :
	$(NAME)

$(NAME)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@