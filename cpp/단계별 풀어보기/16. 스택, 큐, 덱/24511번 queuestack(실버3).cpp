/*
* @title    : 24511번 queuestack(실버3)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240721
* @time     : 44 ms
* @memory   : 2944 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> vecType(N + 1);
	deque<int> deqNums;
	for (int i = 1; i <= N; ++i)
		cin >> vecType[i];
	
	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;
		if (!vecType[i])
			deqNums.push_back(num);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int C;
		cin >> C;
		deqNums.push_front(C);
		cout << deqNums.back() << " ";
		deqNums.pop_back();
	}

	return 0;
}
