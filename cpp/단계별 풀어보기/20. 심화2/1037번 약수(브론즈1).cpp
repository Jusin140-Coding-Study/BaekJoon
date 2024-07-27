/*
* @title    : 1037번 약수(브론즈1)
* @content  : 심화 2
* @author   : 손동찬
* @date     : 240723
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	vector<int> vecNums(num);
	for (int i = 0; i < num; ++i)
		cin >> vecNums[i];
	
	if (num == 1)
		cout << vecNums[0] * vecNums[0];
	else
	{
		sort(vecNums.begin(), vecNums.end());
		cout << vecNums[0] * vecNums[vecNums.end()- vecNums.begin()-1];
	}
	return 0;
}
