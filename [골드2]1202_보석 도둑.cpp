#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 가격, 무게 순서
typedef pair<int, int> jewel;
vector<jewel> vecJewel;
vector<int> vecBags;
priority_queue<int, vector<int>, less<>> pQTemp;

bool CompareDescending(jewel a, jewel b)
{
	if(a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int K = 0; int Result = 0;
	cin >> N >> K;

	vecJewel = vector<jewel>(N, make_pair(-1, -1));
	vecBags = vector<int>(K, 0);

	for (int i = 0; i < N; ++i)
	{
		int M = 0;
		int V = 0;
		cin >> M >> V;

		vecJewel[i] = (make_pair(M, V));
	}

	for (int i = 0; i < K; ++i)
	{
		int C = 0;
		cin >> C;

		vecBags[i] = C;
	}

	sort(vecBags.begin(), vecBags.end());
	sort(vecJewel.begin(), vecJewel.end(), CompareDescending);

	int iJewelIndex = 0;

	for (int i = 0; i < K; ++i)
	{
		while (iJewelIndex < N && vecJewel[iJewelIndex].first <= vecBags[i])
		{
			pQTemp.push(vecJewel[iJewelIndex].second);
			++iJewelIndex;
		}

		if (!pQTemp.empty())
		{
			Result += pQTemp.top();
			pQTemp.pop();
		}
	}

	cout << Result << "\n";

	return 0;
}