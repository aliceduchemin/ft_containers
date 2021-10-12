SRCS		= ./Map/main.cpp
#./Vector/testVector.cpp
#./Vector/main.cpp \
			./Vector/tests.cpp \
			./Vector/menu.cpp
#./Map/main.cpp

OBJS		= $(SRCS:.cpp=.o)

NAME		= container_tests

CC			= clang++

CXX			= clang++

RM			= rm -f

FLAGS		= -Wall -Wextra -Werror -g -I . -I ./Vector -I ./Stack -I ./Map -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) ${FLAGS} ${OBJS} -o ${NAME}

valgrind:	$(NAME)
			valgrind ./$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
