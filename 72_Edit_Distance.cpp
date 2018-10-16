#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m + 1][n + 1];
		dp[0][0] = 0;
		for (int i = 1; i <= m; i++) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= n; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j] + 1), dp[i][j - 1] + 1);
				} else {
					dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
				}
			}
		}
		
		return dp[m][n];
    }
};

int main() {
	

}
