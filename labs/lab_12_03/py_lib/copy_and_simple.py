from ctypes import *

lib = CDLL("./libpyfunc.so")

_data_copy = lib.data_copy
_data_copy.argtypes = ( POINTER(c_int),  POINTER(POINTER(c_int)), c_int, c_int)
_data_copy.restype = c_int



_simple_numbers = lib.simple_numbers
_simple_numbers.argtypes = (POINTER(POINTER(c_int)), c_int)
_simple_numbers.restype = c_int



def data_copy(array,key):
    data1 = POINTER(c_int)()
    src = (c_int * len(array))(*array)
    error = _data_copy(src, byref(data1),len(array),key)
    return error, data1

def simple_numbers(amount):
    array = POINTER(c_int)()
    a = _simple_numbers(byref(array), amount)
    return a, array




menu = 1
while menu:
    print('1 - Сгенерировать ряд простых чисел ')
    print('2 - Скопировать один массив в другой с добавлением числа после каждого четного элемента. ');
    print('0 - Выход');
    print();

    menu = int(input('>>> '))

    if type(menu) == float:
        print('Некорректный ввод, номер пункта меню - целое число')
    if menu < 0 or menu > 2:
        print('Некорректный ввод, несуществует такого пункта меню');

    elif menu == 1:
        
        n = int(input('Введите длину массива: '))
        error, arr = simple_numbers(n)
        if error == -1:
            print('Некорректный ввод, длинна массива - положительная величина')
        else:
            for i in range(n):
                print(arr[i], end=' | ')
        print()        
        print()

    elif menu == 2:
        array_src = [int(x) for x in input("Введите массив:  ").split()]

        # for i in range(len(array_src)):
        #     print(array_src[i])
        # print(array_src)

        key = int(input('Введите число для вставки: '))
        error, data1 = data_copy(array_src, key);
        if error == -1:
            print('Некорректный ввод, длина должна быть больше нуля')
        else:
            for i in range(error):
                print(data1[i], end=' | ')
        print()
        print()



        # array = [int(x) for x in input("Введите массив:  ").split()]

