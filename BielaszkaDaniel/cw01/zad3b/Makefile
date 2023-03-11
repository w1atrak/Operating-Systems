

LIB=lib1
DEPEND=main.c dynamic.h dynamicLib.h


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


lib_static: $(LIB).c $(DEPEND)
	gcc -Wall $(COMPILEFLAG) -c $(LIB).c
	ar cr $(LIB).a $(LIB).o

lib_shared: $(LIB).c $(DEPEND)
	gcc -Wall $(COMPILEFLAG) -c -fPIC $(LIB).c
	gcc -Wall $(COMPILEFLAG) -shared -o $(LIB).so $(LIB).o

program_static: $(LIB).c $(DEPEND)
	gcc -Wall $(COMPILEFLAG) main.c -o main_static.exe -L . $(LIB).a

program_shared: $(LIB).c $(DEPEND)
	gcc -Wall $(COMPILEFLAG) main.c -Wl,-rpath=. -o main_shared.exe -L . $(LIB).so

program_dynamic: $(LIB).c $(DEPEND)
	gcc -Wall $(COMPILEFLAG) main.c -Wl,-rpath=. -o main_dynamic.exe -ldl -D DYNAMIC_LIB


test:
	
	./main_static.exe < commands.txt > results_static_$(SUFFIX).txt
	./main_shared.exe < commands.txt > results_shared_$(SUFFIX).txt
	# ./main_dynamic.exe < commands.txt > results_dynamic_$(SUFFIX).txt 2> /dev/null

	

optim_test:
	make o
	make test SUFFIX="O"
	make o0
	make test SUFFIX="O0"
	make o1
	make test SUFFIX="O1"
	make o2
	make test SUFFIX="O2"
	make o3
	make test SUFFIX="O3"
	make os
	make test SUFFIX="Os"

	touch report.txt
	make report
	

clean: 
	rm -f *.o *.a *.so *.exe results*.txt report.txt

report:
	# this will add all results to report


	echo "static_O >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_O.txt >> report.txt

	echo "static_O1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_O1.txt >> report.txt

	echo "static_O2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_O2.txt >> report.txt

	echo "static_O3 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_O3.txt >> report.txt

	echo "static_Os >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_Os.txt >> report.txt

	echo "static_O0 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_static_O0.txt >> report.txt


	echo "shared_O >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_O.txt >> report.txt

	echo "shared_O1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_O1.txt >> report.txt

	echo "shared_O2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_O2.txt >> report.txt

	echo "shared_O3 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_O3.txt >> report.txt

	echo "shared_Os >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_Os.txt >> report.txt

	echo "shared_O0 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	cat results_shared_O0.txt >> report.txt


	# echo "dynamic_O >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_O.txt >> report.txt

	# echo "dynamic_O1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_O1.txt >> report.txt

	# echo "dynamic_O2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_O2.txt >> report.txt

	# echo "dynamic_O3 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_O3.txt >> report.txt

	# echo "dynamic_Os >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_Os.txt >> report.txt

	# echo "dynamic_O0 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> report.txt
	# cat results_dynamic_O0.txt >> report.txt