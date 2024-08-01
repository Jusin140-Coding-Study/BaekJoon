#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> SegTree;
void MakeSegTree(int iIndex);
void ChangeValue(int iIndex, long iValue);
long GetPartSum(int iStart, int iEnd);

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

	// 트리 배열의 크기를 구합니다. (0번 인덱스는 사용 안함)
	int iTreeSize = (int)pow(2, iTreeHeight + 1);
	SegTree = vector<long>(iTreeSize + 1, 0);

	// 리프 노드의 시작 인덱스를 구합니다.
	int iLeafNodeStartIndex = iTreeSize / 2;

	// 리프 노드 인덱스를 채워줍니다.
	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin >> SegTree[i];

	MakeSegTree(iTreeSize - 1);

	// 질의를 받습니다.
	for (int i = 0; i < M + K; ++i)
	{
		long a, s, e;
		cin >> a >> s >> e;

		if (1 == a)
		{
			s = s + iLeafNodeStartIndex - 1;

			// 데이터 변경
			ChangeValue(s, e);
		}
		else
		{
			// 입력받은 인덱스를 리프노드 인덱스로 변환
			s = s + iLeafNodeStartIndex - 1;
			e = e + iLeafNodeStartIndex - 1;

			// 구간합 구하기
			cout << GetPartSum(s, e) << "\n";
		}
	}

	return 0;
}

// 세그먼트 트리를 만듭니다.
void MakeSegTree(int iIndex)
{
	// 구간합이므로 자식노드 두개의 값을 부모노드에 더해줍니다.
	while (1 < iIndex)
	{
		SegTree[iIndex / 2] += SegTree[iIndex];
		--iIndex;
	}
}

// 트리의 데이터를 변경합니다.
void ChangeValue(int iIndex, long iValue)
{
	// 현재 값과 변경될 값의 차이를 구합니다.
	long iDiff = iValue - SegTree[iIndex];

	// 루트노드까지 변경해주어야 합니다.
	while (1 <= iIndex)
	{
		SegTree[iIndex] += iDiff;
		iIndex /= 2;
	}
}

// 구간합을 구한다.
long GetPartSum(int iStart, int iEnd)
{
	long iSum = 0;

	while (iStart <= iEnd)
	{
		// Start는 나머지가 1일 때, 선택됨.
		if (iStart % 2 == 1)
			iSum += SegTree[iStart];

		// End는 나머지가 0일 때, 선택됨.
		if (iEnd % 2 == 0)
			iSum += SegTree[iEnd];
		
		iStart = (iStart + 1) / 2;
		iEnd = (iEnd - 1) / 2;
	}

	return iSum;
}