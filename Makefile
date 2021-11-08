CFLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

CC = cc

RM = rm -f

NAME = libftprintf.a 

SRC = ft_printf_c_bonus.c ft_printf_i_bonus.c ft_printf_u_bonus.c\
		ft_printf_x_bonus.c ft_printf_p_bonus.c ft_printf_utils_bonus.c\
		ft_printf_lis_bonus.c ft_printf_s_bonus.c ft_printf_utils2_bonus.c\
		ft_printf_utils3_bonus.c

SRCWD = $(addprefix src/, ${SRC})

SOURCES = ft_printf_bonus.c ${SRCWD}

SOURCES_BONUS = ft_printf_bonus.c ${SRCWD}

OBJS = $(patsubst %.c, %.o, ${SOURCES})

OBJS_BONUS = $(patsubst %.c, %.o, ${SOURCES_BONUS})

.PHONY:	clean all bonus fclean re

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
