#include <iostream>
#include <vector>
using namespace std;

bool IsPrime(int num);
void DFS(int num, int size);
static int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int N = 0;
	cin >> N;

	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);
}

// 소수 판별 함수
bool IsPrime(int num)
{
	for (int i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

// DFS 함수
void DFS(int num, int size)
{
	if (size == N && IsPrime(num))
	{
		cout << num << "\n";
		return;
	}

	for (int i = 1; i < 10; ++i)
	{
		// 짝수라면 2를 무조건 약수로 가지므로 탐색할 필요 없음
		if (i % 2 == 0) continue;

		if (IsPrime(num * 10 + i))
			DFS(num * 10 + i, size + 1);
	}
}