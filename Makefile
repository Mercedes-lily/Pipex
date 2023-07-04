# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 13:45:22 by vst-pier          #+#    #+#              #
#    Updated: 2023/05/30 13:02:46 by vst-pier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
LIBFT = libft/libft.a
DEP = inc/pipex.h
DEP_BONUS = inc/pipex_bonus.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MK = mkdir -p					
RM = rm -rf

#Sources directories
INCDIR = inc
SRCDIR = src
SRCDIR_BONUS = src_bonus
LIBFTDIR = libft

SRC = free_message.c file_and_exec.c pipex.c path.c process.c
SRC_BONUS = free_message_bonus.c file_and_exec_bonus.c pipex_bonus.c path_bonus.c process_bonus.c
		
VPATH = $(SRCDIR) $(SRCDIR_BONUS)

#Object directories
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(SRC_BONUS:%.c=%.o))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJDIR) $(OBJ_BONUS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
$(OBJDIR)/%.o : %.c $(DEP_BONUS)
	$(CC) $(CFLAGS) -I$(INCDIR) -Ilibft/inc -c $< -o $@


$(NAME): $(OBJDIR) $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
$(OBJDIR)/%.o : %.c $(DEP)
	$(CC) $(CFLAGS) -I$(INCDIR) -Ilibft/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFTDIR) fclean

re: fclean all

rebonus: fclean bonus