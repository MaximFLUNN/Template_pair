#pragma once
#include <iostream>

/// <summary>
/// ����� ���������, ������� � ���� ��� ���� (int)
/// <para>-int first;</para>
/// <para>-int second;</para>
/// <para>��������������:</para>
/// <para>-Coordinates()</para>
/// <para>-Coordinates(int _first, int _second)</para>
/// <para>-Coordinates(const Coordinates data)</para>
/// <para>������:</para>
/// <para>-iPrint() - ������� �������� � �������</para>
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

	 /// <summary> �������� ���������� � ������� </summary>
	 void iPrint();
	 /// <summary> ������ �������� ������� � ������ "Coordinates" </summary>
	 void iSwap();
	 /// <summary> ������ �������� ������� � ���� ������� "Coordinates" </summary>
	 /// <param name=''>��������� ����� "Coordinates"</param>
	 void iSwap(Coordinates& data);
};

