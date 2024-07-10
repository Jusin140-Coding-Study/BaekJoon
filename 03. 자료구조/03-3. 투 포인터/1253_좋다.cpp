#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums = {};
    int answer = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());

    int start= 0, end = 1, target;

    for (int i = 0; i < N; ++i) {
        
        start = 0;
        end = 1;

        target = nums[i];

        while (start < N) {
       
            if (end >= N || i == start || target < nums[start] + nums[end]) {
                ++start;
                end = start + 1;
            }
            else if (i == end) {
                ++end;
            }
            else if (target == nums[start] + nums[end]) {
                ++answer;
                start = 0;
                end = 1;
                break;
            }else{
                ++end;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}