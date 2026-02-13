build: clean
	g++ main.cpp -o perccptron

run: build
	./perccptron

clean:
	rm -f ./perccptron

all: clean build run
