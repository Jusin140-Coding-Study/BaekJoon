/*
* @title    : 11003번 최솟값 찾기(플래티넘5)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 1236 ms
* @memory   : 43588 KB
* @state    : 완료
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