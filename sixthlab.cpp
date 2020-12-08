#include <iostream>
#include <cmath>
using namespace std;


float arctg (float x, float eps);
int main()
{
	setlocale(0, "");
	float y;
	float x, eps;
	y = 0;
	cout << "Введите х=";
	cin >> x;                                   //ввод х
	cout << "Введите точность=";
	cin >> eps;                                 //ввод точности

	if (x > 1)                          //по условию проверяем х
		cout << "Невозможно рассчитать arctg(x), так как ряд Тэйлора стремится к бесконечности" << endl;
	// y = arctg(x,eps) / arctg(x-5,eps);
	else if (x >= 0 && x <= 1)                                                 //по условию задачи проверяем х
	{
		cout << "Значение arctg(x)=" << arctg(x, eps) << endl;                  //выводим значение арктангенса х, чтобы убедиться,что функция работает верно
		y = arctg(x, eps) - arctg(2 * x, eps);                                 //вычисляем по данной формуле у
	}
	else cout << "Не соответствует условию задачи" << endl;
	cout << "Значит y="<<y<<endl;                                              //выводим у
	system("pause");
	return 0;
}

float arctg(float x, float eps)
{
	int k;
	long double a, S;      

	k = 0;            //счетчик
	S = 0;             //зануляем сумму
	a = 0;              //элемент ряда Тэйлора
	do {
		a = (pow(x, 2 * k + 1) * pow(-1, k)) / (k * 2 + 1);      //вычисляем элемент ряда по выведенной формуле
		S = S + a;                                              //к сумме прибавляем элемент ряда
		k++;
	} while (a >= eps);                                    //делаем, пока элемент ряда будет больше заданной точности
	return S;                                             //возвращаем конечное значение суммы
}




