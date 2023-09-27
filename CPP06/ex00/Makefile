NAME		= ex00
CC			= g++
FLAGS		= -Wall -Wextra -Werror -std=c++98 
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 
SRC 		= ScalarConverter.cpp main.cpp 
OBJ 		= $(SRC:.cpp=.o)

# T E X T   S T U F F
G		= \033[0;92m
R		= \033[0;31m
B		= \033[0;96m
Y		= \033[0;33m
WY		= \033[0;93m
M		= \033[0;95m
BOLD	= \033[0;1m
E		= \033[0m

all: nice_text $(NAME)

nice_text:
	@echo "$(Y)"
	@echo " ██████╗██████╗ ██████╗        ██████╗  ██████╗ "
	@echo "██╔════╝██╔══██╗██╔══██╗      ██╔═████╗██╔════╝ "
	@echo "██║     ██████╔╝██████╔╝█████╗██║██╔██║███████╗ "
	@echo "██║     ██╔═══╝ ██╔═══╝ ╚════╝████╔╝██║██╔═══██╗"
	@echo "╚██████╗██║     ██║           ╚██████╔╝╚██████╔╝"
	@echo " ╚═════╝╚═╝     ╚═╝            ╚═════╝  ╚═════╝ " 
	@echo "$(B)      EX00: CONVERSION OF ESCALAR TYPES"                    
	@echo "$(B)     $(E)"          
	         
	@echo ""  

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(G) Program name : $(NAME)$(E)"
	@echo ""

clean:
	@rm -rf $(OBJ)
	@echo "$(M) Everything cleaned. $(E)"

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.SILENT: all, OBJ
.PHONY: all clean fclean re
