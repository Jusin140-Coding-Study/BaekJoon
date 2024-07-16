/*
* @title    : 1747번 소수&팰린드롬(실버1)
* @content  : 정수론
* @author   : 손동찬
* @date     : 240716
* @time     : 16 ms
* @memory   : 2268 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<bool> vecNumbers(2000001);
	for (int i = 2; i <= 2000000; ++i)
		vecNumbers[i] = true;

	for (int i = 2; i * i <= 2000000; ++i)
	{
		if (!vecNumbers[i])
			continue;

		for (int j = i * 2; j <= 2000000; j += i)
		{
			if (vecNumbers[j])
				vecNumbers[j] = false;
		}
	}

	for (int i = N; i <= 2000000; ++i)
	{
		if (!vecNumbers[i]) continue;

		string strNum = to_string(i);
		string strReverse = "";
		for (int j = strNum.size() - 1; j >= 0; --j)
			strReverse += strNum[j];
	
		if (strNum == strReverse) {
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}
