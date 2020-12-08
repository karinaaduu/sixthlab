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
	cout << "������� �=";
	cin >> x;                                   //���� �
	cout << "������� ��������=";
	cin >> eps;                                 //���� ��������

	if (x > 1)                          //�� ������� ��������� �
		cout << "���������� ���������� arctg(x), ��� ��� ��� ������� ��������� � �������������" << endl;
	// y = arctg(x,eps) / arctg(x-5,eps);
	else if (x >= 0 && x <= 1)                                                 //�� ������� ������ ��������� �
	{
		cout << "�������� arctg(x)=" << arctg(x, eps) << endl;                  //������� �������� ����������� �, ����� ���������,��� ������� �������� �����
		y = arctg(x, eps) - arctg(2 * x, eps);                                 //��������� �� ������ ������� �
	}
	else cout << "�� ������������� ������� ������" << endl;
	cout << "������ y="<<y<<endl;                                              //������� �
	system("pause");
	return 0;
}

float arctg(float x, float eps)
{
	int k;
	long double a, S;      

	k = 0;            //�������
	S = 0;             //�������� �����
	a = 0;              //������� ���� �������
	do {
		a = (pow(x, 2 * k + 1) * pow(-1, k)) / (k * 2 + 1);      //��������� ������� ���� �� ���������� �������
		S = S + a;                                              //� ����� ���������� ������� ����
		k++;
	} while (a >= eps);                                    //������, ���� ������� ���� ����� ������ �������� ��������
	return S;                                             //���������� �������� �������� �����
}




