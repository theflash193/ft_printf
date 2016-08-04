# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#              #
#    Updated: 2016/03/29 01:18:28 by grass-kw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= libftprintf.a

DEBUG 			= no
HEADER			= libftprintf
### DIRECTORIES ###
DIRSRC			:= src
DIROBJ			:= obj
DIRINC			:= includes

DIRMAIN 		:= $(DIRSRC)/main
DIRCOREUTILS 	:= $(DIRSRC)/coreutils
DIRFT			:= $(DIRSRC)/ft
DIRPARSER		:= $(DIRSRC)/parser
DIRCONVERSION	:= $(DIRSRC)/conversion
DIRFLAG			:= $(DIRSRC)/flag
DIRMINFIELD		:= $(DIRSRC)/minimum_field
DIRPRECISION	:= $(DIRSRC)/precision
DIRFORMAT		:= $(DIRSRC)/format

### FILES ###
HEAD	:= $(DIRINC)/$(HEADER).h

include $(DIRMAIN)/sources.mk
include $(DIRCOREUTILS)/sources.mk
include $(DIRFT)/sources.mk
include $(DIRPARSER)/sources.mk
include $(DIRCONVERSION)/sources.mk
include $(DIRFORMAT)/sources.mk

POBJ	:= $(addprefix $(DIROBJ)/, $(OBJ))


### COMPILATION VARIABLES ###
CC	:= gcc
ifeq ($(DEBUG),yes)
	C_FLAG	:= -Wall -Werror -Wextra -g
else
	C_FLAG	:= -Wall -Werror -Wextra
endif
C_INC	:= -I $(DIRINC)
L_FLAG	:= -L $(DIRFT) -lft

COMPIL	= $(CC) $(C_FLAG) -o $@ -c $< $(C_INC)

### RULES ###
.PHONY: all clean fclean re lldb
.SILENT:

all: $(NAME)
ifeq ($(DEBUG),yes)
	@echo "Generated in DEBUG mode"
else
	@echo "Generated in RELEASE mode"
endif

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

$(NAME): $(POBJ)
	ar rc $(NAME) $(POBJ)
	ranlib $(NAME)
### LIBS ###

### MICS ###
clean:
	@rm -rf $(DIROBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

lldb: $(NAME)
	lldb $(NAME)

norme:
	@norminette $(SRCS)
	@norminette $(INC_PATH)
	@echo "[->] Total errors (May include object files) :" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)
git:
	git add .
	echo "Please, enter your commit : "
	read root_path ; git commit -m "$$root_path"
	git push

main: all
	gcc main.c -L. -lftprintf -I includes -g
	./a.out
sup: fclean
	rm -rf a.out a.out.dSYM
