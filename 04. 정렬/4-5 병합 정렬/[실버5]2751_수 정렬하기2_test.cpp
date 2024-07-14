#include <iostream>
#include <vector>
using namespace std;

void mergesort(int start, int end);
static vector<int> V;
static vector<int> Temp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0);
	cin >> N;

	V = vector<int>(N + 1, 0);
	Temp = vector<int>(N + 1, 0);

	for (int i = 0; i < N; ++i)
		cin >> V[i];

	mergesort(1, N);

	for (int i = 0; i < N; ++i)
		cout << V[i] << "\n";
}

void mergesort(int start, int end)
{
	if (end - start < 1)
		return;

	int middle = start + (end - start) / 2;

	mergesort(start, middle);
	mergesort(middle + 1, end);

	// 임시 배열 저장
	for (int i = start; i <= end; ++i)
		Temp[i] = V[i];

	int k = start;
	int Index1 = start;
	int Index2 = middle + 1;

	while (Index1 <= middle && Index2 <= end)
	{
		// 왼쪽 그룹의 값이 더 큰 경우
		if (Temp[Index1] > Temp[Index2])
		{
			V[k] = Temp[Index2];
			k++;
			Index1++;
		}
		// 오른쪽 그룹의 값이 더 큰 경우
		else
		{
			V[k] = Temp[Index1];
			k++;
			Index2++;
		}
	}
	// 한쪽 그룹이 모두 선택된 후 남아있는 값 정리
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