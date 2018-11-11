mecanismo: mecanismo-de-busca.cpp mecanismo-de-busca.h
	g++ -o mecanismo mecanismo-de-busca.cpp -Wall -Wextra -pedantic -std=c++11 -lpthread
clean:
	rm mecanismo.o
 