#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 1;
    int size = nums.size() / 2;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) answer++;
    }
    if (size < answer) answer = size;

    return answer;
}