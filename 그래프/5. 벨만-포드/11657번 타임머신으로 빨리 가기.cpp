#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Edge;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;
	cin >> iN >> iM;

	long INF = iM * 10000 + 1;

	vector<Edge>	vecEdges(iM);
	vector<long>	vecResult(iN + 1, INF);
	vecResult[1] = 0;

	int iCity1, iCity2, iTime;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iCity1 >> iCity2 >> iTime;
		vecEdges[i] = make_tuple(iCity1, iCity2, iTime);
	}

	Edge eCurEgde;

	for (int i = 0; i < iN -  1; ++i)
	{
		for (int j = 0; j < iM; ++j)
		{
			eCurEgde = vecEdges[j];

			if (vecResult[get<0>(eCurEgde)] == INF)
				continue;

			if (vecResult[get<1>(eCurEgde)] > vecResult[get<0>(eCurEgde)] + get<2>(eCurEgde))
			{
				vecResult[get<1>(eCurEgde)] = vecResult[get<0>(eCurEgde)] + get<2>(eCurEgde);
			}
		}
	}

	bool isCycle = false;

	for (int i = 0; i < iM; ++i)
	{
		eCurEgde = vecEdges[i];

		if (vecResult[get<0>(eCurEgde)] == INF)
			continue;

		if (vecResult[get<1>(eCurEgde)] > vecResult[get<0>(eCurEgde)] + get<2>(eCurEgde))
		{
			isCycle = true;
		}
	}

	if (isCycle)
	{
		cout << -1 << '\n';
		return 0;
	}

	else
	{
		for (int i = 2; i <= iN; ++i)
		{
			if (INF == vecResult[i])
			{
				cout << -1 << '\n';
				continue;
			}

			cout << vecResult[i] << '\n';
		}
	}
}