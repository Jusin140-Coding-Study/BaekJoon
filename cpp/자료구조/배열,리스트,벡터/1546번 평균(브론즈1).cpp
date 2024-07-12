/*
* @title    : 1546�� ���(�����1)
* @content  :
* @author   : �յ���
* @date     : 240708
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int N;
	cin >> N;
	vector<int> v;
	int iMax = 0;

	for (int i = 0; i < N; ++i) {
		int iNum;
		cin >> iNum;
		v.push_back(iNum);
		iMax = max(iNum, iMax);
	}

	int iSum = 0;
	for (int& score : v) iSum += score;
	
	float fResult = ((iSum * 100.f) / iMax) / N;
	
	cout << fResult;
}