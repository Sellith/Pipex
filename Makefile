#---------------------------------------------------#
#            information de compilation             #
#---------------------------------------------------#

TARGET		=	$(BIN_DIR)/pipex
CC 			=	gcc
CFLAGS 		=	-Wall -Werror -Wextra -g

#---------------------------------------------------#
#                COLORS DECLARATION                 #
#---------------------------------------------------#

RED			=	\033[31m
GRN			=	\033[32m
YLW			=	\033[33m
CRESET		=	\033[0m

#---------------------------------------------------#
#                 DIRECTORY PATHES                  #
#---------------------------------------------------#

SRC_DIR		=	src
GNL_DIR		=	Get_Next_Line
OBJ_GNL_DIR	=	build/gnl
OBJ_SRC_DIR	=	build/src
BIN_DIR		=	bin

#---------------------------------------------------#
#                     ALL FILES                     #
#---------------------------------------------------#

ARCHIVES	=	$(BIN_DIR)/libft.a

SRC			=	main.c parsing.c pipex.c parsing_utils.c free.c
GNL			=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS_SRC	=	$(patsubst %.c, $(OBJ_SRC_DIR)/%.o, $(SRC))
OBJS_GNL	=	$(patsubst %.c, $(OBJ_GNL_DIR)/%.o, $(GNL))

all: $(TARGET)

$(TARGET): $(OBJS_SRC) $(OBJS_GNL)
	@$(MAKE) -C libft/ --no-print-directory
	@$(CC) $(OBJS_SRC) $(OBJS_GNL) -o $@  $(ARCHIVES)
	@echo "-------------------------------------------------- \
 	$(GRN)\n\nInfo : Fichiers sources compilés !\n\n$(CRESET)\
	--------------------------------------------------\n"

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_SRC_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_GNL_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@find -type f -name "*.o" -delete
	@echo "-------------------------------------------------- \
 	$(GRN)\n\nInfo : Fichiers objets nettoyés !\n\n$(CRESET)\
	--------------------------------------------------\n"

fclean: clean
	@find -type f -name "*.a" -delete
	@echo "-------------------------------------------------- \
 	$(GRN)\n\nInfo : Binaires nettoyés !\n\n$(CRESET)\
	--------------------------------------------------\n"

re: fclean all

.PHONY: all clean fclean re

