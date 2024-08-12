#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string result = "";
	string first = "";
	string second = "";

	cin >> first >> second;

	vector<vector<int>> LCSArray = vector<vector<int>>(first.size() + 1, vector<int>(second.size() + 1, 0));

	for (int row = 1; row <= first.size(); ++row)
	{
		for (int col = 1; col <= second.size(); ++col)
		{
			if (first[row] == second[col])
			{
				LCSArray[row][col] = LCSArray[row - 1][col - 1] + 1;
			}
			else
			{
				LCSArray[row][col] = max(LCSArray[row - 1][col], LCSArray[row][col - 1]);
			}
		}
	}

	cout << LCSArray[first.size()][second.size()] << "\n";

	//for (int i = 1; i <= first.size(); ++i)
	//{
	//	for (int j = 1; j <= second.size(); ++j)
	//	{
	//		cout << LCSArray[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	int temp = second.size();
	for (int row = first.size(); 1 <= row; --row)
	{
		for (int col = temp; 1 <= col; --col)
		{
			if (LCSArray[row][col] == LCSArray[row - 1][col])
			{
				temp = col;
				break;
			}
			else if (LCSArray[row][col] == LCSArray[row][col - 1])
			{
				continue;
			}
			else
			{
				result = first[row - 1] + result;
			}
		}
	}

	for (auto& ch : result)
		cout << ch;

	return 0;
}