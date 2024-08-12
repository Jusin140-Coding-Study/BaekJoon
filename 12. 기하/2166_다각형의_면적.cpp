#include <iostream>
#include <cmath>

using namespace std;

int N;
long long x[10001];
long long y[10001];

double result = 0.0;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}

	x[N] = x[0];
	y[N] = y[0];

	for (int i = 0; i < N; ++i) {

		result += (x[i] * y[i + 1] - x[i + 1] * y[i]);
	}

	result /= 2.0;

	cout.precision(1);

	cout << fixed << abs(result);


	return 0;

}