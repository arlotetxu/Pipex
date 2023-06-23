# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorido <jflorido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 16:24:39 by jflorido          #+#    #+#              #
#    Updated: 2022/10/03 09:22:21 by jflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c  ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_strlcpy.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c

SRC_Bonus = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_Bonus = $(SRC_Bonus:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR      = ar 
AFLAG   = -rc

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(AR) $(AFLAG) $(NAME) $^

bonus: $(OBJS) $(OBJS_Bonus)
	$(AR) $(AFLAG) $(NAME) $^

clean:
	$(RM) $(OBJS) $(OBJS_Bonus)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
