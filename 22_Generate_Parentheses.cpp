#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        dfs(res, n, n, cur);
        return res;
    }
    void dfs(vector<string>& res, int left, int right, string cur) {
        if (left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            res.push_back(cur);
            return;
        } else {
            if (left > 0) {
                dfs(res, left - 1, right, cur + "(");
            }
            if (right > 0) {
                dfs(res, left, right - 1, cur + ")");
            }
        }
    }
};
/**
 * https://leetcode.com/problems/generate-parentheses/description/
 * 递归
 */
class Solution {
    public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
//        backtrack(res, "", 0, 0, n);
        backtrack(res, "", 0, n);
        return res;
    }

    public:
    void backtrack(vector<string> &res, string cur, int open, int n) {
        if ((int)cur.length() == 2 * n) {
            res.push_back(cur);
            return;
        }
        if (open < n) {
            backtrack(res, cur + "(", open + 1, n);
        } else {
           backtrack(res, cur + ")", open, n);
        }
    }


    public:
    void backtrack(vector<string> &res, string cur, int open, int close, int n) {
        if ((int)cur.length() == 2 * n) {
            res.push_back(cur);
            return;
        }
        //如果open < n, 表示open还能放，那就放open
        if (open < n) {
            backtrack(res, cur + "(", open + 1, close, n);
        }
        //在open数量限定下放close
        if (close < open) {
            backtrack(res, cur + ")", open, close + 1, n);
        }

        return;
    }
};
int main() {

    return 0;
}
