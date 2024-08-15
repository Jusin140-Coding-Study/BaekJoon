#include <iostream>
#include <vector>
using namespace std;

static long D[21][21][21];
long W(int a, int b, int c);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 0; int b = 0; int c = 0;

	while (true)
	{
		cin >> a >> b >> c;
		if (-1 == a && -1 == b && -1 == c) { break; }
		
		cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << "\n";
	}

	return 0;
}

long W(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return W(20, 20, 20);
	}
	else if (D[a][b][c])
	{
		return D[a][b][c];
	}
	else if (a < b && b < c)
	{
		D[a][b][c] = W(a, b, c-1) + W(a, b-1, c-1) - W(a, b-1, c);
	}
	else
	{
		D[a][b][c] = W(a-1, b, c) + W(a-1, b-1, c) + W(a-1, b, c-1) - W(a-1, b-1, c-1);
	}

	return D[a][b][c];
}