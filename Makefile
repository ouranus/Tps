# Compile/Link
GCC = gcc
OPTMIZE = -g -O2
LIBS = -lc

#Objetos
OBJS =  main.c
# Nome do aplicativo
APPNAME = Tp1

release : ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean : rm -rf *.o

run :
				make
				./Tp1