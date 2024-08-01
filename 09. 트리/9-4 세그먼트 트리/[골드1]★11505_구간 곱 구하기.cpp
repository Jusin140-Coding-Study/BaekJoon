#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int iMod = 1'000'000'007;
static vector<long long> SegTree;
void MakeSegTree(int iIndex);
void ChangeValue(int iIndex, long long iValue);
long long GetPartMul(int iStart, int iEnd);

// ���׸�Ʈ Ʈ��
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; int M; int K;
	cin >> N >> M >> K;

	int iTreeHeight = 0;
	int iNumLength = N;

	// Ʈ���� ���̸� ���մϴ�.
	while (0 != iNumLength)
	{
		iNumLength /= 2;
		++iTreeHeight;
	}

	// Ʈ�� �迭�� ũ�⸦ ���մϴ�.
	int iTreeSize = (int)pow(2, iTreeHeight + 1);
	int iLeafNodeStartIndex = iTreeSize / 2;
	
	SegTree = vector<long long>(iTreeSize + 1, 1);

	// ���� ����� ���� ä��ϴ�.
	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin >> SegTree[i];

	// ���׸�Ʈ Ʈ���� ����ϴ�.
	MakeSegTree(iTreeSize - 1);

	// ���Ǹ� �޽��ϴ�.
	for (int i = 0; i < M + K; ++i)
	{
		long long a, s, e;
		cin >> a >> s >> e;

		if (1 == a)
		{
			// ���� �����մϴ�.
			s = s + iLeafNodeStartIndex - 1;
			ChangeValue(s, e);
		}
		else
		{
			// �������� ����մϴ�.
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