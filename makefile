guerra:	main.o soldado.o escuadron.o arquero.o knight.o asesino.o 
	g++ main.o soldado.o escuadron.o arquero.o knight.o asesino.o -o guerra

asesino.o:	asesino.cpp asesino.h soldado.h
	g++ -c asesino.cpp

knight.o:	knight.cpp knight.h soldado.h
	g++ -c knight.cpp

arquero.o:	arquero.cpp arquero.h soldado.h
	g++ -c arquero.cpp

escuadron.o:	escuadron.cpp escuadron.h soldado.h
	g++ -c escuadron.cpp

soldado.o:	soldado.cpp soldado.h
	g++ -c soldado.cpp

main.o:	main.cpp soldado.h escuadron.h arquero.h knight.h asesino.h
	g++ -c main.cpp	
