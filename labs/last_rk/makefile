ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

main.exe : list_functions.o logic_functions.o main.o
	gcc -o main.exe list_functions.o logic_functions.o main.o

list_functions.o : list_functions.c list_functions.h
	gcc -std=c99 -c list_functions.c

logic_functions.o : logic_functions.c logic_functions.h
	gcc -std=c99 -c logic_functions.c

main.o : main.c list_functions.h logic_functions.h
	gcc -std=c99 -c main.c

clean : 
	rm *.o*.exe
