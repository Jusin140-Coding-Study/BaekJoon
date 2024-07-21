/*
* @title    : 18258번 큐 2(실버4)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240717
* @time     : 424 ms
* @memory   : 10424 KB
* @state    : 완료
*/
#include <iostream>
#include <queue>

using namespace std;

void Order(queue<int>& _que, string _strOrder, int _iNum)
{
	if (_strOrder == "push")
		_que.push(_iNum);
	
	else if (_strOrder == "pop")
	{
		if (_que.empty()) cout << "-1\n";
		else
		{
			cout << _que.front() <<"\n";
			_que.pop();
		}
	}
	else if (_strOrder == "size")
		cout << _que.size() << "\n";

	
	else if (_strOrder == "empty")
	{
		if (_que.empty()) cout << "1\n";
		else cout << "0\n";

	}
	else if (_strOrder == "front")
	{
		if (_que.empty()) cout << "-1\n";
		else
			cout << _que.front() << "\n";
	}
	else if (_strOrder == "back")
	{
		if (_que.empty()) cout << "-1\n";
		else
			cout << _que.back() << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> que;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string strOrder;
		cin >> strOrder;
		int iNum = 0;
		if (strOrder == "push")
			cin >> iNum;
		
		Order(que, strOrder, iNum);
	}

	return 0;
}
