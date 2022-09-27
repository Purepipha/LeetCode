/*
 * LeetCode 35.搜索插入位置
 * url: 
 * Author: Purepipha
 * Create: 2022-09-27 22:57:40
 * Method: https://leetcode.cn/problems/search-insert-position/
 * Time Complex: O(logn)
 * Space Complex: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    vector<int> data{1,3,5,6};
    int target = 5;
    Solution solution;
    auto res = solution.searchInsert(data, target);
    cout << res << endl;
    return 0;
}