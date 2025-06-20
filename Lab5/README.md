# Лабораторная работа: Обработка матриц

## Условие

При работе с матрицами необходимо:
- Использовать динамический массив
- Предусмотреть два способа заполнения:
  1. Ввод с клавиатуры
  2. Заполнение случайными числами (с предварительным заданием границ интервала)
- Выводить результаты расчетов
- При невозможности решения выводить соответствующее сообщение

**Задание 1:**
Для целочисленной прямоугольной матрицы:
1. Найти сумму элементов в строках, не содержащих нулей
2. Переставить столбцы:
   - 1-й с последним
   - 2-й с предпоследним
   - и т.д.

**Задание 2:**
Для целочисленной прямоугольной матрицы m×n:
1. Найти номер первой строки, содержащей хотя бы один ноль
2. Найти координаты всех седловых точек (если они существуют) по условию:
   ```maximinj mtr[i][j] = minjmaxi mtr[i][j]```