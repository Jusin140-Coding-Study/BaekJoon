/*
* @title    : 2529번 부등호(실버1)
* @content  : 브루트 포스 - 순열
* @author   : 손동찬
* @date     : 240822
* @time     : 16 ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;
	char c[10];
	for (int i = 1; i <= K; ++i)
		cin >> c[i];

	vector<int> Nums(10);

	for (int i = 0; i <= 9; ++i)
		Nums[i] = 9-i;

	while (1)
	{
		bool b = true;
		for (int i = 1; i <= K; ++i)
		{
			if ((c[i] == '<' && Nums[i - 1] > Nums[i]) || (c[i] == '>' && Nums[i - 1] < Nums[i]))
			{
				b = false;
				break;
			}
		}
		if(b)
		{
			for (int i = 0; i <= K; ++i)
				cout << to_string(Nums[i]);
			
			cout << "\n";
			break;
		}

		if (!prev_permutation(Nums.begin(), Nums.end()))
			break;
	}

	for (int i = 0; i <= 9; ++i)
		Nums[i] = i;

	while (1)
	{
		bool b = true;
		for (int i = 1; i <= K; ++i)
		{
			if ((c[i] == '<' && Nums[i - 1] > Nums[i]) || (c[i] == '>' && Nums[i - 1] < Nums[i]))
			{
				b = false;
				break;
			}
		}
		if (b)
		{
			for (int i = 0; i <= K; ++i)
				cout << to_string(Nums[i]);
		
			break;
		}

		if (!next_permutation(Nums.begin(), Nums.end()))
			break;
	}

	return 0;
}
