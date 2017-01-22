CC=g++
CXXFLAGS=-g -Wall -std=c++0x

SRCS= classes.h init.h output.h moves.h check_pos.h check_pos.cpp moves.cpp init_standard.cpp output.cpp main.cpp
OBJS= $(SRCS:.cpp=.o)
TARGET=main

all:$(TARGET)

$(TARGET): $(OBJS) 
		$(CC) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	$(RM) *.o $(TARGET)


.c.o: $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
