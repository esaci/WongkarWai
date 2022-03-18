NAME = 2048

CXX = cc
CXX_FLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
SRCS =	main.c 

OBJS_DIR = ./objects/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))
$(NAME) : $(OBJS)
	$(CXX) -lncurses $(CXX_FLAGS) $^ -o $@


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) -o $@ -c $< 
all : $(NAME)
	

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

