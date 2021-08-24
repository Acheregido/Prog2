# Autor: Acher Egido Mairal
# Makefile del trabajo práctico de Programación 2 de Primero de Ingeniería informática

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # para limpiar
CC = g++         # para compilar
#---------------------------------------------------------
# opciones de compilación
CPPFLAGS=-I. -std=c++11 -fmax-errors=1 # opciones compilación
#---------------------------------------------------------
main: main.o cuentaInv.o
	$(CC) main.o cuentaInv.o -o main $(CPPFLAGS)
#---------------------------------------------------------
main.o: main.cpp
	$(CC) main.cpp -c $(CPPFLAGS)
#---------------------------------------------------------
cuentaInv.o: cuentaInv.cpp cuentaInv.hpp
	$(CC) cuentaInv.cpp -c $(CPPFLAGS)
#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) main cuentaInv.o
	$(RM) main main.o