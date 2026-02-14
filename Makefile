build: clean
	g++ -g main.cpp -o percpptron

run: build
	./percpptron

clean:
	rm -f ./percpptron

all: clean build run
