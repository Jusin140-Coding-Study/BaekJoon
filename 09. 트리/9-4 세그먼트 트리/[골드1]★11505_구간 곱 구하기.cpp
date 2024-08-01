#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int iMod = 1'000'000'007;
static vector<long long> SegTree;
void MakeSegTree(int iIndex);
void ChangeValue(int iIndex, long long iValue);
long long GetPartMul(int iStart, int iEnd);

// 세그먼트 트리
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M; int K;
	cin >> N >> M >> K;

	int iTreeHeight = 0;
	int iNumLength = N;

	// 트리의 높이를 구합니다.
	while (0 != iNumLength)
	{
		iNumLength /= 2;
		++iTreeHeight;
	}

	// 트리 배열의 크기를 구합니다.
	int iTreeSize = (int)pow(2, iTreeHeight + 1);
	int iLeafNodeStartIndex = iTreeSize / 2;
	
	SegTree = vector<long long>(iTreeSize + 1, 1);

	// 리프 노드의 값을 채웁니다.
	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin >> SegTree[i];

	// 세그먼트 트리를 만듭니다.
	MakeSegTree(iTreeSize - 1);

	// 질의를 받습니다.
	for (int i = 0; i < M + K; ++i)
	{
		long long a, s, e;
		cin >> a >> s >> e;

		if (1 == a)
		{
			// 값을 변경합니다.
			s = s + iLeafNodeStartIndex - 1;
			ChangeValue(s, e);
		}
		else
		{
			// 구간곱을 출력합니다.
			s = s + iLeafNodeStartIndex - 1;
			e = e + iLeafNodeStartIndex - 1;
			cout << GetPartMul(s, e) << "\n";
		}
	}
	
	return 0;
}

void MakeSegTree(int iIndex)
{
	while (1 < iIndex)
	{
		SegTree[iIndex / 2] *= SegTree[iIndex] % iMod;
		--iIndex;
	}
}

void ChangeValue(int iIndex, long long iValue)
{
	SegTree[iIndex] = iValue;

	while (1 < iIndex)
	{
		iIndex = iIndex / 2;
		SegTree[iIndex] = SegTree[iIndex * 2] % iMod * SegTree[iIndex * 2 + 1] % iMod;
	}
}

long long GetPartMul(int iStart, int iEnd)
{
	long long lPartMul = 1;

	while (iStart <= iEnd)
	{
		if (iStart % 2 == 1)
			lPartMul = lPartMul * SegTree[iStart] % iMod;
		if (iEnd % 2 == 0)
			lPartMul = lPartMul * SegTree[iEnd] % iMod;

		iStart = (iStart + 1) / 2;
		iEnd = (iEnd - 1) / 2;
	}
	
	return lPartMul;
}