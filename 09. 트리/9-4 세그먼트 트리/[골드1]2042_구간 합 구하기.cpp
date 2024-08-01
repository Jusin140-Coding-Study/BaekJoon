#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> SegTree;
void MakeSegTree(int iIndex);
void ChangeValue(int iIndex, long iValue);
long GetPartSum(int iStart, int iEnd);

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

	// Ʈ�� �迭�� ũ�⸦ ���մϴ�. (0�� �ε����� ��� ����)
	int iTreeSize = (int)pow(2, iTreeHeight + 1);
	SegTree = vector<long>(iTreeSize + 1, 0);

	// ���� ����� ���� �ε����� ���մϴ�.
	int iLeafNodeStartIndex = iTreeSize / 2;

	// ���� ��� �ε����� ä���ݴϴ�.
	for (int i = iLeafNodeStartIndex; i < iLeafNodeStartIndex + N; ++i)
		cin >> SegTree[i];

	MakeSegTree(iTreeSize - 1);

	// ���Ǹ� �޽��ϴ�.
	for (int i = 0; i < M + K; ++i)
	{
		long a, s, e;
		cin >> a >> s >> e;

		if (1 == a)
		{
			s = s + iLeafNodeStartIndex - 1;

			// ������ ����
			ChangeValue(s, e);
		}
		else
		{
			// �Է¹��� �ε����� ������� �ε����� ��ȯ
			s = s + iLeafNodeStartIndex - 1;
			e = e + iLeafNodeStartIndex - 1;

			// ������ ���ϱ�
			cout << GetPartSum(s, e) << "\n";
		}
	}

	return 0;
}

// ���׸�Ʈ Ʈ���� ����ϴ�.
void MakeSegTree(int iIndex)
{
	// �������̹Ƿ� �ڽĳ�� �ΰ��� ���� �θ��忡 �����ݴϴ�.
	while (1 < iIndex)
	{
		SegTree[iIndex / 2] += SegTree[iIndex];
		--iIndex;
	}
}

// Ʈ���� �����͸� �����մϴ�.
void ChangeValue(int iIndex, long iValue)
{
	// ���� ���� ����� ���� ���̸� ���մϴ�.
	long iDiff = iValue - SegTree[iIndex];

	// ��Ʈ������ �������־�� �մϴ�.
	while (1 <= iIndex)
	{
		SegTree[iIndex] += iDiff;
		iIndex /= 2;
	}
}

// �������� ���Ѵ�.
long GetPartSum(int iStart, int iEnd)
{
	long iSum = 0;

	while (iStart <= iEnd)
	{
		// Start�� �������� 1�� ��, ���õ�.
		if (iStart % 2 == 1)
			iSum += SegTree[iStart];

		// End�� �������� 0�� ��, ���õ�.
		if (iEnd % 2 == 0)
			iSum += SegTree[iEnd];
		
		iStart = (iStart + 1) / 2;
		iEnd = (iEnd - 1) / 2;
	}

	return iSum;
}