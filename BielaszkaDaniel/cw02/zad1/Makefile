FLAG=-Wall


all:
	make sys
	make lib

sys: main.c
	gcc $(FLAG) main.c -o main_sys -D USE_SYS

lib: main.c
	gcc $(FLAG) main.c -o main_lib 


clean:
	rm -f main_sys main_lib

test:
	make all
	rm -f pomiar_zad_1.txt
	touch pomiar_zad_1.txt
	echo "Pomiar czasu dla funkcji systemowych:" >> pomiar_zad_1.txt
	./main_sys e i main.c tmp1 >> pomiar_zad_1.txt
	./main_sys e i Makefile tmp2 >> pomiar_zad_1.txt
	echo "Pomiar czasu dla funkcji bibliotecznych:" >> pomiar_zad_1.txt
	./main_lib e i main.c tmp3 >> pomiar_zad_1.txt
	./main_lib e i Makefile tmp4 >> pomiar_zad_1.txt

	rm -f tmp1 tmp2 tmp3 tmp4