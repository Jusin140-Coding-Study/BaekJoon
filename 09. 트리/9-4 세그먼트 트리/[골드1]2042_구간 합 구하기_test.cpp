#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> segTree;
void MakeSegTree();
void ChangeValue(long a, long b);
long GetPartSum(int a, int b);

// 세그먼트 트리
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M; int K;
	cin >> N >> M >> K;
	
	int iTreeHeight = 0;
	int iNodeNum = N;

	while (iNodeNum != 0)
	{
		iNodeNum /= 2;
		iTreeHeight++;
	}

	int iTreeSize = pow(2, iTreeHeight + 1);
	segTree = vector<long>(iTreeSize + 1, 0);

	int iLeafNodeStartIndex = iTreeSize / 2;

	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin>> segTree[i];

	MakeSegTree();

	for (int i = 0; i < M + K; ++i)
	{
		int iQuestion;
		long a, b;

		cin >> iQuestion >> a >> b;

		if (1 == iQuestion)
		{
			// a를 b로 바꾸기
			int iLeafIndex = a + iLeafNodeStartIndex - 1;
			ChangeValue(iLeafIndex, b);
		}
		else
		{
			// a부터 b까지 합 구하기
			int iLeafStartIndex = a + iLeafNodeStartIndex - 1;
			int iLeafEndIndex = b + iLeafNodeStartIndex - 1;
			
			long lPartSum = GetPartSum(iLeafStartIndex, iLeafEndIndex);
			cout << lPartSum << "\n";
		}
	}
}

void MakeSegTree()
{
	int iIndex = segTree.size() - 1;

	while (0 < iIndex)
	{
		segTree[iIndex / 2] += segTree[iIndex];
		--iIndex;
	}
}

void ChangeValue(long a, long b)
{
	long lDiff = b - segTree[a];

	while (0 < a)
	{
		segTree[a] = segTree[a] + lDiff;
		a /= 2;
	}
}

long GetPartSum(int a, int b)
{
	long lResult = 0;

	while (a <= b)
	{
		if (a % 2 == 1)
			lResult += segTree[a];
		if (b % 2 == 0)
			lResult += segTree[b];

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}

	return lResult;
}