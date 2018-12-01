ifeq ($(mode), debug)
    # Отладочная сборка: добавим генерацию отладочной информации
    CFLAGS += -g3
endif

ifeq ($(mode), release)
    # Финальная сборка: исключим отладочную информацию и утверждения (asserts)
    CFLAGS += -DNDEBUG -g0
endif


main.exe : printmass.o readfile.o sort.o diffitems.o main.o
	gcc -o main.exe printmass.o readfile.o sort.o diffitems.o main.o
	
unit_test_read_file.exe : unit_test_read_file.o
	gcc -o unit_test_read_file.exe unit_test_read_file.o

unit_test_sort.exe : unit_test_sort.o
	gcc -o unit_test_sort.exe unit_test_sort.o
	
unit_test_diffitems.exe : unit_test_diffitems.o
	gcc -o unit_test_diffitems.exe unit_test_diffitems.o
	
printmass.o : printmass.c printmass.h
	gcc -std=c99 -Wall -Werror -pedantic -c printmass.c

readfile.o : readfile.c readfile.h
	gcc -std=c99 -Wall -Werror -pedantic -c readfile.c

sort.o : sort.c sort.h
	gcc -std=c99 -Wall -Werror -pedantic -c sort.c

diffitems.o : diffitems.c diffitems.h
	gcc -std=c99 -Wall -Werror -pedantic -c diffitems.c

main.o : main.c printmass.h readfile.h sort.h diffitems.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c
	
unit_test_read_file.o : unit_test_read_file.c 
	gcc -std=c99 -Wall -Werror -pedantic -c unit_test_read_file.c
	
unit_test_sort.o : unit_test_sort.c 
	gcc -std=c99 -Wall -Werror -pedantic -c unit_test_sort.c
	
unit_test_diffitems.o : unit_test_diffitems.c 
	gcc -std=c99 -Wall -Werror -pedantic -c unit_test_diffitems.c


clean :
	rm *.o*.exe