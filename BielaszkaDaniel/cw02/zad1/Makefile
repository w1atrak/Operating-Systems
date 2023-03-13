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