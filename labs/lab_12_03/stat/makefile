ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

main.exe : libstatfunc.a
	gcc -std=c99 -Wall -Werror main.c libstatfunc.a -o main.exe

functions.o : functions.c functions.h
	gcc -std=c99 -Wall -Werror -c functions.c

libstatfunc.a : functions.o
	ar rc libstatfunc.a functions.o
	ranlib libstatfunc.a

clean : 
	rm *.o*.exef
