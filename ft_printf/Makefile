# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svidot <svidot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/11/01 11:08:05 by svidot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTDIR = ./libft
LIBFTPATH = ./libft/libft.a

.PHONY : all libft clean fclean re 

all : libft $(NAME)
	
libft : 
	$(MAKE) -C $(LIBFTDIR)	
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) :: $(LIBFTPATH)
	cp $(LIBFTPATH) $(NAME)	
	
$(NAME) :: $(OBJECTS) $(LIBFTPATH)
	ar rcs $@ $(OBJECTS)
	
clean :
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	
re : fclean all