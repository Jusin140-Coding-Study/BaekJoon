/*
* @title    : 1427번 소드인사이드(실버5)
* @content  : 선택정렬
* @author   : 손동찬
* @date     : 240711
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string strNum;
    cin >> strNum;
    vector<int> vNums;
    for (int i = 0; i < strNum.size(); ++i)
        vNums.push_back(strNum[i] - '0');
    
    for (int i = 0; i < vNums.size(); ++i)
    {
        int iMaxIndex = i;
        for (int j = i; j < vNums.size(); ++j)
        {
            if(vNums[j] > vNums[iMaxIndex])
               iMaxIndex = j;
        }
        swap(vNums[i], vNums[iMaxIndex]);
        cout << vNums[i];
    }


    return 0;
}