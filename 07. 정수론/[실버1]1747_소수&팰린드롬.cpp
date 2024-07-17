#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ※ 헤맸던 점 ※
	// 전체 범위를 N ~ 백만으로 두고 판별하고 있었음.
	// 백만보다 큰 수 중에서 소수이면서 팰린드롬인 수도 고려해야 함

	// 1. 에라토스테네스로 1차 거름
	// 2. 팰린드롬인지 판별
	// 3. 맞다면 출력
	int N = 0;
	cin >> N;

	vector<bool> V(10000001, true);
	V[0] = false;
	V[1] = false;

	// 에라토스테네스의 체
	for (int i = 2; i <= sqrt(10000001); ++i)
	{
		if (false == V[i]) continue;

		for (int j = 2 * i; j <= 10000000; j += i)
			V[j] = false;
	}

	for (int i = N; i < 10000001; ++i)
	{
		if (false == V[i]) continue;

		string strNum = to_string(i);

		int start = 0;
		int end = strNum.size() - 1;

		bool bEqual = true;

		while (start < end)
		{
			if (strNum[start] != strNum[end])
			{
				bEqual = false;
				break;
			}

			start++;
			end--;
		}

		if (bEqual)
		{
			cout << strNum << "\n";
			break;
		}
	}

	return 0;
}