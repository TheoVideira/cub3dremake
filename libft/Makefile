# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvideira <tvideira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:51:31 by tvideira          #+#    #+#              #
#    Updated: 2020/03/06 03:51:07 by tvideira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_power.c ft_putchar_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c\
ft_toupper.c ft_max.c ft_strcmp.c ft_min.c
OBJ=$(SRC:.c=.o)
HEADERS=libft.h
BONUS_SRC = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c\
ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ=$(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus:
	@make all OBJ="$(OBJ) $(BONUS_OBJ)"

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
