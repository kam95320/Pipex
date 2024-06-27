# ------------  COLORS  ----------------------------------------------------- #
RED				=	\033[0;31m
GREEN			=	\033[0;32m
YELLOW			=	\033[0;33m
DEFAULT			=	\033[0m

# ------------  PROJECT  ----------------------------------------------------- #
NAME			=	pipex

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR			=	src/
B_SRC_DIR		=	src_bonus/
OBJ_DIR			=	objs/
B_OBJ_DIR		=	objs_bonus/
LFT_DIR			=	src/libft/

# ------------  SOURCES  ----------------------------------------------------- #
LFT				=	src/libft/libft.a

SRC_FLS			=	clear.c \
					error.c \
					get_cmds.c \
					get_files.c \
					init_data.c \
					pipex.c \
					process.c \

B_SRC_FLS		=	clear_bonus.c \
					error_bonus.c \
					get_cmds_bonus.c \
					get_files_bonus.c \
					heredoc_bonus.c \
					init_data_bonus.c \
					pipex_bonus.c \
					process_bonus.c \

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FLS))
OBJS			=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))

B_SRCS			=	$(addprefix $(B_SRC_DIR), $(B_SRC_FLS))
B_OBJS			=	$(patsubst $(B_SRC_DIR)%.c,$(B_OBJ_DIR)%.o, $(B_SRCS))

# ------------  FLAGS  -------------------------------------------------------- #
LFLAGS			=	-L./$(LFT_DIR) -lft
CFLAGS			=	-Wall -Wextra -Werror -g

MAKE_FLAGS		=	-s -C
RM_FLAGS		=	-rf

INCLUDES		=	-I/$(SRC_DIR)
B_INCLUDES		=	-I/$(B_SRC_DIR)

# ------------  COMMANDS  ------------------------------------------------------- #
CC				=	cc
MK				=	make all
MFC				=	make fclean
MC				=	make clean
RM				=	rm $(RM_FLAGS)

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(NAME):			$(OBJS) $(LFT)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(OBJS) $(LFLAGS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(OBJ_DIR)%.o: 		$(SRC_DIR)%.c | $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)

bonus:				$(B_OBJS) $(LFT)
					@$(CC) $(CFLAGS) -o ./$(NAME) $(B_OBJS) $(LFLAGS)
					@echo "$(GREEN)Compiled $(NAME)$(DEFAULT)"

$(B_OBJ_DIR)%.o: 	$(B_SRC_DIR)%.c | $(B_OBJ_DIR)
					@$(CC) $(CFLAGS) $(B_INCLUDES) -c $< -o $@

$(B_OBJ_DIR):
					@mkdir -p $(B_OBJ_DIR)

$(LFT):
					@$(MK) $(MAKE_FLAGS) $(LFT_DIR)

clean:	
					@$(RM) $(OBJ_DIR) $(B_OBJ_DIR)
					@$(MFC) $(MAKE_FLAGS) $(LFT_DIR)

fclean:				clean 
					@$(RM) $(NAME)

re:					fclean all

.PHONY: 			all clean fclean re