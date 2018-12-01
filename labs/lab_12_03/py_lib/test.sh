#!/bin/bash

#Запуск функции генерации последовательности простых чисел (5 чисел) 
python3 copy_and_simple.py < in_1.txt > out.txt
diff out.txt out_1.txt

#Запуск функции генерации последовательности простых чисел (1 число) 
python3 copy_and_simple.py < in_2.txt > out.txt
diff out.txt out_2.txt

#Запуск функции генерации последовательности простых чисел (-1 число) 
python3 copy_and_simple.py < in_3.txt > out.txt
diff out.txt out_3.txt

#Добавление после четных - тривальный случай
python3 copy_and_simple.py < in_4.txt > out.txt
diff out.txt out_4.txt

#Добавление после четных - нет четных
python3 copy_and_simple.py < in_5.txt > out.txt
diff out.txt out_5.txt

#Добавление после четных - только четные
python3 copy_and_simple.py < in_6.txt > out.txt
diff out.txt out_6.txt

#Добавление после четных - xетное отрицательное
python3 copy_and_simple.py < in_7.txt > out.txt
diff out.txt out_7.txt