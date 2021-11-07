CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

RM = rm -f

NAME = libftprintf.a 

# LIBFT = libft.a

# LIBFTDIR = ./libft

SOURCES = ft_printf_bonus.c

SOURCES_BONUS = ft_printf_bonus.c

OBJS = $(patsubst %.c, %.o, ${SOURCES})

OBJS_BONUS = $(patsubst %.c, %.o, ${SOURCES_BONUS})

all:	 ${NAME}

%.o :	%.c ${HEADERS}
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} $?

bonus:	${OBJS_BONUS}
	ar rcs ${NAME} $?

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all
