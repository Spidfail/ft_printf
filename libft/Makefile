# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 18:27:40 by guhernan          #+#    #+#              #
#    Updated: 2021/02/11 17:34:54 by guhernan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CMDS	=	ar -rcs
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
LIB		=	libft.h
RM		=	rm -f
OBJ_DIR =	../obj
OBJ_PATH =	$(addprefix $(OBJ_DIR)/, $(OBJ) ) 
BONUS_PATH =	$(addprefix $(OBJ_DIR)/, $(BOBJ) ) 
VPATH	=	$(OBJ_DIR) $(AR_DIR)
OBJ		=	$(SRCS:.c=.o)
BOBJ	=	$(BONUS:.c=.o)
SRCS	=	ft_atoi.c \
ft_uatoi.c \
ft_bzero.c \
ft_calloc.c \
ft_count_base.c \
ft_scount_base.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdup.c \
ft_memjoin.c \
ft_memmove.c \
ft_memset.c \
ft_memrset.c \
ft_realloc.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strrpl.c \
ft_split.c \
ft_itoa.c \
ft_uitoa.c \
ft_strmapi.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_putnbr_base.c

BONUS	=	ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c  \
ft_lstsize.c

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CMDS) $(NAME) $(OBJ_PATH)

%.o :		%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -o $(OBJ_DIR)/$@ -c $<

$(OBJ) :	$(LIB)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

bonus:		$(OBJ) $(BONUS) $(LIB)
			$(CMDS) $(NAME) $(OBJ_PATH) $(BONUS_PATH)

.PHONY :	fclean clean re all

clean :
			$(RM) $(OBJ_PATH) $(BONUS_PATH)

fclean :	clean
			$(RM) $(NAME)
			$(RM) -R $(OBJ_DIR)

re :		fclean all
