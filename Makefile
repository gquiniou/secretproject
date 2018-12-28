CXX=g++

LDFLAGS=  -lsfml-system -lsfml-window -lsfml-graphics

CXXFLAGS= -g -Wall -Wextra -std=c++0x -I./include


OBJS=main.o Application.o
NAME=secret


all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	rm $(NAME) $(OBJS)
