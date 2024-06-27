# ------------  PROJECT  ----------------------------------------------------- #
NAME		=	libft.a

# ------------  DIRECTORIES  ------------------------------------------------- #
OBJ_DIR			=	objs/
LIBFT_DIR		=	libft_src/
PF_DIR			=	ft_printf/
GNL_DIR			=	get_next_line/

# ------------  HEADERS  ----------------------------------------------------- #
L_HEADER		=	$(LIBFT_DIR)libft.h
GNL_HEADER		=	$(GNL_DIR)get_next_line.h
PF_HEADER		=	$(PF_DIR)ft_printf.h

# ------------  SOURCES  ----------------------------------------------------- #
LIBFT_SRC		=	$(LIBFT_DIR)ft_count_chars.c $(LIBFT_DIR)clear_tab.c $(LIBFT_DIR)is_in_charset.c $(LIBFT_DIR)ft_atoi.c $(LIBFT_DIR)ft_bzero.c $(LIBFT_DIR)ft_calloc.c $(LIBFT_DIR)ft_isalnum.c $(LIBFT_DIR)ft_isalpha.c $(LIBFT_DIR)ft_isascii.c $(LIBFT_DIR)ft_isdigit.c $(LIBFT_DIR)ft_isprint.c $(LIBFT_DIR)ft_itoa.c $(LIBFT_DIR)ft_memchr.c $(LIBFT_DIR)ft_memcmp.c $(LIBFT_DIR)ft_memcpy.c $(LIBFT_DIR)ft_memmove.c $(LIBFT_DIR)ft_memset.c $(LIBFT_DIR)ft_putchar_fd.c $(LIBFT_DIR)ft_putendl_fd.c $(LIBFT_DIR)ft_putnbr_fd.c $(LIBFT_DIR)ft_putstr_fd.c $(LIBFT_DIR)ft_split.c $(LIBFT_DIR)ft_strchr.c $(LIBFT_DIR)ft_strdup.c $(LIBFT_DIR)ft_striteri.c $(LIBFT_DIR)ft_strjoin.c $(LIBFT_DIR)ft_strlcat.c $(LIBFT_DIR)ft_strlcpy.c $(LIBFT_DIR)ft_strlen.c $(LIBFT_DIR)ft_strmapi.c $(LIBFT_DIR)ft_strncmp.c $(LIBFT_DIR)ft_strnstr.c $(LIBFT_DIR)ft_strrchr.c $(LIBFT_DIR)ft_strtrim.c $(LIBFT_DIR)ft_substr.c $(LIBFT_DIR)ft_tolower.c $(LIBFT_DIR)ft_toupper.c $(LIBFT_DIR)ft_lstadd_back.c $(LIBFT_DIR)ft_lstadd_front.c $(LIBFT_DIR)ft_lstclear.c $(LIBFT_DIR)ft_lstdelone.c $(LIBFT_DIR)ft_lstiter.c $(LIBFT_DIR)ft_lstlast.c $(LIBFT_DIR)ft_lstmap.c $(LIBFT_DIR)ft_lstnew.c $(LIBFT_DIR)ft_lstsize.c
PF_SRC			=	$(PF_DIR)ft_printf.c $(PF_DIR)ft_printf_utils.c $(PF_DIR)get_address.c $(PF_DIR)get_hex.c $(PF_DIR)get_unsigned.c
GNL_SRC			=	$(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

# ------------  OBJECTS  ----------------------------------------------------- #
OBJS			=	$(patsubst $(LIBFT_DIR)%.c,$(OBJ_DIR)%.o, $(LIBFT_SRC))
PF_OBJS			=	$(patsubst $(PF_DIR)%.c,$(OBJ_DIR)$(PF_DIR)%.o, $(PF_SRC))
GNL_OBJS		=	$(patsubst $(GNL_DIR)%.c,$(OBJ_DIR)$(GNL_DIR)%.o, $(GNL_SRC))

# ------------  MISC  -------------------------------------------------------- #
CC				=	cc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror

# ------------  RULES  ------------------------------------------------------- #
all:				${NAME}

$(OBJ_DIR)%.o:				$(LIBFT_DIR)%.c $(L_HEADER) | $(OBJ_DIR)
							@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)$(GNL_DIR)%.o:	$(GNL_DIR)%.c $(GNL_HEADER) $(L_HEADER) | $(OBJ_DIR)$(GNL_DIR)
							@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)$(PF_DIR)%.o:		$(PF_DIR)%.c $(PF_HEADER) $(L_HEADER) | $(OBJ_DIR)$(PF_DIR)
							@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(PF_DIR)
					@mkdir -p $(OBJ_DIR)$(GNL_DIR)

$(NAME):			$(OBJS) $(PF_OBJS) $(GNL_OBJS)
					@ar -rsc $(NAME) $(OBJS) $(PF_OBJS) $(GNL_OBJS)

clean:	
					@$(RM) $(OBJ_DIR)

fclean:				clean 
					@$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
