#include <iostream>
#include <string>

using namespace std;

class LongNumber {
	char nullArray[20];
private:
	//заполняет массив нулями
	void ZeroArray() {
		for (char i = 0; i < 20; i++)
			nullArray[i] = '0';
	}
	//повышает разряд числа(единицы в десятки и тд.)
	void UpRank() {
		for (int i = 20; i > 0; i--)
			nullArray[i] = nullArray[i - 1];
		nullArray[0] = '0';
	}
	//ф-ция преобразовывает числа типа char в числа типа int
	int ChangeChar(char elementChar) {
		switch (elementChar) {
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default:  return 0;
		}
	}
	//тоже самое только наоборот
	char ChangeCharBack(int number) {
		switch (number) {
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		default:return '0';
		}
	}
public:
	LongNumber() {
		ZeroArray();
	}
	//идентификация элементов строки, занесение каждого элемента в ячейку массива
	LongNumber(char c[])
	{
		int sLength = strlen(c);
		ZeroArray();

		if (sLength <= 20)
		{
			for (int i = 0, j = sLength - 1; i < 20 && c[j] != '\0'; i++, j--)
			{
				nullArray[i] = c[j];
			}
		}
	}
	//сложение
	LongNumber operator+(const LongNumber &number) {
		LongNumber tmp;
		int temp = 0;
		int remainder;
		for (int i = 0; i < 20; i++) {
			temp = (ChangeChar(nullArray[i])) + (ChangeChar(number.nullArray[i])) + temp;//передаем в переменную результат сложения ячеек двух массивов 
			remainder = temp % 10;//вытаскивает последнюю цифру из числа
			//проверка остатка на отрицательность
			if (remainder < 0) {
				remainder += 10;
				temp -= 10;
			}
			tmp.nullArray[i] = ChangeCharBack(remainder);//передаем в "массив ответов" 
			temp /= 10;//сдвигает числа влево
		}
		return tmp;//возвращаем ответ
	}
	//вычитание
	LongNumber operator-(const LongNumber &number) {
		LongNumber tmp;
		int temp = 0;
		int remainder;
		for (int i = 0; i < 20; i++) {
			temp = (ChangeChar(nullArray[i])) - (ChangeChar(number.nullArray[i])) + temp;//передаем в переменную результат вычитания ячеек двух массивов 
			remainder = temp % 10;//вытаскивает последнюю цифру из числа
			//проверка остатка на отрицательность
			if (remainder < 0) {
				remainder += 10;
				temp -= 10;
			}
			tmp.nullArray[i] = ChangeCharBack(remainder);//передаем в "массив ответов"
			temp /= 10;
		}
		return tmp;//возвращаем результат
	}
	//умножение
	LongNumber operator*(const LongNumber &number) {
		LongNumber	temporary;
		LongNumber tmp;
		int	temp = 0;//остаток десяток
		int	temp2 = 0;//остаток единиц

		for (int j = 0; j < 20; j++) {
			for (int i = 0; i < 20 - j; i++) {
				if (number.nullArray[j] == '0')//игнорируем нули
					continue;
				temp2 = ChangeChar(nullArray[i]) * ChangeChar(number.nullArray[j]);//результат умножения ячеек двух массивов
				temporary.nullArray[i + j] = ChangeCharBack((temp2 += temp) % 10);//записывает результат в массив
				temp = temp2 / 10;//сдвигаем массив влево
			}
			tmp = tmp + temporary;//ответ
			temporary = "0";//обнуляем результат умножения
		}
		return tmp;//возвращаем результат
	}
	//деление
	LongNumber operator/(LongNumber &number) {
		if (number == (LongNumber)"0")
			throw;

		LongNumber tmp;
		LongNumber dividend(*this);//делимое
		LongNumber dividendPart;
		LongNumber divider(number);//делитель

		int size = 20;

		bool begin = false;
		//выполняем деление пока размер массива делимого больше нуля
		do {
			//пока часть делимого меньше делителя
			while (dividendPart < divider && size--> 0) {
				dividendPart.UpRank();//повышаем разряд части от делимого
				dividendPart.nullArray[0] = dividend.nullArray[size];//даем первой ячейке части делимого последний элемнт делимого
				if (dividend.nullArray[size] != '0')//начинаем делить , когда наткнулись на число
					begin = true;
				//делим
				if ((dividendPart < divider) && begin && dividend.nullArray[size] != '0')
					tmp.UpRank();
			}
			//записываем результат
			while (dividendPart >= divider) {
				dividendPart = dividendPart - divider;
				tmp = tmp + "1";
			}
			//прерываем цикл когда делимое закончилось
			if (size <= 0)
				break;

			tmp.UpRank();
		} while (size > 0);

		return tmp;//возвращаем результат
	}
	//деление с остатком
	LongNumber operator%(LongNumber &number) {
		if (number == (LongNumber)"0")
			throw;

		LongNumber tmp;
		LongNumber dividend(*this);//делимое
		LongNumber dividendPart;
		LongNumber divider(number);//делитель

		int size = 20;

		bool begin = false;
		//выполняем деление пока размер массива делимого больше нуля
		do {
			//пока часть делимого меньше делителя
			while (dividendPart < divider && size--> 0) {
				dividendPart.UpRank();//повышаем разряд части от делимого
				dividendPart.nullArray[0] = dividend.nullArray[size];//даем первой ячейке части делимого последний элемнт делимого
				if (dividend.nullArray[size] != '0')//начинаем делить , когда наткнулись на число
					begin = true;
				//делим
				if ((dividendPart < divider) && begin && dividend.nullArray[size] != '0')
					tmp.UpRank();
			}
			//записываем результат
			while (dividendPart >= divider) {
				dividendPart = dividendPart - divider;
				tmp = tmp + "1";
			}
			//прерываем цикл когда делимое закончилось
			if (size <= 0)
				break;

			tmp.UpRank();
		} while (size > 0);

		tmp = (*this) - tmp * number;//остаток

		return tmp;//возвращаем результат
	}
	//оператор присваивания		
	LongNumber operator=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--)
			nullArray[i] = number.nullArray[i];
		return *this;
	}
	//проверка на равенство
	bool operator==(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если какие-то элементы массивов не равны , возвращаем false
			if (ChangeChar(nullArray[i]) != ChangeChar(number.nullArray[i])) {
				return false;
			}
		}
		return true;
	}
	//проверка на неравенство
	bool operator!=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если какие-то элементы массивов не равны , возвращаем true
			if (ChangeChar(nullArray[i]) != ChangeChar(number.nullArray[i])) {
				return true;
			}
		}
		return false;
	}
	//проверка на меньшесть
	bool operator<(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если элемент массива меньше , возвращает true
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return true;
			//если элемент массива больше , возвращает false
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return false;
		}
		//общий выход, нужен когда, числа в строках равны
		return false;
	}
	//проверка на меньшесть/равность
	bool operator<=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если элемент массива меньше , возвращает true
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return true;
			//если элемент массива больше , возвращает false
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return false;
		}
	}
	//проверка на большесть
	bool operator>(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если элемент массива больше , возвращает true
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return true;
			//если элемент массива меньше , возвращает false
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return false;
		}
		//общий выход, нужен когда, числа в строках равны
		return false;
	}
	//проверка на большесть/равность
	bool operator>=(const LongNumber &number) {
		for (int i = 20; i >= 0; i--) {
			//если элемент массива больше , возвращает true
			if (ChangeChar(nullArray[i]) > ChangeChar(number.nullArray[i]))
				return true;
			//если элемент массива меньше , возвращает false
			if (ChangeChar(nullArray[i]) < ChangeChar(number.nullArray[i]))
				return false;
		}
	}

	//вывод ответа

	friend ostream& operator<<(ostream& os, const LongNumber &number);
};
//оператор вывода
ostream& operator<<(ostream& os, const LongNumber &number) {
	bool trigger = false;
	for (int i = 0; i < 20; i++) {
		if (number.nullArray[19 - i] != '0')
			trigger = true;
		if (trigger)
			os << number.nullArray[19 - i];
	}
	if (!trigger)
		os << 0;
	return os;
}

int main() {
	LongNumber c;
	LongNumber t1 = "140";
	LongNumber t2 = "0";
	LongNumber t(t1 % t2);
	cout << t << endl;
	system("pause");
	return 0;
}