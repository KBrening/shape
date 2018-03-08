CFLAGS = -I ./include
LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr

all: walk2

walk2: walk2.cpp log.cpp jordanP.cpp miguelN.cpp keelanB.cpp randiA.cpp time.h
	g++ $(CFLAGS) walk2.cpp log.cpp jordanP.cpp miguelN.cpp keelanB.cpp randiA.cpp libggfonts.a time.h -Wall -Wextra $(LFLAGS) -o walk2

clean:
	rm -f walk2
	rm -f *.o

