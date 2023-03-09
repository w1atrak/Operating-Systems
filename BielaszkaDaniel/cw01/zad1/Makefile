LIB=lib1

all:
	make lib_static
	make lib_shared

lib_static: $(LIB).c
	gcc -Wall -c $(LIB).c
	ar cr $(LIB).a $(LIB).o

lib_shared: $(LIB).c
	gcc -Wall -fPIC -c $(LIB).c
	gcc -Wall -shared $(LIB).o -o lib$(LIB).so

clean:
	rm -f *.o *.a *.so