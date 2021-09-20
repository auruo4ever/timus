#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return -8+45*x*x-25*x*x*x*x;
}
double df4(double x)
{
	return -600;
}

int main() {
	double a, b, eps;//Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
	cin >> a >> b >> eps;
	int iteras;
	double I = eps + 1, I1 = 0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
	for (int N = 1; (N <= 4); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2*N);//Шаг интегрирования.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += f(a + h * i);//Значения с нечётными индексами, которые нужно умножить на 4.
			sum2 += f(a + h * (i + 1));//Значения с чётными индексами, которые нужно умножить на 2.
			iteras = N;
		}
		sum = f(a) + 4 * sum4 + 2 * sum2 - f(b);//Отнимаем значение f(b) так как ранее прибавили его дважды. 
		I = I1;
		I1 = (h / 3) * sum;
	}
	cout << "answer: " << I1 << endl;
	cout << "N: " << iteras/2 << endl;
	cout << "R ost: " << (b - a)*pow(eps, 4)*df4(eps)/180 << endl;

	return 0;
}