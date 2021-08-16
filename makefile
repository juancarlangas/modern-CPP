# Bueno, vamos a practicar de nueva cuenta el makefile alv

CC = g++
CXXFLAGS = -std=c++20 -g
OBJS =	obj/main.o \
		obj/001-flujos-1.o \
		obj/002-flujos-2.o \
		obj/003-namespaces.o \
		obj/004-funciones-1.o \
		obj/005-funciones-2.o \
		obj/006-define.o \
		obj/007-condicionales.o \
		obj/008-string_view.o \
		obj/misFuncionesMatematicas.o \
		obj/utilities.o

course: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o bin/course

obj/main.o: src/main.cpp include/temas.hpp
	$(CC) -c $(CXXFLAGS) src/main.cpp -o obj/main.o

obj/001-flujos-1.o: src/001-flujos-1.cpp \
					txt/mario-utf8.txt \
					txt/u8_mario-utf8.txt \

	$(CC) -c $(CXXFLAGS) src/001-flujos-1.cpp -o obj/001-flujos-1.o
		
obj/002-flujos-2.o: src/002-flujos-2.cpp
	$(CC) -c $(CXXFLAGS) src/002-flujos-2.cpp -o obj/002-flujos-2.o
		
obj/003-namespaces.o: src/003-namespaces.cpp
	$(CC) -c $(CXXFLAGS) src/003-namespaces.cpp -o obj/003-namespaces.o
		
obj/004-funciones-1.o: src/004-funciones-1.cpp
	$(CC) -c $(CXXFLAGS) src/004-funciones-1.cpp -o obj/004-funciones-1.o
		
obj/005-funciones-2.o: src/005-funciones-2.cpp
	$(CC) -c $(CXXFLAGS) src/005-funciones-2.cpp -o obj/005-funciones-2.o
		
obj/006-define.o: src/006-define.cpp
	$(CC) -c $(CXXFLAGS) src/006-define.cpp -o obj/006-define.o
		
obj/007-condicionales.o: src/007-condicionales.cpp src/utilities.hpp
	$(CC) -c $(CXXFLAGS) src/007-condicionales.cpp -o obj/007-condicionales.o
		
obj/008-string_view.o: src/008-string_view.cpp
	$(CC) -c $(CXXFLAGS) src/008-string_view.cpp -o obj/008-string_view.o
		

obj/misFuncionesMatematicas.o : src/misFuncionesMatematicas.cpp
	$(CC) -c $(CXXFLAGS) src/misFuncionesMatematicas.cpp -o obj/misFuncionesMatematicas.o

obj/utilities.o : src/utilities.cpp
	$(CC) -c $(CXXFLAGS) src/utilities.cpp -o obj/utilities.o

.PHONY: clean

clean:
	rm $(OBJS)
