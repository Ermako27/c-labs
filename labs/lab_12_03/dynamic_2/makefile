ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

main.exe : libdynfunc.so
	gcc -rdynamic -o main.exe main.c -ldl

functions.o : functions.c functions.h
	gcc -std=c99 -Wall -Werror -fPIC -c functions.c

libdynfunc.so : functions.o
	gcc -shared -o libdynfunc.so functions.o

clean : 
	rm *.o *.exe *.so
