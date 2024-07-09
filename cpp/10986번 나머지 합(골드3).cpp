/*
* @title    : 10986번 나머지 합(골드3)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 188 ms
* @memory   : 9892 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<long long> v(N + 1, 0);

	for (int i = 1; i <= N; ++i)
	{
		long long iNum;
		cin >> iNum;
		v[i] = v[i - 1] + iNum;
	}

	long long iResult = 0;
	map<int, int> m;

	for (int i = 1; i <= N; ++i)
	{
		int iNum = v[i] % M;
		if (!iNum) iResult++;

		m[iNum]++;
	}

	for (auto& iter : m)
	{
		long long iNum = iter.second;
		iResult += ( (iNum * (iNum - 1)) / 2 );
	}

	cout << iResult << "\n";
}