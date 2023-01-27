compiler        = g++
files       = enigma2.cpp enigma.cpp encrypt.cpp main.cpp

all: compile

compile: $(files)
	$(compiler) $(files) 

clean:
	rm -f a.out

exe:
	./a.out

