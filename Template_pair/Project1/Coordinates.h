#pragma once
#include <iostream>

/// <summary>
/// Класс координат, имеющий в себе два поля (int)
/// <para>-int first;</para>
/// <para>-int second;</para>
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

	 Coordinates operator * (Coordinates& data);
	 Coordinates operator / (Coordinates& data);
	 Coordinates operator % (Coordinates& data);
	 Coordinates operator + (Coordinates& data);
	 Coordinates operator += (Coordinates& data);
	 Coordinates operator - (Coordinates& data);
	 Coordinates operator -= (Coordinates& data);
	 Coordinates operator = (const Coordinates& data);
	 bool operator == (Coordinates& data);
	 bool operator >= (Coordinates& data);
	 bool operator <= (Coordinates& data);
	 bool operator > (Coordinates& data);
	 bool operator < (Coordinates& data);
	 bool operator != (Coordinates& data);

	 /// <summary> Печатает переменные в консоль </summary>
	 void iPrint();
	 /// <summary> Меняет значения местами в классе "Coordinates" </summary>
	 void iSwap();
	 /// <summary> Меняет значения местами в двух классов "Coordinates" </summary>
	 /// <param name=''>Принимает класс "Coordinates"</param>
	 void iSwap(Coordinates& data);
};

