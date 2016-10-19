
CC=clang++-mp-3.9
LDFLAGS=-llua
STD=-std=c++11

all: dumper hello

dumper:
	$(CC) $(LDFLAGS) $(STD) $(CUSTFLAGS) -shared dumper.cpp -o dumper.so 

hello:
	$(CC) $(LDFLAGS) $(STD) $(CUSTFLAGS) hello.cpp -o hello

clean:
	rm -f dumper.so hello
