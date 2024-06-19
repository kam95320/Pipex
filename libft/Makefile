

# NAME = libft.a
# CC = cc 
# FLAGS = -Wall -Werror -Wextra

# # Sources de la libft
# SRCS = ft_isalpha.c \
#        ft_isdigit.c \
#        ft_isalnum.c \
#        ft_isascii.c \
#        ft_isprint.c \
#        ft_strlen.c \
#        ft_memset.c \
#        ft_bzero.c \
#        ft_memcpy.c \
#        ft_memmove.c \
#        ft_strlcpy.c \
#        ft_strlcat.c \
#        ft_toupper.c \
#        ft_tolower.c \
#        ft_strchr.c \
#        ft_strrchr.c \
#        ft_strncmp.c \
#        ft_memchr.c \
#        ft_memcmp.c \
#        ft_strnstr.c \
#        ft_atoi.c \
#        ft_calloc.c \
#        ft_strdup.c \
#        ft_substr.c \
#        ft_strjoin.c \
#        ft_strtrim.c \
#        ft_split.c \
#        ft_itoa.c \
#        ft_strmapi.c \
#        ft_striteri.c \
#        ft_putchar_fd.c \
#        ft_putstr_fd.c \
#        ft_putendl_fd.c \
#        ft_putnbr_fd.c \
#        ft_lstadd_back.c \
#        ft_lstadd_front.c \
#        ft_lstclear.c \
#        ft_lstdelone.c \
#        ft_lstiter.c \
#        ft_lstnew.c \
#        ft_lstlast.c \
#        ft_lstsize.c \
#        ft_printf/libftprintf.a \
#        get_next_line/get_next_line.c \
#        get_next_line/get_next_line_utils.c

# OBJS = $(SRCS:.c=.o)

# # Compilation des fichiers .o à partir des fichiers .c
# %.o : %.c
#         $(CC) $(FLAGS) -c $< -o $@

# # Création de la bibliothèque
# $(NAME) :
#         MAKE ALL -C ft_printf
#         ar rcs $(NAME) $(OBJS)

# all : $(NAME)

# clean :
# 	rm -f $(OBJS)

# fclean : clean
# 	rm -f $(NAME)
# 	rm -f a.out

# re : fclean all

# .PHONY: all clean fclean re




# NAME = libft.a
# CC = cc 
# FLAGS = -Wall -Werror -Wextra
# GNL = get_next_line/
# PRINTF = ft_printf/

# # Sources de la libft
# SRCS = ft_isalpha.c \
#        ft_isdigit.c \
#        ft_isalnum.c \
#        ft_isascii.c \
#        ft_isprint.c \
#        ft_strlen.c \
#        ft_memset.c \
#        ft_bzero.c \
#        ft_memcpy.c \
#        ft_memmove.c \
#        ft_strlcpy.c \
#        ft_strlcat.c \
#        ft_toupper.c \
#        ft_tolower.c \
#        ft_strchr.c \
#        ft_strrchr.c \
#        ft_strncmp.c \
#        ft_memchr.c \
#        ft_memcmp.c \
#        ft_strnstr.c \
#        ft_atoi.c \
#        ft_calloc.c \
#        ft_strdup.c \
#        ft_substr.c \
#        ft_strjoin.c \
#        ft_strtrim.c \
#        ft_split.c \
#        ft_itoa.c \
#        ft_strmapi.c \
#        ft_striteri.c \
#        ft_putchar_fd.c \
#        ft_putstr_fd.c \
#        ft_putendl_fd.c \
#        ft_putnbr_fd.c \
#        ft_lstadd_back.c \
#        ft_lstadd_front.c \
#        ft_lstclear.c \
#        ft_lstdelone.c \
#        ft_lstiter.c \
#        ft_lstnew.c \
#        ft_lstlast.c \
#        ft_lstsize.c \
#        get_next_line/get_next_line_utils.c\
#        $(GNL)get_next_line.c\
#        ft_printf/ft_hexadecimal.c\
#        ft_printf/ft_pourcentage.c\
#        ft_printf/ft_print_pointeur.c\
#        ft_printf/ft_print_putnbr.c\
#        ft_printf/ft_print_putstr.c\
#        ft_printf/ft_print_unsigned.c\
#        ft_printf/ft_printf.c\

# OBJS = $(SRCS:.c=.o)

# # Compilation des fichiers .o à partir des fichiers .c
# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@


# # Création de la bibliothèque principale
# $(NAME): $(OBJS) 
# 	ar rcs $(NAME) $(OBJS)

# all: $(NAME)

# clean:
# 	rm -f $(OBJS)
# 	$(MAKE) -C ft_printf clean

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f libftprintf.a
# 	$(MAKE) -C ft_printf fclean

# re: fclean all

# .PHONY: all clean fclean re



NAME = libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra -fPIE
GNL = get_next_line/
PRINTF = ft_printf/

# Sources de la libft
SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_strlen.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strncmp.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_atoi.c \
       ft_calloc.c \
       ft_strdup.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_itoa.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_lstadd_back.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstiter.c \
       ft_lstnew.c \
       ft_lstlast.c \
       ft_lstsize.c \
       ft_strcmp.c\
       $(GNL)get_next_line.c \
       $(GNL)get_next_line_utils.c \
       ft_printf/ft_hexadecimal.c \
       ft_printf/ft_pourcentage.c \
       ft_printf/ft_print_pointeur.c \
       ft_printf/ft_print_putnbr.c \
       ft_printf/ft_print_putstr.c \
       ft_printf/ft_print_unsigned.c \
       ft_printf/ft_putchar_lenght.c\
       ft_printf/ft_printf.c

OBJS = $(SRCS:.c=.o)

# Compilation des fichiers .o à partir des fichiers .c
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Création de la bibliothèque principale
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
