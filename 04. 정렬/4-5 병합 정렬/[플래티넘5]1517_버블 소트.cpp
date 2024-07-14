#include <iostream>
#include <vector>
using namespace std;

void mergesort(int start, int end);
static vector<int> V;
static vector<int> Temp;
static long Result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	cin >> N;

	V = vector<int>(N + 1, 0);
	Temp = vector<int>(N + 1, 0);
	Result = 0;

	for (int i = 1; i <= N; ++i)
		cin >> V[i];

	mergesort(1, N);

	cout << Result;
}

void mergesort(int start, int end)
{
	if (end - start < 1)
		return;

	int middle = start + (end - start) / 2;

	mergesort(start, middle);
	mergesort(middle + 1, end);

	for (int i = start; i <= end; ++i)
		Temp[i] = V[i];

	int k = start;
	int Index1 = start;
	int Index2 = middle + 1;

	while (Index1 <= middle && Index2 <= end)
	{
		// ������ �׷��� ���� �� ���� ���
		if (Temp[Index1] > Temp[Index2])
		{
			V[k] = Temp[Index2];

			// ������ �׷��� ���� ���õǴ� ��� ����� ������Ʈ
			Result = Result + Index2 - k;

			k++;
			Index2++;
		}
		// ���� �׷��� ���� �� ���� ���
		else
		{
			V[k] = Temp[Index1];
			k++;
			Index1++;
		}
	}
	// ���� �׷��� ���� ��� ���õ� ��
	while (Index1 <= middle)
	{
		V[k] = Temp[Index1];
		k++;
		Index1++;
	}
	while (Index2 <= end)
	{
		V[k] = Temp[Index2];
		k++;
		Index2++;
	}
}