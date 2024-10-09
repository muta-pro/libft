CC : cc
CFLAGS : -Wall -Wextra -Werror
SRCS : libft.h ft_*.c
OBJS : $(SRCS: .c=.o)
NAME : libft.a
all : $(NAME)
$(SRCS): $(OBJS)
	$(CC) $(CFLAGS) -o $(SRCS) $(OBJS)
clean : rm -f $(OBJS)
fclean : rm -f $(SRCS)
re : fclean all

