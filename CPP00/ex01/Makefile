# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:41:04 by vtestut           #+#    #+#              #
#    Updated: 2023/12/19 20:14:59 by vtestut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME := phonebook

# INCLUDES := Contact.hpp
# INCLUDES += PhoneBook.hpp

# SRCS := Contact.cpp
# SRCS += PhoneBook.cpp
# SRCS += main.cpp

# OBJS := $(SRCS:.cpp=.o)

# CC := c++

# CFLAGS := -Wall
# CFLAGS += -Wextra
# CFLAGS += -Werror
# CFLAGS += -std=c++98

# RM := rm -f

# %.o: %.cpp
# 	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(OBJS:.o=.cpp)

# all: $(NAME)

# clean:
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: re fclean clean all

NAME := phonebook
PATH_OBJS := objs
CXX := c++ -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp PhoneBook.cpp Contact.cpp
HEADERS := Contact.hpp PhoneBook.hpp
OBJS := ${patsubst %.cpp, ${PATH_OBJS}/%.o, ${SRCS}}

all: ${NAME}

${OBJS}: ${PATH_OBJS}/%.o: %.cpp ${HEADERS}
	@mkdir -p ${PATH_OBJS}
	${CXX} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${OBJS} -o $@

clean:
	rm -rf ${PATH_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re