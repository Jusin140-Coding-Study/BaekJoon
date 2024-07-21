/*
* @title    : 11050번 이항 계수 1(브론즈1)
* @content  : 조합론
* @author   : 손동찬
* @date     : 240722
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

static int binomial(int n, int r) {
	if (r == 0 || n == r)
		return 1;

	return binomial(n - 1, r - 1) + binomial(n - 1, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	cout << binomial(N,K);

	return 0;
}
