#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int Max(0); double Result(0);

	cin >> N;
	vector<double> Scores(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> Scores[i];

		if (Scores[i] > Max)
			Max = Scores[i];
	}

	for (int i = 0; i < N; ++i)
	{
		Scores[i] = Scores[i] / Max * 100.0;
		Result += Scores[i];
	}

	cout << Result / N;
}