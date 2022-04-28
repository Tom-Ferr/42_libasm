SRC = ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s ft_strdup.s 

OBJ = ${SRC:.s=.o}

BONUS_FILES = ft_atoi_base.s ft_create_elem.s ft_list_push_front.s ft_list_size.s ft_list_remove_if.s ft_list_sort.s

BONUS_DIR = bonus/

BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))

OBJ_BONUS = ${BONUS:.s=.o}

AR = ar -crs

FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address

NAME = libasm.a

MAIN = main.c

OUT = run_test

CXX = clang

%.o:	%.s
		nasm -f elf64 $< -o $@

$(NAME):	${OBJ}
			${AR} ${NAME} ${OBJ}

all:		${NAME}

main:		all
			${CXX} ${FLAGS} ${SANITIZE} ${MAIN}  -L. -lasm -o ${OUT}

run:		main
			./${OUT}
clean:
			rm -f ${OBJ} ${OBJ_BONUS} testing.txt

fclean:		clean
			rm -f ${NAME} ${OUT}*

bonus:		${OBJ} ${OBJ_BONUS}
			${AR} ${NAME} ${OBJ} ${OBJ_BONUS}
			${CXX} ${FLAGS} ${SANITIZE} bonus/main_bonus.c -L. -lasm -o ${OUT}_bonus
			./${OUT}_bonus

re:			fclean all

.PHONY:	all clean fclean re main run bonus