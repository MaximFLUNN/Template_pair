#pragma once
#include <iostream>

/// <summary>
/// Класс координат, имеющий в себе два поля (int)
/// <para>-int first;</para>
/// <remarks>-int second;</remarks>
/// <para>Инициализаторы:</para>
/// <para>-Coordinates()</para>
/// <para>-Coordinates(int _first, int _second)</para>
/// <para>-Coordinates(const Coordinates data)</para>
/// <para>Методы:</para>
/// <para>-iPrint() - выводит значения в консоль</para>
/// </summary>
class Coordinates {
	friend std::ostream& operator << (std::ostream& out, Coordinates& data);
	
 private:
	int first;
	int second;

 public:

	 Coordinates();
	 Coordinates(int _first, int _second);
	 Coordinates(const Coordinates& data);

	 Coordinates operator + (const Coordinates& data);
	 Coordinates operator = (const Coordinates& data);

	 void iPrint();
};

