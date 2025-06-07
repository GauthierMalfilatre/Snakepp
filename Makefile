SRC = 	main.cpp \
		Apple.cpp \
		SnakePart.cpp \
		Snake.cpp \

OBJ = $(SRC:.cpp=.o)
NAME ?= snake

CXX = g++
CXXFLAGS = 

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	find -name "*~" -delete -a -name "#*#" -delete
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
