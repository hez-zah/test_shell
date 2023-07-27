NC         = \033[0m
GREEN      = \033[1;32m
RED        = \033[1;31m

NAME	= libft.a

SRCS	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
 			ft_isprint.c ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c \
 			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
			ft_substr.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_strrev.c ft_lstadd_back.c ft_lstadd_front.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
			ft_lstnew.c ft_lstsize.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

HEADER	= ../headers/libft.h

CFLAGS	= -Wall -Werror -Wextra

LIB		= ar -rc



all:		${NAME}

%.o:	%.c ${HEADER}
				@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
				@${LIB} $@ $^
				@echo "${GREEN} ##### libft.a Ready! ##### ${NC}"

clean:
				@${RM} ${OBJS}
				@echo "${GREEN} ##### Libft Cleans Objects ##### ${NC}"

fclean:		clean
				@${RM} ${NAME}
				@echo "${GREEN} ##### libft.a Removed ##### ${NC}"

re:			fclean all

.PHONY: all clean fclean re
