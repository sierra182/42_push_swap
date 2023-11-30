CC = cc
CFLAGS = -Iinclude/ -Ift_printf/libft/ -Ift_printf/ #-Wall -Wextra -Werror
CFLAGS_BONUS = -Ignl/
LDFLAGS = ft_printf/libftprintf.a
SRC_DIR = sources
BONUS_DIR = bonus
GNL_DIR = gnl
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/setup.c $(SRC_DIR)/setup_utils.c $(SRC_DIR)/ps_utils.c $(SRC_DIR)/alg_turk.c $(SRC_DIR)/alg_turk_calcbest.c $(SRC_DIR)/alg_turk_utils.c $(SRC_DIR)/alg_turk_presort.c\
$(SRC_DIR)/push.c $(SRC_DIR)/swap.c $(SRC_DIR)/rotate.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate_utils.c \
$(SRC_DIR)/alg_backtr.c
SOURCES_BONUS = $(BONUS_DIR)/checker.c \
$(SRC_DIR)/rotate.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate_utils.c \
$(SRC_DIR)/setup.c $(SRC_DIR)/ps_utils.c $(SRC_DIR)/push.c $(SRC_DIR)/swap.c \
$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker

.PHONY : all bonus clean fclean re

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(CFLAGS_BONUS) $< -c -o $@

all : $(NAME)	

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(LDFLAGS) -o $@

clean :
	rm -f $(OBJECTS);

fclean : clean
	rm -f $(NAME)

re: fclean all
