# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guhernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 14:14:42 by guhernan          #+#    #+#              #
#    Updated: 2021/02/11 18:02:22 by guhernan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
MAIN		= main.c

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NCFLAGS		= -Wall -Wextra
CSAN		= -fsanitize=address -g3
ARFLAGS		= -rcs
VPATH		= . libft src obj bin inc
LARFILES	= libft.a
LIBS		= ft_printf.h $(CURDIR)/libft/libft.h
INCLUDE		= -I inc -I libft

OBJ_DIR		= obj
OBJS		= $(SRCS:.c=.o)
OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(OBJS) )

SRC_PATH	= $(addprefix src/, $(SRCS) )
SRCS		= ft_printf.c \
			  printf_format.c \
			  format_utils.c \
			  printf_prt.c \
			  printf_spec.c \
			  prt_mod.c \
			  prt_nmod.c \
			  prt_utils.c \
			  spec_utils.c \
			  spec_mod_chstr.c \
			  spec_mod_digit.c

all :		lib $(NAME) 

$(NAME) : 	$(OBJS) 	
	@cp libft/$(LARFILES) $@
	$(AR) $(ARFLAGS) $@ $(OBJ_PATH)

%.o :		%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(OBJ_DIR)/$@ -c $<

$(OBJS) :	$(LIBS) 

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR) 

bonus :		all

$(LARFILES) :
	@$(MAKE) -C libft

lib :
	@$(MAKE) -C libft

cf :		all
	@$(CC) $(INCLUDE) $(CFLAGS) $(MAIN) $(NAME) && ./a.out

cnf :		all
	@$(CC) $(INCLUDE) $(NCFLAGS) $(MAIN) $(NAME) && ./a.out

cf-san :	all
	@$(CC) $(INCLUDE) $(CSAN) $(CFLAGS) $(MAIN) $(NAME) && ./a.out

cnf-san :	all
	@$(CC) $(INCLUDE) $(CSAN) $(NCFLAGS) $(MAIN) $(NAME) && ./a.out

clean :		sclean
	$(RM) $(OBJ_PATH) 

sclean :
	$(MAKE) -C libft clean

sfclean :
	$(MAKE) -C libft fclean

fclean :	clean sfclean
	$(RM) $(NAME)

re :		fclean all

.PHONY :	cf cnf c-san cnf-san clean sclean fclean sfclean lib re all
