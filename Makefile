all: out

out: main.cpp cod.hpp cod.cpp angajat.cpp angajat.hpp produs.hpp produs.cpp comanda.hpp comanda.cpp
	clang++ -o out main.cpp cod.cpp angajat.cpp produs.cpp comanda.cpp -std=c++17 -o 'test.exe'

clean:
	del test.exe

run: out
	./test.exe
