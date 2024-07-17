#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long Min = 0; long Max = 0;
	int Result = 0;
	cin >> Min >> Max;

	vector<bool> V(Max - Min + 1, false);

	for (long i = 2; i * i <= Max; ++i)
	{
		long pow = i * i;
		long start = Min / pow;

		if (Min % pow != 0)
			start++;

		for (long j = start; j * pow <= Max; ++j)
			V[(int)(j * pow) - (int)Min] = true;
	}

	for (const auto& iter : V)
	{
		if (!iter)
			Result++;
	}

	cout << Result;
}