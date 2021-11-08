CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

RM = rm -f

NAME = libftprintf.a 

LIBRARY = libft.a

LIBDIR = ./libft

LIB = $(addprefix ${LIBDIR}/, ${LIBRARY})

SRC = ft_printf_c.c ft_printf_i.c ft_printf_u.c\
		ft_printf_x.c ft_printf_p.c ft_printf_utils.c\
		ft_printf_lis.c ft_printf_s.c

SRCWD = $(addprefix src/, ${SRC})

SOURCES = ft_printf_bonus.c ${SRCWD}

SOURCES_BONUS = ft_printf_bonus.c ${SRCWD}

OBJS = $(patsubst %.c, %.o, ${SOURCES})

OBJS_BONUS = $(patsubst %.c, %.o, ${SOURCES_BONUS})

.PHONY:	clean all bonus fclean re

all:	 ${LIB} ${NAME}

%.o :	%.c ${HEADERS}
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rcs ${NAME} $?

${LIB}:
	${MAKE} -C ${LIBDIR}

bonus:	${OBJS_BONUS}
	ar rcs ${NAME} $?

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${LIBDIR}

fclean:		clean
	${RM} ${NAME}
	${RM} ${LIB}

re:	fclean all
