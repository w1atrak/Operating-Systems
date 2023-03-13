
all:
	make program_1
	make program_1024

program_1: main.c
	gcc -Wall main.c -o main_1 -D CHARS_NUMBER=1


program_1024: main.c
	gcc -Wall main.c -o main_1024 -D CHARS_NUMBER=1024

clean:
	rm -f main_1
	rm -f main_1024


test:
	make all
	rm -f pomiar_zad_2.txt
	touch pomiar_zad_2.txt
	echo "Pomiar czasu dla 1 bajtu:" >> pomiar_zad_2.txt
	./main_1 main.c tmp1 >> pomiar_zad_2.txt
	./main_1 Makefile tmp2 >> pomiar_zad_2.txt
	./main_1 main_1 tmp5 >> pomiar_zad_2.txt
	./main_1 main_1024 tmp6 >> pomiar_zad_2.txt
	echo "Pomiar czasu dla 1024 bajtów:" >> pomiar_zad_2.txt
	./main_1024 main.c tmp3 >> pomiar_zad_2.txt
	./main_1024 Makefile tmp4 >> pomiar_zad_2.txt
	./main_1024 main_1 tmp7 >> pomiar_zad_2.txt
	./main_1024 main_1024 tmp8 >> pomiar_zad_2.txt

	rm -f tmp1 tmp2 tmp3 tmp4 tmp5 tmp6 tmp7 tmp8


