SRCS_DIR			= ./testers/
SRCS				= main.cpp \
					testsVector.cpp \
					testsStack.cpp \
					testsMap.cpp

OBJS_DIR_FT			= ./objs_ft/
OBJS_FT				= $(addprefix $(OBJS_DIR_FT), $(SRCS:.cpp=.o))

OBJS_DIR_STL		= ./objs_stl/
OBJS_STL			= $(addprefix $(OBJS_DIR_STL), $(SRCS:.cpp=.o))

NAME_FT				= FT_containers

NAME_STL			= STL_containers

RM					= rm -f

RMDIR				= rm -rf

FLAGS_FT			= -Wall -Wextra -Werror -g -D NMSPC=ft -I ./testers/testsContainers.hpp -I ./includes/Vector -I ./includes/Stack -I ./includes/Map -std=c++98

FLAGS_STL			= -Wall -Wextra -Werror -g -D NMSPC=std -I ./testers/testsContainers.hpp -I ./includes/Vector -I ./includes/Stack -I ./includes/Map -std=c++98

$(OBJS_DIR_FT)%.o :	$(SRCS_DIR)%.cpp
					@mkdir -p objs_ft
					@clang++ $(FLAGS_FT) -c $< -o $@

$(OBJS_DIR_STL)%.o :$(SRCS_DIR)%.cpp
					@mkdir -p objs_stl
					@clang++ $(FLAGS_STL) -c $< -o $@

all:				$(NAME_FT) $(NAME_STL)
					@echo "Compilation complete"

$(NAME_FT):			$(OBJS_FT)
					@echo "Compiling ft librairy..."
					@clang++ $(FLAGS_FT) $(OBJS_FT) -o $(NAME_FT) 

$(NAME_STL):		$(OBJS_STL)
					@echo "Compiling st librairy..."
					@clang++ $(FLAGS_STL) $(OBJS_STL) -o $(NAME_STL) 

clean:
					@$(RM) $(OBJS_FT) $(OBJS_STL)
					@echo "Cleaning..."

fclean:				clean
					@$(RM) $(NAME_FT) $(NAME_STL)
					@$(RMDIR) objs_stl objs_ft

re:					fclean all

.PHONY:				all clean fclean re