#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& v, int left, int right);
int partion(vector<int>& v, int start, int end);
void leftquicksort(vector<int>& v, int start, int end, int K);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int K(0);
	cin >> N >> K;

	vector<int> V(N, 0);
	for(int i = 0; i < N; ++i)
		cin >> V[i];

	leftquicksort(V, 0, N - 1, K - 1);
	cout << V[K - 1];
}

void leftquicksort(vector<int>& v, int start, int end, int K)
{
	int pivot = partion(v, start, end);

	if (pivot == K)
	{
		return;
	}
	else if (pivot > K)
	{
		leftquicksort(v, start, pivot - 1, K);
	}
	else
	{
		leftquicksort(v, pivot + 1, end, K);
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

	int low = start + 1;
	int high = end;

	int Middle = (start + end) / 2;
	swap(v, start, Middle);

	int pivot = v[start];

	while (low <= high)
	{
		while (pivot > v[low] && low <= end) low++;
		while (pivot < v[high]&& high >= start + 1) high--;

		if (low < high) swap(v, low++, high--);
		else break;
	}

	v[start] = v[high];
	v[high] = pivot;

	return high;
}

void swap(vector<int>& v, int left, int right)
{
	int temp = v[right];
	v[right] = v[left];
	v[left] = temp;
}