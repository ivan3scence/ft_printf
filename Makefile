CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

RM = rm -f

NAME = libftprintf.a 

# LIBFT = libft.a

# LIBFTDIR = ./libft

SOURCES = ft_printf1.c

OBJS = $(patsubst %.c, %.o, ${SOURCES})

all:	 ${NAME}

%.o :	%.c ${HEADERS}
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} $?

clean:
	${RM} -f ${OBJS}

fclean:		clean
	${RM} -f ${NAME}

re:	fclean all
