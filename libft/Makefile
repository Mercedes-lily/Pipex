NAME = libft.a

SRC = ft_isalpha.c \
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
	ft_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_strtrim.c \

OBJS = $(SRC:%.c=%.o)  


SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstlast.c \
			ft_lstclear.c \
			ft_lstiter.c 

OBJS_BONUS = $(SRC_BONUS:%.c=%.o)


CC = gcc
RM = rm -f
CFLAGS = -Wextra -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)     
	ar rcs $@ $^     

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BONUS)

$(OBJS_BONUS) : 
	$(CC) $(CFLAGS) -c $(SRC_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: clean fclean re bonus
