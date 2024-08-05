/*
* @title    : 2042번 구간 합 구하기(골드1)
* @content  : 세그먼트 트리
* @author   : 손동찬
* @date     : 240729
* @time     : 220 ms
* @memory   : 18596 KB
* @state    : 완료
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void FillParent(int _iIndex, vector<long long>& _vecSegmentTree)
{
	while (_iIndex > 1)
	{
		_vecSegmentTree[_iIndex / 2] += _vecSegmentTree[_iIndex];
		--_iIndex;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	
	int P = 1;
	while (pow(2, P) < N)  ++P;
		
	long long llStartIndex = pow(2, P);
	vector<long long> vecSegmentTree(llStartIndex * 2);

	for (long long i = 0; i < N; ++i)
		cin >> vecSegmentTree[llStartIndex + i];

	FillParent(llStartIndex * 2 -1, vecSegmentTree);
	
	for (int i = 0; i < M + K; ++i)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long Index = llStartIndex + b - 1;
			long long Diff = c - vecSegmentTree[Index];

			while (Index > 0)
			{
				vecSegmentTree[Index] += Diff;
				Index /= 2;
			}
		}

		else
		{
			long long Sum = 0;
			long long Start = llStartIndex + b - 1;
			long long End	= llStartIndex + c - 1;

			while (Start <= End)
			{
				if (Start % 2) Sum += vecSegmentTree[Start];
				if (!(End % 2)) Sum += vecSegmentTree[End];

				Start = (Start + 1) / 2;
				End = (End - 1) / 2;
			}

			cout << Sum << "\n";
		}
	}

	return 0;
}
