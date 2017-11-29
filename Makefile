NAME = libftprintf.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra -Iincludes

SRC_PATH = src/

LIBFT_PATH = libft/

LIBFT_FILE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_islower.c ft_isupper.c \
		ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
		ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
		ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c \
		ft_lstadd.c ft_lstdel.c \
		ft_lstdelall.c ft_lstdelone.c \
		ft_lstfrontbacksplit.c ft_lstiter.c \
		ft_lstlen.c ft_lstmap.c \
		ft_lstnew.c ft_lstpushadd.c \
		ft_lstrev.c ft_lstrotate.c \
		ft_dtoa.c ft_intlen.c \
		ft_power.c ft_print_bits.c \
		ft_strndup.c ft_strrev.c \
		ft_strtrijoin.c ft_swap.c \
		ft_utoa.c ft_imtoa.c ft_strnrchr.c

LIBFT = $(LIBFT_FILE:%.c=$(LIBFT_PATH)%.c)

OBJ_PATH = obj/

SRC_FILE = printf.c \
						init.c \
						process.c \
						operateur.c \
						print_char.c \
						print_str.c \
						print_int.c \
						flags.c

SRC = $(SRC_FILE:%.c=$(SRC_PATH)%.c)

OBJ = $(LIBFT:$(LIBFT_PATH)%.c=$(OBJ_PATH)%.o) $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -Rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re, norme
