# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 18:12:44 by victofer          #+#    #+#              #
#    Updated: 2023/06/23 12:53:39 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
SRC = megaphone.cpp
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

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
	@echo " ██████╗██████╗ ██████╗        ██████╗  ██████╗" 
	@echo "██╔════╝██╔══██╗██╔══██╗      ██╔═████╗██╔═████╗"
	@echo "██║     ██████╔╝██████╔╝█████╗██║██╔██║██║██╔██║"
	@echo "██║     ██╔═══╝ ██╔═══╝ ╚════╝████╔╝██║████╔╝██║"
	@echo "╚██████╗██║     ██║           ╚██████╔╝╚██████╔╝"
	@echo " ╚═════╝╚═╝     ╚═╝            ╚═════╝  ╚═════╝ "
	@echo "$(B) 	 	  EX00 MEGAPHONE 				 $(E)"                   
	@echo ""                   

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "$(M) Everything cleaned. $(E)"

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

.SILENT: all, OBJ
.PHONY: all clean fclean re
