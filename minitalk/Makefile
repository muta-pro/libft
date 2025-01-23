# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 13:14:48 by imutavdz          #+#    #+#              #
#    Updated: 2025/01/20 18:01:21 by imutavdz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = receiver.c sender.c
BONUS_SRCS = 
HDR = libft.h
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS: .C=.O)
client: $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) -o client
server: $(OBJS_SERVER)
	$(CC) $(OBJS_SERVER) -o server 
all: client server
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(BONUS_OBJS) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
clean:
	rm -f client server *.o
fclean: fclean
	rm -f $(NAME)
re : fclean all