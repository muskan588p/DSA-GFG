#include <bits/stdc++.h>
using namespace std;

int maxCandyProfit(vector<int>& candy, int k) {
    priority_queue<int> maxHeap;

    for (int c : candy) {
        maxHeap.push(c);
    }

    int profit = 0;
    const int MOD = 1e9 + 7;

    while (k-- && !maxHeap.empty()) {
        int maxCandies = maxHeap.top();
        maxHeap.pop();
        profit = (profit + maxCandies) % MOD;

        if (maxCandies - 1 > 0) {
            maxHeap.push(maxCandies - 1);
        }
    }

    return profit;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> candy(N);
        for (int i = 0; i < N; ++i) {
            cin >> candy[i];
        }

        int K;
        cin >> K;

        cout << maxCandyProfit(candy, K) << endl;
    }

    return 0;
}

You own a candy store in which N different types of candies are available, and each type of candy is kept in a separate jar. Now, given an array candy, where candy[i] denotes the number of candies left 
in the i'th jar. Suppose, there are K people standing outside your store, and you need to sell exactly one candy to each of them in such a way that your profit is maximum. The cost of each candy is equal to 
the number of candies left in the jar it belongs to.

Example 1: N = 3 candy = \{1, 2, 1\} , k = 2
Sell one candy from the middle jar to the first person and earn 2 rupees, then all the jars will contain only one candy, i.e. candy = \{1, 1, 1\} . Now, sell one candy to the second person and earn 1 more rupee.
Therefore, the maximum profit earned = 2 + 1 = 3 rupees.

Example 2: N = 2 candy = \{1, 4\} K = 3

To earn maximum profit, sell candies from the second jar only to all the people. The profit would be 4 + 3 + 2 = 9
Input Format
First line of input contain T = number of test cases.

Each test case contains three lines:

First line will contain an integer N, denoting the type of candies available. Second line will contain N space separated integers, denoting the number of canc Third line will contain an integer K, 
denoting the number of people
