#pragma once
#include <iostream>
#include <typeinfo>

/// <summary>
///  ласс координат, имеющий в себе два пол¤ (int)
/// <para>-int first;</para>
/// <para>-int second;</para>
/// <para>»нициализаторы:</para>
/// <para>-Coordinates()</para>
/// <para>-Coordinates(int _first, int _second)</para>
/// <para>-Coordinates(const Coordinates data)</para>
/// <para>ћетоды:</para>
/// <para>-iPrint() - выводит значени¤ в консоль</para>
/// </summary>
template <class Type_1, class Type_2>
class Coordinates {
 private:
	Type_1 first;
	Type_2 second;

 public:
	 Coordinates();
	 Coordinates(Type_1 _first, Type_2 _second);
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

	 /// <summary> ѕечатает переменные в консоль </summary>
	 void iPrint();
	 /// <summary> ѕечатает переменные в консоль в виде a; b при false и (a; b) при true</summary>
	 void iPrint(bool flag);
	 /// <summary> ѕечатает им¤ типа данных в консоль </summary>
	 void iPrint_type();
	 /// <summary> ћен¤ет значени¤ местами в классе "Coordinates" </summary>
	 void iSwap();
	 /// <summary> ћен¤ет значени¤ местами в двух классов "Coordinates" </summary>
	 /// <param name=''>ѕринимает класс "Coordinates"</param>
	 void iSwap(Coordinates& data);

	 friend std::ostream& operator << (std::ostream& out, const Coordinates& data) {
		 out << "First: " << data.first << "\n" << "Second: " << data.second << "\n";
		 return out;
	 }
};

