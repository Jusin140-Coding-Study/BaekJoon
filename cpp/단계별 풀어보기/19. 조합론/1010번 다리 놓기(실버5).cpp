/*
* @title    : 1010번 다리 놓기(실버5)
* @content  : 조합론
* @author   : 손동찬
* @date     : 240722
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

static int binomial(int n, int r, vector<vector<int>>& _vecCheck) {
	if (r == 0 || n == r)
		return _vecCheck[n][r] = 1;

	if (_vecCheck[n][r] != 0)
		return _vecCheck[n][r];

	if (_vecCheck[n][n-r] != 0)
		return _vecCheck[n][n-r];

	return _vecCheck[n][r] = binomial(n - 1, r - 1, _vecCheck) + binomial(n - 1, r, _vecCheck);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N, M;
		cin >> N >> M;
		if (N >= M)
		{
			cout << "1\n";
			continue;
		}
		vector<vector<int>> vecCheck(M+1, vector<int>(M+1, false));

		cout << binomial(M, N, vecCheck) << "\n";
	}

	return 0;
}
