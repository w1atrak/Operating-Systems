wykonanie: 100%

zad1: make test kompiluje 2 wersje programu oraz tworzy test ktorego wyniki umieszcza w pomiar_zad_1.txt
uzycie wersji systemowych daje krotszy czas


zad2: make all tworzy 2 wersje: main_1 oraz main_1024
make test: wywoluje test, wyniki w pliku pomiar_zad_2.txt wskazuja ze odczyt po 1024 znaki jest szybszy
porowanie przy pomocy diff -s wskazuje na identycznosc oryginalnego oraz 2krotnie odwroconego pliku

zad3: kompilacja: make main
wywolanie: ./main
zgodnosc z wc --bytes *

zad 4: kompilacja poprzez: make main
wywolanie: ./main
zgodnosc z poleceniem find nazwa | xargs wc --bytes


do wszystkich zadan pliki usuwa make main

pliki docelowe w zad 1 oraz 2 nie musza istniec oraz nie sa usuwane automatycznie
