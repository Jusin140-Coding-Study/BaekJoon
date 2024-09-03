/*
* @title    : 15652�� N�� M (4)(�ǹ�3)
* @content  : ��Ʈ��ŷ
* @author   : �յ���
* @date     : 240904
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <deque>

using namespace std;

int N, M;
deque<int> Nums;

void DFS(int Count, int Start)
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

	for (int i = Start; i <= N; ++i)
	{
		Nums.push_back(i);
		DFS(Count + 1, i );
		Nums.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(0, 1);

	return 0;
}
