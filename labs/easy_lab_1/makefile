# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

# Общие объектные файлы
OBJS := functions.o integration.o roots.o

main.exe : $(OBJS) main.o
	$(CC) $^ -o $@

test_main.exe : $(OBJS) test.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) *.o *.exe
