executable_server = server

all: Server

Server: main.cpp Map.h Employee.h Library.h
	g++ -g -Wall -pedantic main.cpp -o $(executable_server)

.PHONY: clean
clean:
	rm $(executable_server)