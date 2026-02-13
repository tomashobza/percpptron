build: clean
	g++ main.cpp -o perccptron

run:
	./perccptron

clean:
	rm ./perccptron

all: clean build run
