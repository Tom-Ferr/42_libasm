SRC = ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s ft_strdup.s

OBJ = ${SRC:.s=.o}

AR = ar -crs

NAME = libasm.a

MAIN = main.cpp

OUT = run_test

CXX = g++

%.o:	%.s
		nasm -f elf64 $< -o $@

$(NAME):	${OBJ}
			${AR} ${NAME} ${OBJ}

all:		${NAME}

main:		all
			${CXX} ${MAIN} -L. -lasm -o ${OUT}

run:		main
			./${OUT}
clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME} ${OUT}

re:			fclean all

.PHONY:	all clean fclean re main run