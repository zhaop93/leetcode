#include "heads.h"
using namespace std;

class Solution {
    public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        int a = INT_MAX;
        int b = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] < a) {
                a = nums[i];
            } else if (nums[i] < b) {
                b = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {

    return 0;
}
