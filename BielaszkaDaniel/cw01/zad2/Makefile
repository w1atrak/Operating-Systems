SHELL=/bin/bash # ?
FLAGSS=-Wall
LIB=lib1

BINS=main.c dllmanager.h #?

all:
	make lib_static
	make lib_shared
	make program_static
	make program_shared
	make program_dlopen


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


