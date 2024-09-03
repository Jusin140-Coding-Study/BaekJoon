/*
* @title    : 15651�� N�� M (3)(�ǹ�3)
* @content  : ��Ʈ��ŷ
* @author   : �յ���
* @date     : 240904
* @time     : 316 ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <deque>

using namespace std;

int N, M;
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
		Nums.push_back(i);
		DFS(Count + 1);
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
