TARGET = megaphone

CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean $(TARGET)

.PHONY: clean re