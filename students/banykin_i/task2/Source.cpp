#include <iostream>
#include <time.h>

#define size 20

using namespace std;


class vector {
	int nullArray[size];
	int dim = 0;
	//нулевой массив, от нуля до размера массива
	void ZeroArray() {
		for (int i = 0; i < dim; i++)
			nullArray[i] = 0;
	}

public:
	vector() {
		ZeroArray();
	}
	//перенос массива в нулевой массив
	vector(int number[]) {
		dim = GetDim(number);
		ZeroArray();
		for (int i = 0; i < size; i++)
			nullArray[i] = number[i];
	}
	//сложение
	vector operator+(const vector number) {
		vector tmp;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++)
			tmp.nullArray[i] = nullArray[i] + number.nullArray[i];//складываем каждый элемент одного массива с каждым элементом другого
		tmp.dim = dim;

		return tmp;
	}
	//вычитание
	vector operator-(const vector number) {
		vector tmp;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++)
			tmp.nullArray[i] = nullArray[i] - number.nullArray[i];//складываем каждый элемент одного массива с каждым элементом другого
		tmp.dim = dim;

		return tmp;
	}
	//скалярное умножени
	vector operator*(const vector number) {
		vector tmp;
		tmp.nullArray[0] = 0;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++) {
			tmp.nullArray[0] += nullArray[i] * number.nullArray[i];//умножаем и складываем
		}

		tmp.dim = 1;//сокращаем длину массива для правильного вывода

		return tmp;
	}
	//векторное произведение, только для трехмерного пространства
	vector operator &(const vector number) {
		if (dim <= 3) {
			vector tmp;
			tmp.dim = dim;
			tmp.nullArray[0] = nullArray[1] * number.nullArray[2] - nullArray[2] * number.nullArray[1];
			tmp.nullArray[1] = nullArray[0] * number.nullArray[2] - nullArray[2] * number.nullArray[0];
			tmp.nullArray[2] = nullArray[0] * number.nullArray[1] - nullArray[1] * number.nullArray[0];
			return tmp;
		}
	}

	//вычисление длины
	float GetLength() {
		float tmp = 0;

		for (int i = 0; i < dim; i++)
			tmp += nullArray[i] * nullArray[i];// элементы массива возводятся в квадрат и складываются 

		return sqrt(tmp);//результат
	}
	//ручное изменение размерности
	int SetDim(int i) {
		return dim = i;
	}
	//получение размерности
	int GetDim() {
		return dim;
	}
	//перегруженная функция изменения размерности
	int GetDim(int number[]) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (number[i] != NULL)//считывает числа до нуля; если в массиве есть нулевая координата , то следует воспользоваться ручной настройкой размерности
				count++;
		}
		return dim = count;
	}
	//изменяет выбраную координату вектора
	void SetCoordinate(int i, int value) {
		nullArray[i] = value;
	}
	//получает значение выбранной координаты
	int GetCoordinate(int i) {
		return nullArray[i];
	}
	//тестовая функция для демонстрации работостпособности класса
	void Test(int c) {
		srand(time(NULL));
		SetCoordinate(1, c);
		cout << endl << "SetCoordinate(1," << c << ")" << endl;
		int d = GetCoordinate(1);
		cout << "GetCoordinate(1): " << d << endl;

		float a = GetLength();
		cout << endl << "length: " << a << endl;
		int b = GetDim();
		cout << "dimention: " << b << endl << endl;
		cout << endl;
	}

	friend ostream& operator<<(ostream& os, vector &c);
};
//вывод класса в консоль
ostream& operator<<(ostream& os, vector &number)
{
	os << '(';
	for (int i = 0; i < number.dim; i++)
	{
		os << number.nullArray[i];
		if (i < number.dim - 1)
			os << ',';
	}
	os << ')';
	return os;
}


int main() {
	int number[size] = { 21, 14, 9, 14 };
	int number2[size] = { 13, 901, 24 , 16 };
	//задаем векторы
	vector t1(number);
	vector t2(number2);
	vector t;
	t = t1 + t2; cout << t1 << " + " << t2 << " = " << t << endl;
	t = t1 - t2; cout << t1 << " - " << t2 << " = " << t << endl;
	t = t1 * t2; cout << t1 << " * " << t2 << " = " << t << endl;
	int q = t1.GetDim();
	if (q <= 3) {//векторное произведение для трехмерного пространства
		t = t1 & t2; cout << t1 << " & " << t2 << " = " << t << endl;
	}

	int c = rand() % 1000;
	t1.Test(c);
	t1.SetDim(4); t2.SetDim(4);
	cout << "AFTER DIMENTION SET:" << endl;
	c = rand() % 1000;
	t1.Test(c);

	t = t1 + t2; cout << t1 << " + " << t2 << " = " << t << endl;
	t = t1 * t2; cout << t1 << " * " << t2 << " = " << t << endl;
	t = t1 + t2; cout << t1 << " + " << t2 << " = " << t << endl;
	t = t1 - t2; cout << t1 << " - " << t2 << " = " << t << endl;
	t = t1 * t2; cout << t1 << " * " << t2 << " = " << t << endl;
	q = t1.GetDim();
	if (q <= 3) {//векторное произведение для трехмерного пространства
		t = t1 & t2; cout << t1 << " & " << t2 << " = " << t << endl;
	}

	system("pause");

	return 0;
}

