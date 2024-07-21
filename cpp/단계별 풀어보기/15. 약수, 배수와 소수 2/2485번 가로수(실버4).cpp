/*
* @title    : 2485번 가로수(실버4)
* @content  : 약수, 배수와 소수 2
* @author   : 손동찬
* @date     : 240717
* @time     : 12 ms
* @memory   : 2412 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

static int GCD(int A, int B)
{
	int iMax = max(A, B);
	int iMin = min(A, B);
	
	while (iMax % iMin)
	{
		int Temp = iMin;
		iMin = iMax % iMin;
		iMax = Temp;
	}

	return iMin;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> vecDistance(N);

	cin >> vecDistance[0];

	for (int i = 1; i < N; ++i)
	{
		cin >> vecDistance[i];
		vecDistance[i - 1] = vecDistance[i] - vecDistance[i - 1];
	}
	vecDistance.pop_back();
	int iGCD = vecDistance[0];
	for (int i = 1; i < vecDistance.size(); ++i)
	{
		iGCD = GCD(iGCD, vecDistance[i]);
	}

	int iCount = 0;
	for (int i = 0; i < vecDistance.size(); ++i)
	{
		iCount += (vecDistance[i] / iGCD) - 1;
	}

	cout << iCount;

	return 0;
}
