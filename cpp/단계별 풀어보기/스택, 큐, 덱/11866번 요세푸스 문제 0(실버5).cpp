/*
* @title    : 11866번 요세푸스 문제 0(실버5)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240720
* @time     : 4 ms
* @memory   : 2020 KB
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

	int N, K;
	cin >> N >> K;
	vector<bool> vecNums(N+1, true);
	int iTotal = 0;
	int iIndex = 0;
	int iCount = 0;

	cout << "<";
	while (iTotal < N)
	{
		++iCount;
		++iIndex;
		if (iIndex > N)
			iIndex = 1;

		while (!vecNums[iIndex])
		{
			++iIndex;
			if (iIndex > N)
				iIndex = 1;
		}
		
		if (iCount == K)
		{
			iCount = 0;
			vecNums[iIndex] = false;
			++iTotal;
			if (iTotal < N)
				cout << iIndex << ", ";
		}
	}
	
	cout << iIndex << ">";
	return 0;
}
