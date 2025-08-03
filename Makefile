NAME = tamagotchi_ncurses

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = src/main.cpp src/Tamagotchi.cpp
OBJ = $(SRC:.cpp=.o)
INC = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -lncurses -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all