#include <iostream>
#include <iomanip>;
using namespace std;
int main()
{
	int N;
	float a0, a1, aN, ci, sum = 0;
	cin >> N >> a0 >> aN;
	float* c = new float[N];
	for (int i = 0; i < N; i++) {
		cin >> ci;
		sum = sum + (2+2*(N-(i+1)))*ci;
	}

	a1 = (aN+N*a0-sum)/(N+1);
	cout << setprecision(2) << fixed;
	cout << a1;

	return 0;
}

