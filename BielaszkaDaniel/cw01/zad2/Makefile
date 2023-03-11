
LIB=lib1



all:
	make lib_static
	make lib_shared
	make program_static
	make program_shared
	make program_dynamic





lib_static: $(LIB).c dynamic.h
	gcc -Wall  -c $(LIB).c
	ar cr $(LIB).a $(LIB).o

lib_shared: $(LIB).c
	gcc -Wall  -c -fPIC $(LIB).c
	gcc -Wall -shared -o $(LIB).so $(LIB).o

program_static: $(LIB).c
	gcc -Wall main.c -o main_static.exe -L . $(LIB).a

program_shared: $(LIB).c
	gcc -Wall main.c -Wl,-rpath=. -o main_shared.exe -L . $(LIB).so

program_dynamic: $(LIB).c
	gcc -Wall main.c -Wl,-rpath=. -o main_dynamic.exe -ldl -D DYNAMIC_LIB


clean: 
	rm -f *.o *.a *.so *.exe

