all:
	g++ src/main.cpp ./classes/func/*.cpp -o exec; mv exec build; build/exec