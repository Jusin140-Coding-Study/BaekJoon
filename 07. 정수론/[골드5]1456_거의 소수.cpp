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

	// �����佺�׳׽��� ü
	for (int i = 2; i < Size; ++i)
	{
		if (false == V[i]) continue;

		for (int j = 2 * i; j < Size; j += i)
			V[j] = false;
	}

	for(int num = 2; num < Size; ++num)
	{
		// �Ҽ����
		if (true == V[num])
		{
			long long Temp = num;

			// B�� � �Ҽ��� �������� ��, A/�Ҽ� �� B/�Ҽ� ���� �ȿ� ���´ٸ� Result�� ������Ų��.
			// num^k <= B
			//     ��
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