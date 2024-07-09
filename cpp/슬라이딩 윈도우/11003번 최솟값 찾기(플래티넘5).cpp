/*
* @title    : 11003�� �ּڰ� ã��(�÷�Ƽ��5)
* @content  :
* @author   : �յ���
* @date     : 240709
* @time     : 1236 ms
* @memory   : 43588 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<pair<int, int>> dq;
	for (int i = 0; i < N; ++i)
	{
		int iNum;
		cin >> iNum;
		while (dq.size() && dq.back().second > iNum)
			dq.pop_back();

		dq.push_back({i,iNum});

		if(L <= i-dq.front().first)
			dq.pop_front();

		cout << dq.front().second << " ";
	}

	return 0;
}