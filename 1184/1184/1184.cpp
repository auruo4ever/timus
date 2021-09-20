#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	float cable;
	long long sum = 0;
	int N, K, num = 0, len, min = 1, max = -1, ans = 0;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> cable;
		v.push_back(static_cast<int>(cable * 100));
		//cout << v[i] << endl;
		sum += v[i];
		if (v[i] > max) {
			max = v[i];
		}

	}
	if (sum / K < 1) {
		cout << "0.00";
		return 0;
	}
	while (min <= max) {
		len = (max + min) / 2;
		//cout << "len " << len << endl;

		for (int i = 0; i < v.size(); i++) {
			num += v[i] / len;
		}
		//cout << "num " << num << endl;
		//cout << "min " << min << endl;
		//cout << "max " << max << endl;
		if ((num >= K) && (len >= ans)) {
			min = len + 1;
			ans = len;
		}
		if (num > K) {
			min = len + 1;
		} else if (num < K) {
			max = len - 1;
		}
		num = 0;
	}
	cable = (float)ans;
	cout << fixed << setprecision(2) << cable/100.0;

	return 0;
}

