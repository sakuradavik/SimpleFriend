all: output

output: StudentMain.o Person.o
	g++ StudentMain.o Person.o -o output

StudentMain.o: StudentMain.cpp
	g++ -c StudentMain.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm -rf *o output