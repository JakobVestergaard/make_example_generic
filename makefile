SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

CXXFLAGS =    -g  -std=c++11 -Wall

TARGET =    readfromfile

$(TARGET):    $(OBJ)
	$(CXX) -o $@ $^

.PHONY: all
all:    $(TARGET)

.PHONY: clean
clean:
	rm -f *.o $(TARGET)

