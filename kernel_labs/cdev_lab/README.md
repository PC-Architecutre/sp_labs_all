# km_labs
## Character device module

1. make

2. /sbin/insmod file.ko <- su!!!

3. dmesg <- su !!! look to log of kernel

4. cd cprog

5. gcc main.c -o a.out 

6. ./a.out <- su !!!

7./sbin/rmmod file <- su!!! exit

8. dmesg <- su !!! look to log of kernel

В данной лабораторной работе 8 вариантов, в каждом из которых необходимо создать свое символьное устройство
    и воспользоватся его функционалом из простой С програмы, необходимо реальзовать функции open, close и указанные в варианте,
в каждом варианте необходимо вывести в консоль результаты задания
### Варианты:
* Реализовать read и передавать в юзерспейс текущее время
* Реализовать read и передавать в юзерспейс случайный набор бит
* Реализовать read и передавать в юзерспейс значение внетреннего счетчика модуля, read инкрементирует счетчик
* Реализовать write, который записывает переданную строчку в буфер и выводит последний в консоль
* Реализовать write, который принимает целое число и считает его факториал
* Реализовать write, который принимает число и определяет простое ли оно
* Реализовать ioctl с 5ю командами, который считает кол-во обращений к каждой команде
* Реализовать ioctl который выодит данные о девайсе в зависимости от команды(minor, major, dev addres, etc)

Как созавать символьное устройство можно прочитать в разделе "Глава 3, Символьные драйверы" книги Linux device drivers, которая прикреплена к этому репозиторую