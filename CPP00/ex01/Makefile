# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 19:41:04 by vtestut           #+#    #+#              #
#    Updated: 2023/12/19 19:41:17 by vtestut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := my_awesome_phonebook

INCLUDES := -I $(CURDIR)

SRCS := Contact.cpp
SRCS += PhoneBook.cpp
SRCS += main.cpp

OBJS := $(SRCS:.cpp=.o)

CC := c++

CFLAGS := -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -std=c++98

RM := rm -f

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all