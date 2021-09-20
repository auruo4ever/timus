#include <iostream>
using namespace std;

int main()
{
	int mas[20];
	int n, k;
	cin >> n >> k;
	int num = k - 1; //все цифры данной системы счисления без 0
	mas[0] = 1;
	mas[1] = num;

	for (int i = 2; i <= n; i++) {
		mas[i] = (mas[i - 1] * num + mas[i - 2] * num); //отдельно когда добавляем 0 вариантов и не 0 вариантов
	}
	cout << mas[n];
	return 0;
}