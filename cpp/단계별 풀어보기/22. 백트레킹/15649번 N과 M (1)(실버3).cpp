/*
* @title    : 15649�� N�� M (1)(�ǹ�3)
* @content  : ��Ʈ��ŷ
* @author   : �յ���
* @date     : 240904
* @time     : 20 ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <deque>

using namespace std;

int N, M;
bool Used[9] = {false, };
deque<int> Nums;

void DFS(int Count)
{
	if (Count >= M)
	{
		int num;
		for (int i = 0; i < M; ++i)
		{
			num = Nums.front();
			cout << num << " ";
			Nums.pop_front();
			Nums.push_back(num);
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Used[i])
			continue;

		Nums.push_back(i);
		Used[i] = true;
		DFS(Count + 1);
		Used[i] = false;
		Nums.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	DFS(0);

	return 0;
}
