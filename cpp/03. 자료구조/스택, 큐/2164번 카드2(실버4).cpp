/*
* @title    : 2164번 카드2(실버4)
* @content  : 스택, 큐
* @author   : 손동찬
* @date     : 240710
* @time     : 4 ms
* @memory   : 4156 KB
* @state    : 완료
*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	queue<int> que;
	for (int i = 1; i <= N; ++i)
		que.push(i);
	
	while (que.size() > 1)
	{
		que.pop();	
		que.push(que.front());
		que.pop();
	}

	cout << que.front() <<"\n";

	return 0;
}