/*
* @title    : 1456번 거의 소수(골드5)
* @content  : 정수론
* @author   : 손동찬
* @date     : 240716
* @time     : 288 ms
* @memory   : 41272 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;
	vector<int> vecNumbers(sqrt(B)+1);
	for (long long i = 2; i <= sqrt(B); ++i)
		vecNumbers[i] = 1;

	for (long long i = 2; i <= sqrt(B); ++i)
	{
		if (!vecNumbers[i])
			continue;

		for (long long j = i * 2; j <= sqrt(B); j += i)
		{
			if (vecNumbers[j])
				vecNumbers[j] = 0;
		}
	}

	long long iCount = 0;
	for (long long i = 2; i <= sqrt(B); ++i)
	{
		if (vecNumbers[i] == 1)
		{
			for (long long j = 2; pow(i, j)<= B; ++j)
			{
				if(A <= pow(i, j)) 
					iCount++;					
			}
		}
	}

	cout << iCount << "\n";

	return 0;
}
