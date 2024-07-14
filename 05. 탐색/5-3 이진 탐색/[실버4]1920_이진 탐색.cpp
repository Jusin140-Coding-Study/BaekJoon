#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsExist(int num, vector<int>& v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;

	cin >> N;
	vector<int> V(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> V[i];

	// 데이터 정렬
	sort(V.begin(), V.end());

	// 찾고자하는 목표 정수 배열
	cin >> M;
	vector<int> D(M, 0);

	for (int i = 0; i < M; ++i)
	{
		cin >> D[i];

		if (IsExist(D[i], V))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}

bool IsExist(int num, vector<int>& v)
{
	int start = 0;
	int end = v.size() - 1;

	while (start <= end)
	{
		int mIndex = (start + end) / 2;
		int mValue = v[mIndex];

		if (num < mValue)
		{
			end = mIndex - 1;
		}
		else if (num > mValue)
		{
			start = mIndex + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}