/*
* @title    : 2343번 기타레슨(실버1)
* @content  : 이진탐색
* @author   : 손동찬
* @date     : 240714
* @time     : 8 ms
* @memory   : 2412 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CountCheck(int _MaxLength, vector<int>& _vecLengths)
{
	int iCount = 0;
	int iLength = 0;

	for (int i = 0; i < _vecLengths.size(); ++i)
	{
		iLength += _vecLengths[i];
		if (iLength > _MaxLength)
		{
			iLength = _vecLengths[i];
			iCount++;
		}
	}
	return iCount + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> vecLengths(N);
	int iTotalLength = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> vecLengths[i];
		iTotalLength += vecLengths[i];
	}

	int iStart = *max_element(vecLengths.begin(), vecLengths.end());
	int iEnd = iTotalLength;

	while (iStart < iEnd)
	{
		int iMiddle = (iStart + iEnd) / 2;

		if (CountCheck(iMiddle, vecLengths) > M)
			iStart = iMiddle + 1;
	
		else
			iEnd = iMiddle;
	}
	
	cout << iStart;

	return 0;
}