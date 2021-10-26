SRCS		= ./main42.cpp #\
			./testers/testsVector.cpp \
			./testers/testsStack.cpp \
			./testers/testsMap.cpp
#./Vector/testVector.cpp
#./Vector/main.cpp \
			./Vector/tests.cpp \
			./Vector/menu.cpp
#./Map/main.cpp

OBJS		= $(SRCS:.cpp=.o)

NAME		= test

CC			= clang++

CXX			= clang++

RM			= rm -f

FLAGS		= -Wall -Wextra -Werror -g -I . -I ./includes -I ./includes/Vector -I ./includes/Stack -I ./Map -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) ${FLAGS} ${OBJS} -o ${NAME}

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
