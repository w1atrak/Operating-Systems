pozoiom wykonania: 100%

w zad1 do skompilowania obu bibliotek wystarczy: make all

w zad2 podobnie
polecenie do usuwania zadanego indexu to u mnie: delete <liczba oznaczajca index>
dodatkowe polecenie do zamykania programu: exit

w zad3a wystarczy: make test
pojawi sie plik report.txt zawierajacy wyniki

w zad3b wywolujemy: make optim_test 
pojawi sie wiele plikow z wynikami oraz report.txt zawierajacy je wszystkie

make clean do usuwania utworzonych plikow


komentarz do 3a:
biorac pod uwage 2 operacje wykonania polecenia wc najszybciej dziala wersja static, a najwolniej dynamic

komentarz do 3b:
widac pewne zwiekszenie czasu -O2 wzgledem -O, dla -O3 czasy nizsze