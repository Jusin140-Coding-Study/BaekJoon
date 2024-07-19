/*
* @title    : 11720번 숫자의합(브론즈4)
* @content  : 
* @author   : 손동찬
* @date     : 240708
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N = 0;
    string numbers = "";
    cin >> N;
    cin >> numbers;

    int Sum = 0;

    for (int i = 0; i < numbers.size(); ++i)
        Sum += (numbers[i] - '0');

    cout << Sum << "\n";
}