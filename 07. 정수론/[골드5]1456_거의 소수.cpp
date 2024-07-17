#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A = 0; long long B = 0; int Result = 0;
	cin >> A >> B;

	long long Size = sqrt(B);
	vector<bool> V(Size + 1, true);
	V[0] = false;
	V[1] = false;

	// 에라토스테네스의 체
	for (int i = 2; i < Size; ++i)
	{
		if (false == V[i]) continue;

		for (int j = 2 * i; j < Size; j += i)
			V[j] = false;
	}

	for(int num = 2; num < Size; ++num)
	{
		// 소수라면
		if (true == V[num])
		{
			long long Temp = num;

			// B를 어떤 소수로 나누었을 때, A/소수 와 B/소수 범위 안에 들어온다면 Result를 증가시킨다.
			// num^k <= B
			//     ↓
			// num <= B / num^(k-1)
			while ((double)num <= double(B) / double(Temp))
			{
				if (double(num) >= double(A) / double(Temp))
					Result++;

				Temp = Temp * num;
			}
		}
	}

	cout << Result;

	return 0;
}