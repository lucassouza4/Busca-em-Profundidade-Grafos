all: principal.o DFS.o
	g++ -o programa principal.o DFS.o

run:
	.\programa.exe

principal.o: principal.cpp
	g++ principal.cpp -c
 
DFS.o: DFS.cpp
	g++ DFS.cpp -c