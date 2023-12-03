# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/12/03 18:23:59 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTDIR = ./libft
LIBFTPATH = $(LIBFTDIR)/libft.a

.PHONY : all libft clean fclean re 

all : libft $(NAME)
	
libft : 	
	@$(MAKE) -s -C $(LIBFTDIR) && \
	$(MAKE) -s -C $(LIBFTDIR) bonus
	
%.o : %.c $(LIBFTPATH) $(HEADER)
	@echo "\033[0;32mcompiling $<...\033[0m" 🚀
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) :: $(LIBFTPATH)
	@echo "\033[0;32mcopying $(LIBFTPATH) to $(NAME)...\033[0m" 🚀
	cp $(LIBFTPATH) $(NAME)

$(NAME) :: $(OBJECTS)
	@echo "\033[0;32madding $(OBJECTS) to $(NAME)...\033[0m" 🚀	
	ar rcs $@ $(OBJECTS)	
	
clean :
	@echo cleanning ft_printf objects 🧻
	@rm -f $(OBJECTS)
	@$(MAKE) -C $(LIBFTDIR) clean 
	
fclean : 
	@echo cleanning ft_printf objects 🧻
	@rm -f $(OBJECTS)
	@echo cleanning libftprintf.a 🚽 
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean 
	
re : fclean all
