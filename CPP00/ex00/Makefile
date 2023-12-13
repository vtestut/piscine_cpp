TARGET = megaphone

COMPILO = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(COMPILO) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(COMPILO) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean $(TARGET)

.PHONY: clean re