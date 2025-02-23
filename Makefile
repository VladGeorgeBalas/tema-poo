build:
	clang++ main.cpp cod.hpp cod.cpp angajat.cpp angajat.hpp produs.hpp produs.cpp comanda.hpp comanda.cpp

clean:
	rm -f out

run:
	./out
