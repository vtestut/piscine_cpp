NAME		= megaphone
PATH_OBJS	= objs
CXX			= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRC			= megaphone.cpp
OBJS		= ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRC}} # Utilisez SRC, pas SRCS

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp
	mkdir -p ${PATH_OBJS}
	${CXX} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${FLAGS} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}