# filler
![screenshot](sss.png?raw=true)
- игра, в которой два игрока / алгоритма сражаются на карте.

Виртуальная машина организует игру:

Называет игроков поочередно
Дает каждому случайный кусок фигуры

На каждом ходу текущий игрок должен поместить свою фигуру на карту и попытаться заблокировать противника. Чтобы положить кусок, игрок должен записать свои координаты в формате "Y X \ n" на стандартный ввод (stdin).

Игра появляется на стандартном входе.

Цель игры - поместить на карту больше фигур, чем враг.
Запуск: 

./make

./resources/filler_vm -p1 ./fsnow-be.filler -p2 ./resources/players/abanlin.filler -f resources/maps/map00
