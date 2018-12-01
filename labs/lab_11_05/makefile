ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

main.exe : functions.o main.o
	gcc -o main.exe functions.o main.o -lm
functions.o : functions.c functions.h
	gcc -std=c99 -Wall -Werror -c functions.c -lm
main.o : main.c functions.h
	gcc -std=c99 -Wall -Werror -c main.c -lm

clean : 
	rm *.o*.exe