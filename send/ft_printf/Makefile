# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/12/02 08:09:58 by marvin           ###   ########.fr        #
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
PASS = 0

.PHONY : all libft clean fclean re 

all : libft $(NAME)
	
libft : 
	$(MAKE) -C $(LIBFTDIR) && \
	$(MAKE) -C $(LIBFTDIR) bonus
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) :: $(LIBFTPATH) | $(OBJECTS)
	cp $< $@	
	ar rcs $@ $(OBJECTS)	
	$(eval PASS = 1)
	
$(NAME) :: $(OBJECTS) 
	@if [ $(PASS) -eq 0 ]; then \
		echo "only modified objects: ar rcs $@ $?"; \
		ar rcs $@ $?; \
	fi

clean :
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	
re : fclean all