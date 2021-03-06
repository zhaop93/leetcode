#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

/**
 * https://leetcode.com/problems/3sum/description/
 * 第一层循环先确定第一个数
 *    第二层 两个指针一个从头开始，一个从尾开始，分别表示第二个数 和 第三个数
 *    如果三个数相等，则放入集合中，为了防止重复
 *    如果三个数和小于0，说明需要增大一下，则移动第二个数指针
 *    如果三个数和大于0，说明需要减小一下，则移动第三个数指针
class Solution {
    public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int s = i + 1;
            int e = n - 1;
            int target = 0 - nums[i];
            while (s < e) {
                if (nums[s] + nums[e] == target) {
                    res.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s + 1] == nums[s]) {
                        s++;
                    }
                    while (s < e && nums[e - 1] == nums[e]) {
                        e--;
                    }
                    s++;
                    e--;
                }
                if (nums[s] + nums[e] > target) {
                    e--;
                }
                if (nums[s] + nums[e] < target) {
                    s++;
                }
            }
        }
        return res;
    }
};
*/

/*
class Solution {
    public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s, e;
        vector< vector<int> > res;
        set< vector<int> > reSet;
        for (int i = 0; i < n; i++) {
            s = i + 1;
            e = n - 1;
            while (s < e) {
                if (nums[i] + nums[s] + nums[e] == 0) {
                    vector<int> record;
                    record.push_back(nums[i]);
                    record.push_back(nums[s]);
                    record.push_back(nums[e]);
                    reSet.insert(record);
                    s++;
                } else if (nums[i] + nums[s] + nums[e] < 0) {
                    s++;
                } else {
                    e--;
                }
            }
        }
        set< vector<int> >::iterator it;
        for (it = reSet.begin(); it != reSet.end(); it++) {
            res.push_back(*it);
        }

        return res;
    }
};
*/

class Solution {
    public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i <= n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};


int main() {
    Solution* solution = new Solution();
    int n;
    vector<int> nums;
    while (cin >> n) {
        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            nums.push_back(t);
        }
        vector<vector<int> > res = solution->threeSum(nums);
        for (int i = 0; i < (int)res.size(); i++) {
            for (int j = 0; j < (int) res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }

    }


    return 0;
}
