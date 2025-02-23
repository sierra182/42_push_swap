# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svidot <svidot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 06:54:46 by svidot            #+#    #+#              #
#    Updated: 2023/12/04 06:54:46 by svidot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
$(HEADERS_DIR)/setup_utils.h $(HEADERS_DIR)/rotate_utils.h $(FT_PRINTF_DIR)/ft_printf.h
HEADERS_BONUS = $(GNL_DIR)/get_next_line.h $(HEADERS_DIR)/operations.h $(HEADERS_DIR)/setup.h \
$(HEADERS_DIR)/ps_utils.h $(FT_PRINTF_DIR)/ft_printf.h
.PHONY : all ft_printf bonus clean fclean re intro l newline emoticon

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(LDFLAGS) $(HEADERS)
	@echo "\033[0;32m compiling push_swap object $<...\033[0m" 🚀
	@$(CC) $(CFLAGS) $< -c -o $@
	
$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c $(LDFLAGS) $(HEADERS_BONUS)
	@echo "\033[0;32m compiling push_swap object bonus $<...\033[0m" 🚀
	@$(CC) $(CFLAGS) $(CFLAGS_BONUS) $< -c -o $@	


all : intro ft_printf $(NAME) emoticon		

l :ft_printf $(NAME) emoticon		

$(NAME) : $(OBJECTS) 
	@echo "\n\033[0;32m linking push_swap objects with $(LDFLAGS)...\033[0m 🚀\n"
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	
intro:
	clear
	@sleep 1
	@echo -n " Wake"
	@sleep .4
	@echo " up...\n"
	@sleep .1
	@echo -n " "
	@letters="The Makefile has you..."; \
	echo "\033[1;92m$$letters\033[0m" | awk '{split($$0, chars, ""); \
	for (i = 1; i <= length($$0); i++) \
	{printf "%s", chars[i]; system("sleep 0.2");}} \
	system("sleep 1");' 
	@words="\n\n\tFollow \n\t\tthe \t\b\b\033[0;96mColored! \
	\n\n\t\t\b\b\b\b\b\b\033[1;95mUnicorne!\033[0m...🦄\n\n"; \
	for j in $${words}; do \
		echo -n "$$j"; \
		sleep .4; \
	done
	@sleep .4
	@cat mfile_design	

ft_printf: emoticon
	@$(MAKE) -s -C $(FT_PRINTF_DIR) 

emoticon:
	@echo "\n 💗 😀 😃 😍\n"

newline: 
	@echo ""

bonus : ft_printf $(NAME_BONUS) 
	@echo " 💎 🧯 🔥 😵\n"

$(NAME_BONUS) : $(OBJECTS_BONUS) 
	@echo "\n\033[0;32m linking push_swap objects bonus with $(LDFLAGS)...\033[0m 🚀\n"
	@$(CC) $(OBJECTS_BONUS) $(LDFLAGS) -o $@

clean :
	@echo "\n cleanning push_swap objects 🧻"
	@rm -f $(OBJECTS) $(OBJECTS_BONUS);
	@$(MAKE) -C $(FT_PRINTF_DIR) clean -s
	@echo ""

fclean : 
	@echo "\n cleanning push_swap objects 🧻"
	@rm -f $(OBJECTS) $(OBJECTS_BONUS);
	@echo " cleanning push_swap 🚽" 
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean -s
	@echo ""

re: fclean ft_printf $(NAME)
