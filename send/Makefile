CC = cc
CFLAGS = -I$(HEADERS_DIR) -Ift_printf/libft/ -Ift_printf/ -Wall -Wextra -Werror
CFLAGS_BONUS = -I$(GNL_DIR)
LDFLAGS = ft_printf/libftprintf.a
SRC_DIR = sources
FT_PRINTF_DIR = ft_printf
BONUS_DIR = bonus
GNL_DIR = $(BONUS_DIR)/gnl
HEADERS_DIR = include
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/setup.c $(SRC_DIR)/setup_utils.c $(SRC_DIR)/ps_utils.c \
$(SRC_DIR)/alg_turk.c $(SRC_DIR)/alg_turk_calcbest.c $(SRC_DIR)/alg_turk_utils.c $(SRC_DIR)/alg_turk_presort.c \
$(SRC_DIR)/push.c $(SRC_DIR)/swap.c $(SRC_DIR)/rotate.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate_utils.c \
$(SRC_DIR)/alg_backtr.c
SOURCES_BONUS = $(BONUS_DIR)/checker.c \
$(SRC_DIR)/rotate.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate_utils.c \
$(SRC_DIR)/setup.c $(SRC_DIR)/setup_utils.c $(SRC_DIR)/ps_utils.c $(SRC_DIR)/push.c $(SRC_DIR)/swap.c \
$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker
HEADERS = $(HEADERS_DIR)/alg_backtr.h $(HEADERS_DIR)/alg_turk.h $(HEADERS_DIR)/alg_turk_utils.h \
$(HEADERS_DIR)/operations.h $(HEADERS_DIR)/ps_utils.h $(HEADERS_DIR)/setup.h \
$(HEADERS_DIR)/setup_utils.h $(HEADERS_DIR)/rotate_utils.h

.PHONY : all ft_printf bonus clean fclean re

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c 
	$(CC) $(CFLAGS) $(CFLAGS_BONUS) $< -c -o $@

all : ft_printf $(NAME)	
	@echo 💗 😀 😃 😍

$(NAME) : $(OBJECTS) 	
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

ft_printf: 
	$(MAKE) -C $(FT_PRINTF_DIR) 

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJECTS_BONUS)
	$(CC) $(OBJECTS_BONUS) $(LDFLAGS) -o $@

clean :
	rm -f $(OBJECTS) $(OBJECTS_BONUS);
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
