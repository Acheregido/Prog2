#------------------------------------------------------------------------------
# File:   Makefile
# Author: Programación II-Unizar
# Date:   febrero 2021
# Coms:   Ejemplo de Makefile para la práctica 1 de Programación II
#         "make all" compila y generará los tres ejecutables
#         "make tiempoReaccion" compila y genera "tiempoReaccion"
#         ...
#         "make clean" borra todo lo generado, si existe (ver línea 40-50)
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++
CPPFLAGS = -I. -std=c++11      #opciones de compilación
LDFLAGS =                      #opciones de linkado
RM = rm -f                     #comando para borrar ficheros

all: listarArgumentos medirCoste tiempoReaccion
#-----------------------------------------------------------
# Compilacion
tiempoReaccion.o: tiempoReaccion.cpp
	${CC} -c tiempoReaccion.cpp ${CPPFLAGS}
#linkado
tiempoReaccion: tiempoReaccion.o
	${CC} tiempoReaccion.o -o tiempoReaccion ${LDFLAGS}
#-----------------------------------------------------------
# Compilacion
medirCoste.o: medirCoste.cpp
	${CC} -c medirCoste.cpp ${CPPFLAGS}
#linkado
medirCoste: medirCoste.o ordenar.o
	${CC} medirCoste.o ordenar.o -o medirCoste ${LDFLAGS}

ordenar.o: ordenar.cpp ordenar.hpp
	${CC} -c ordenar.cpp ${CPPFLAGS}
#-----------------------------------------------------------
# Compilacion
listarArgumentos.o: listarArgumentos.cpp
	${CC} -c listarArgumentos.cpp ${CPPFLAGS}
#linkado
listarArgumentos: listarArgumentos.o
	${CC} listarArgumentos.o -o listarArgumentos
#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. Ojo: se borrarán sin preguntar
clean:
	${RM} tiempoReaccion.o tiempoReaccion
	${RM} medirCoste.o medirCoste
	${RM} listarArgumentos.o listarArgumentos
