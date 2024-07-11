#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N(0); int Count(0);

	cin >> N;
	vector<int> Numbers(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> Numbers[i];
	}

	sort(Numbers.begin(), Numbers.end());

	for (int k = 0; k < N; ++k)
	{
		int Temp = Numbers[k];
		int Left = 0;
		int Right = N - 1;

		while (Left < Right)
		{
			if (Numbers[Left] + Numbers[Right] == Temp)
			{
				if (Left != k && Right != k)
				{
					Count++;
					break;
				}
				else if (Left == k)
				{
					Left++;
				}
				else if (Right == k)
				{
					Right--;
				}
			}
			else if (Numbers[Left] + Numbers[Right] < Temp)
			{
				Left++;
			}
			else if (Numbers[Left] + Numbers[Right] > Temp)
			{
				Right--;
			}
		}
	}

	cout << Count;
}