

LIB=lib1



all:
	make lib_static
	make lib_shared
	make program_static
	make program_shared
	make program_dynamic




lib_static: $(LIB).c dynamic.h
	gcc -Wall -c $(LIB).c
	ar cr $(LIB).a $(LIB).o

lib_shared: $(LIB).c
	gcc -Wall -c -fPIC $(LIB).c
	gcc -Wall -shared -o $(LIB).so $(LIB).o


program_static: $(LIB).c
	gcc -Wall main.c -o main_static.exe -L . $(LIB).a

program_shared: $(LIB).c
	gcc -Wall main.c -Wl,-rpath=. -o main_shared.exe -L . $(LIB).so

program_dynamic: $(LIB).c
	gcc -Wall main.c -Wl,-rpath=. -o main_dynamic.exe -ldl -D DYNAMIC_LIB


test:
	make all
	./main_static.exe < commands.txt > results_static.txt
	./main_shared.exe < commands.txt > results_shared.txt
	# ./main_dynamic.exe < commands.txt > results_dynamic.txt 2> /dev/null

	touch report.txt
	echo "static >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static.txt >> report.txt

	echo "shared >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared.txt >> report.txt
	
	echo "dynamic >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	#cat results_dynamic.txt >> report.txt

clean: 
	rm -f *.o *.a *.so *.exe results*.txt report.txt

