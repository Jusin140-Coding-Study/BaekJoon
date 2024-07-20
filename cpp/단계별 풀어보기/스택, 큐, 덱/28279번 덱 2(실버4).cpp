/*
* @title    : 28279번 덱 2(실버4)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240720
* @time     : 188 ms
* @memory   : 6304 KB
* @state    : 완료
*/
#include <iostream>
#include <deque>

using namespace std;

void Order(int _iOrder, int _iNum, deque<int>& _deqNums)
{
	switch (_iOrder)
	{
	case 1:
		_deqNums.push_front(_iNum);
		break;
	case 2:
		_deqNums.push_back(_iNum);
		break;
	case 3:
		if (_deqNums.empty())
			cout << "-1\n";
		else
		{
			cout << _deqNums.front() <<"\n";
			_deqNums.pop_front();
		}
		break;
	case 4:
		if (_deqNums.empty())
			cout << "-1\n";
		else
		{
			cout << _deqNums.back() << "\n";
			_deqNums.pop_back();
		}
		break;
	case 5:
		cout << _deqNums.size() << "\n";
		break;
	case 6:
		if (_deqNums.empty()) 
			cout << "1\n";
		else
			cout << "0\n";
		break;
	case 7:
		if (_deqNums.empty())
			cout << "-1\n";
		else
			cout << _deqNums.front() << "\n";
		break;
	case 8:
		if (_deqNums.empty())
			cout << "-1\n";
		else
			cout << _deqNums.back() << "\n";
		break;

	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> deqNums;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int iOrder = 0, iNum = 0;
		cin >> iOrder;
		if(iOrder == 1 || iOrder == 2)
			cin >> iNum;

		Order(iOrder, iNum, deqNums);
	}

	return 0;
}
