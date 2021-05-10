SRCS		= main.cpp

OBJS		= $(SRCS:.cpp=.o)

NAME		= container_tests

CC			= clang++

CXX			= clang++

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I . -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o ${NAME} ${OBJS} ${CFLAGS}

valgrind:	$(NAME)
			valgrind ./$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
