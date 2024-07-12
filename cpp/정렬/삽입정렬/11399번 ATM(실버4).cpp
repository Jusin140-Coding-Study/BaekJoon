/*
* @title    : 11399번 ATM(실버4)
* @content  : 삽입정렬
* @author   : 손동찬
* @date     : 240711
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];

    for (int i = 1; i < N; ++i)
    {
        int iInsertIndex = i;
        for (int j = i-1; j >= 0; --j)
        {
            if (v[j] <= v[i]) 
                break;        

            iInsertIndex = j;
        }

        int temp = v[i];
        for (int j = i; j > iInsertIndex ; --j)
            v[j] = v[j - 1];
        
        v[iInsertIndex] = temp;
    }

    int iResult = 0;
    for (int i = 0; i < N; ++i)
        iResult += v[i] * (N - i);
    
    cout << iResult << "\n";
    
    return 0;
}