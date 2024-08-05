/*
* @title    : 10868번 최솟값(골드1)
* @content  : 세그먼트 트리
* @author   : 손동찬
* @date     : 240730
* @time     : 52 ms
* @memory   : 3236 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void SetSgTree(int _iIndex, vector<int>& _vecSgTree)
{
	while (_iIndex > 1)
	{
		_vecSgTree[_iIndex / 2] = min(_vecSgTree[_iIndex/2],_vecSgTree[_iIndex]);
		--_iIndex;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int P = 1;
	while (pow(2, P) < N)  ++P;
	int StartIndex = pow(2, P);

	vector<int> vecSgTree(StartIndex * 2, 1000000001);
	for (int i = 0; i < N; ++i)
		cin >> vecSgTree[StartIndex + i];

	SetSgTree(StartIndex * 2 -1, vecSgTree);
	
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		int Start	= StartIndex + a - 1;
		int End		= StartIndex + b - 1;
		int iMin	= 1000000001;
		while (Start <= End)
		{
			iMin = min(iMin, vecSgTree[Start]);
			iMin = min(iMin, vecSgTree[End]);

			Start = (Start + 1) / 2;
			End	= (End - 1) / 2;
		}

		cout << iMin << "\n";
	}

	return 0;
}
