/*
* @title    : 13251번 조약돌 꺼내기(실버3)
* @content  : 조합
* @author   : 손동찬
* @date     : 240805
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);

	int M, K;
	cin >> M;
	vector<int> vecNums(M);
	int iTotal = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> vecNums[i];
		iTotal += vecNums[i];
	}

	cin >> K;

	double dResult = 0.0;

	for (int i = 0; i < M; ++i)
	{
		double d = 1.0;
		int A = vecNums[i];
		int B = iTotal;
		int iCount = 0;
		while (iCount < K)
		{
			d *= ((double)A/(double)B);
			--B;
			--A;
			++iCount; 
		}
		dResult += d;
	}

	cout << dResult;
	return 0;
}