NAME := phonebook
PATH_OBJS := objs
CPP := c++ -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp phonebook.cpp
HEADERS := contact.hpp phonebook.hpp
OBJS := ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${PATH_OBJS}
	${CPP} -c $< -o $@

${NAME}: ${OBJS}
	${CPP} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
