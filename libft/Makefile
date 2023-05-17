# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mecauchy <mecauchy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:01:39 by mecauchy          #+#    #+#              #
#    Updated: 2023/01/05 14:24:51 by mecauchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_atoi.c ft_strlen.c ft_strjoin.c ft_putstr_fd.c ft_putnbr_fd.c \
			ft_memcpy.c ft_putchar_fd.c ft_memcmp.c ft_putendl_fd.c \
			ft_strncmp.c ft_memmove.c ft_memchr.c ft_strchr.c ft_memset.c \
			ft_bzero.c ft_strrchr.c ft_calloc.c ft_substr.c ft_toupper.c \
			ft_tolower.c  ft_strdup.c ft_strnstr.c ft_strtrim.c\
			ft_striteri.c ft_split.c ft_itoa.c \
			ft_strmapi.c  ft_strlcpy.c ft_strlcat.c \
			
BONUS	=	ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c ft_lstmap_bonus.c ft_lstiter_bonus.c

BONUS_O	=	$(BONUS:.c=.o)

HEADER	=	libft.h

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

DEBUG	=	-g3

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar rc  $@ $^
			ranlib $@

%.o		:	%.c $(HEADER)
			$(CC) $(CFLAGS) $(DEBUG) -o $@ -c $<

bonus	:	$(BONUS_O) $(OBJS)
			ar rc $(NAME) $(BONUS_O) $(OBJS)
			ranlib $(NAME)

clean	:
			/bin/rm -rf $(OBJS)
			/bin/rm -rf $(BONUS_O)

fclean	:	clean
			/bin/rm -rf $(NAME)

re		:	fclean all
