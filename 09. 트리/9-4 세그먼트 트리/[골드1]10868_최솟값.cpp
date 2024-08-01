#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> SegTree;
void MakeSegTree(int iIndex);
long GetMinimum(int iStart, int iEnd);

// 세그먼트 트리
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M;
	cin >> N >> M;

	int iTreeHeight = 0;
	int iNumLength = N;

	// 트리의 높이를 구합니다.
	while (0 != iNumLength)
	{
		iNumLength /= 2;
		++iTreeHeight;
	}

	int iTreeSize = (int)pow(2, iTreeHeight + 1);
	int iLeafNodeStartIndex = iTreeSize / 2;

	SegTree = vector<long>(iTreeSize, 0);

	// 리프노드 배열을 채웁니다.
	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin >> SegTree[i];

	MakeSegTree(iTreeSize - 1);

	// 질의를 받습니다.
	for (int i = 0; i < M; ++i)
	{
		long s, e;
		cin >> s >> e;

		s = s + iLeafNodeStartIndex - 1;
		e = e + iLeafNodeStartIndex - 1;

		cout << GetMinimum(s, e) << "\n";
	}

	return 0;
}

void MakeSegTree(int iIndex)
{
	while (2 < iIndex)
	{
		if (SegTree[iIndex] < SegTree[iIndex - 1])
			SegTree[iIndex / 2] = SegTree[iIndex];
		else
			SegTree[iIndex / 2] = SegTree[iIndex - 1];

		iIndex -= 2;
	}
}

long GetMinimum(int iStart, int iEnd)
{
	long lMin = 1'000'000'000;

	while (iStart <= iEnd)
	{
		if (iStart % 2 == 1)
			lMin = min(lMin, SegTree[iStart]);

		if (iEnd % 2 == 0)
			lMin = min(lMin, SegTree[iEnd]);

		iStart = (iStart + 1) / 2;
		iEnd = (iEnd - 1) / 2;
	}

	return lMin;
}