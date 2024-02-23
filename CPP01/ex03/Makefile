NAME	= a.Violence

OBJDIR	= objs

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HEADERS	= Weapon.hpp HumanA.hpp HumanB.hpp

OBJS	= ${patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${OBJDIR}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${OBJDIR}
	${CPP} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CPP} ${OBJS} -o $@

clean:
	rm -rf ${OBJDIR}		

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re