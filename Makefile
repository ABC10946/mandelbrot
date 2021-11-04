CC = g++
CFLAGS = -Wall -std=c++14
PROGRAM = mandelbrot
SRCS = main.cpp complex.cpp mandelbrot.cpp gui.cpp
LIBS = -lglut -lGLU -lGL

all: $(PROGRAM)

$(PROGRAM): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRCS) $(LIBS)

clean:
	rm -f $(PROGRAM)
