/*
* @title    : 28278번 스택 2(실버4)
* @content  : 스택, 큐, 덱
* @author   : 손동찬
* @date     : 240717
* @time     : 156 ms
* @memory   : 6300 KB
* @state    : 완료
*/
#include <iostream>
#include <stack>

using namespace std;

void Order(stack<int>& _stNums, int _iOrder, int _iNum)
{
	switch (_iOrder)
	{
	case 1 :
		_stNums.push(_iNum);
		break;

	case 2:
		if (_stNums.empty())
			cout << "-1" <<"\n";
		else
		{
			int a = _stNums.top();
			_stNums.pop();
			cout << a << "\n";
		}
		break;

	case 3:
		cout << _stNums.size() << "\n";
		break;

	case 4:
		if (_stNums.empty())
			cout << "1" << "\n";
		else
			cout << "0" << "\n";
		break;

	case 5:
		if (_stNums.empty())
			cout << "-1" << "\n";
		else
			cout << _stNums.top() << "\n";		
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

	int N;
	cin >> N;
	
	stack<int> stNums;
	for (int i = 0; i < N; ++i)
	{
		int iOrder, iNum=0;
		cin >> iOrder;
		if(iOrder == 1)
			cin >> iNum;
		Order(stNums, iOrder, iNum);
	}
	return 0;
}
