ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif

unit_test.exe : libpyfunc.so
	gcc -std=c99 -Wall -Werror -c unit_test.c
	gcc unit_test.o -L. libpyfunc.so -o unit_test.exe
	export LD_LIBRARY_PATH=.

functions.o : functions.c functions.h
	gcc -std=c99 -Wall -Werror -fPIC -c functions.c

libpyfunc.so : functions.o
	gcc -shared -o libpyfunc.so functions.o

clean :
	rm *.o*.exe 



