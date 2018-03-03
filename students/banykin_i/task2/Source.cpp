#include <iostream>
#include <time.h>

#define size 20

using namespace std;

class vector {

private:
	int Coordinates[size];
	int dim = 0;
public:
	vector() {}
	//сложение
	vector operator+(const vector number) {
		vector tmp;
		tmp.dim = dim;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++)
			tmp.Coordinates[i] = Coordinates[i] + number.Coordinates[i];//складываем каждый элемент одного массива с каждым элементом другого

		return tmp;
	}
	//вычитание
	vector operator-(const vector number) {
		vector tmp;
		tmp.dim = dim;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++)
			tmp.Coordinates[i] = Coordinates[i] - number.Coordinates[i];//складываем каждый элемент одного массива с каждым элементом другого

		return tmp;
	}

	//скалярное умножени
	int Scalar(const vector number) {
		int tmp = 0;
		if (dim != number.dim)
			throw;
		for (int i = 0; i < dim; i++) {
			tmp += Coordinates[i] * number.Coordinates[i];//умножаем и складываем
		}

		return tmp;
	}
	//векторное произведение для 3х мерного пространства
	vector Vector(const vector number) {
		if (dim == 3) {
			vector tmp;
			tmp.dim = dim;
			tmp.Coordinates[0] = Coordinates[1] * number.Coordinates[2] - Coordinates[2] * number.Coordinates[1];
			tmp.Coordinates[1] = Coordinates[0] * number.Coordinates[2] - Coordinates[2] * number.Coordinates[0];
			tmp.Coordinates[2] = Coordinates[0] * number.Coordinates[1] - Coordinates[1] * number.Coordinates[0];

			return tmp;
		}
	}

	//вычисление длины
	float GetLength() {
		float tmp = 0;

		for (int i = 0; i < dim; i++)
			tmp += Coordinates[i] * Coordinates[i];// элементы массива возводятся в квадрат и складываются 

		return sqrt(tmp);//результат
	}
	//ручное изменение размерности
	void SetDim(int i) {
		dim = i;
	}
	//получение размерности
	int GetDim() {
		return dim;
	}
	//изменяет выбраную координату вектора
	void SetCoordinate(int i, int value) {
		Coordinates[i] = value;
	}
	//получает значение выбранной координаты
	int GetCoordinate(int i) {
		return Coordinates[i];
	}

	friend ostream& operator<<(ostream& os, vector &c);
};
//вывод класса в консоль
ostream& operator<<(ostream& os, vector &number) {
	os << '(';
	for (int i = 0; i < number.dim; i++) {
		os << number.Coordinates[i];
		if (i < number.dim - 1)
			os << ',';
	}
	os << ')';
	return os;
}


int main() {
	vector t1;
	vector t2;
	vector t;
	int n;
	int value;
	srand(time(NULL));
	/*	t1.SetDim(5);t2.SetDim(5);
	for (int i = 0; i < t1.GetDim(); i++) {
	value = rand() % 20;
	t1.SetCoordinate(i, value);
	value = rand() % 20;
	t2.SetCoordinate(i, value);
	}*/

	cout << "Enter dimention: "; cin >> n; t1.SetDim(n); t2.SetDim(n); system("cls");
	for (int i = 0; i < t1.GetDim(); i++) {
		cout << "1#Enter coordinate " << i + 1 << " : "; cin >> value;
		t1.SetCoordinate(i, value);
	}system("cls");
	for (int i = 0; i < t2.GetDim(); i++) {
		cout << "2#Enter coordinate " << i + 1 << " : "; cin >> value;
		t2.SetCoordinate(i, value);
	}

	cout << "1# vector = " << t1 << endl;
	cout << "2# vector = " << t2 << endl << endl;
	cout << "1#Length = " << t1.GetLength() << endl;
	cout << "2#Length = " << t2.GetLength() << endl << endl;
	t = t1 + t2; cout << t1 << " + " << t2 << " = " << t << endl;
	t = t1 - t2; cout << t1 << " - " << t2 << " = " << t << endl;
	cout << t1 << " * " << t2 << " = " << t1.Scalar(t2) << endl;
	if (n == 3)
		cout << t1 << " vector work " << t2 << " = " << t1.Vector(t2) << endl;

	system("pause");

	return 0;
}

