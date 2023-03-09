
FLAGSS=-Wall
LIB=lib1



all:
	make lib_static
	make lib_shared
	make program_static
	make program_shared
	make program_dynamic


o:
	make all COMPILEFLAG="-O"
o0:
	make all COMPILEFLAG="-O0"
o1:
	make all COMPILEFLAG="-O1"
o2:
	make all COMPILEFLAG="-O2"
o3:
	make all COMPILEFLAG="-O3"
os:
	make all COMPILEFLAG="-Os"


lib_static: $(LIB).c dynamic.h
	gcc -Wall $(COMPILEFLAG) -c $(LIB).c
	ar cr $(LIB).a $(LIB).o

lib_shared: $(LIB).c
	gcc -Wall $(COMPILEFLAG) -c -fPIC $(LIB).c
	gcc -Wall $(COMPILEFLAG) -shared -o $(LIB).so $(LIB).o

program_static: $(LIB).c
	gcc -Wall $(COMPILEFLAG) main.c -o main_static.exe -L . $(LIB).a

program_shared: $(LIB).c
	gcc -Wall $(COMPILEFLAG) main.c -o main_shared.exe -L . $(LIB).so

program_dynamic: $(LIB).c
	gcc -Wall $(COMPILEFLAG) main.c -o main_dynamic.exe -ldl -D DYNAMIC_LIB


clean: 
	rm -f *.o *.a *.so *.exe

