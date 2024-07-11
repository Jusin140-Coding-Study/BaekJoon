#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int Start(1); int End(1); int Sum(1);
	int N(0); int Result(1);
	cin >> N;

	while (End != N)
	{
		if (Sum == N)
		{
			Result++;

			Sum = Sum - Start;
			Start++;
		}
		else if (Sum < N)
		{
			End++;
			Sum = Sum + End;
		}
		else if (Sum > N)
		{
			Sum = Sum - Start;
			Start++;
		}
	}

	cout << Result << "\n";
}