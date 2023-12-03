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

.PHONY : all ft_printf bonus clean fclean re intro l

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c $(LDFLAGS) $(HEADERS)
	@echo "\033[0;32mcompiling push_swap object $<...\033[0m" 🚀
	@$(CC) $(CFLAGS) $< -c -o $@
	
$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c $(LDFLAGS)
	@echo "\033[0;32mcompiling push_swap object bonus $<...\033[0m" 🚀
	@$(CC) $(CFLAGS) $(CFLAGS_BONUS) $< -c -o $@	

all : intro ft_printf $(NAME)	
	@echo 💗 😀 😃 😍

l :ft_printf $(NAME)	
	@echo 💗 😀 😃 😍

$(NAME) : $(OBJECTS) 
	@echo "\033[0;32mlinking push_swap all objects with $(LDFLAGS)...\033[0m" 🚀
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@

intro:
	clear
	@sleep 1
	@echo -n " Wake"
	@sleep .4
	@echo " up...\n"
	@sleep .2
	@echo -n " "
	@letters="The Makefile has you..."; \
	echo "\033[1;92m$$letters\033[0m" | awk '{split($$0, chars, ""); \
	for (i = 1; i <= length($$0); i++) \
	{printf "%s", chars[i]; system("sleep 0.2");}} \
	system("sleep 1");' 
	@words="\n\n\tFollow \n\t\tthe \t\b\b\b\033[0;96mColored! \
	\n\n\t\t\b\b\b\b\b\b\033[1;95mUnicorne!\033[0m...🦄\n\n"; \
	for j in $${words}; do \
		echo -n "$$j"; \
		sleep .4; \
	done
	@sleep .4
	@cat lic.txt
	@echo "\n"		

ft_printf:		
	@$(MAKE) -s -C $(FT_PRINTF_DIR) 

bonus : ft_printf $(NAME_BONUS) 
	@echo 💎 🧯 🔥 😵

$(NAME_BONUS) : $(OBJECTS_BONUS) 
	@echo "\033[0;32mlinking push_swap all objects bonus with $(LDFLAGS)...\033[0m" 🚀
	@$(CC) $(OBJECTS_BONUS) $(LDFLAGS) -o $@

clean :
	@echo cleanning push_swap objects 🧻
	@rm -f $(OBJECTS) $(OBJECTS_BONUS);
	@$(MAKE) -C $(FT_PRINTF_DIR) clean -s

fclean : 
	@echo cleanning push_swap objects 🧻
	@rm -f $(OBJECTS) $(OBJECTS_BONUS);
	@echo cleanning push_swap 🚽 
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean -s

re: fclean ft_printf $(NAME)
