NAME	= a.out

OBJDIR	= objs

CPP		= c++

FLAGS	= -Wall -Wextra -Werror -std=c++17

SRCS	= NewClass.cpp main.cpp

HEADERS = NewClass.hpp

OBJS = ${patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${OBJDIR}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${OBJDIR}
	${CPP} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CPP} ${OBJS} -o $@

clean:
	@rm -rf ${OBJDIR}		

fclean: clean
	@rm -f ${NAME}
	@rm -rf output

re: fclean ${NAME}

.PHONY: all clean fclean re
