#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& v, int left, int right);
int partion(vector<int>& v, int start, int end);
void centerquicksort(vector<int>& v, int start, int end, int K);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int K(0);
	cin >> N >> K;

	vector<int> V(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> V[i];

	centerquicksort(V, 0, N - 1, K - 1);
	cout << V[K - 1];
}

void centerquicksort(vector<int>& v, int start, int end, int K)
{
	if (start >= end) return;

	int pivot = partion(v, start, end);

	if (pivot == K)
	{
		return;
	}
	else if (pivot > K)
	{
		centerquicksort(v, start, pivot, K);
	}
	else
	{
		centerquicksort(v, pivot + 1, end, K);
	}
}

int partion(vector<int>& v, int start, int end)
{
	if (start + 1 == end)
	{
		if (v[start] > v[end])
			swap(v, start, end);
		return end;
	}

	int low = start;
	int high = end;



	int pivot = v[(start + end) / 2];

	while (true)
	{
		while (pivot > v[low]) low++;
		while (pivot < v[high] && low < high) high--;

		if (low < high)
		{
			swap(v, low, high);
		}
		else
		{
			return high;
		}
	}
}

void swap(vector<int>& v, int left, int right)
{
	int temp = v[right];
	v[right] = v[left];
	v[left] = temp;
}