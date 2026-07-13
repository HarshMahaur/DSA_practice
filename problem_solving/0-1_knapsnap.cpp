#include <bits/stdc++.h>
using namespace std;
// this recursive solution will get time limit exceed solution.
// assumption is we have one copy of each item 
class Solution {
public:
    // int helper(vector<int>& weights, vector<int>& values, int capacity, int n){
    //     if(n==0 || capacity==0){
    //         return 0;
    //     }
    //     int ind= n-1;
    //     int first, second;
    //     int ans {0};
    //     if(capacity<weights[ind]){
    //         ans=helper(weights,values,capacity,n-1);
    //     }
    //     else{
    //         first = helper(weights,values,capacity,n-1);
    //         second = values[ind] + helper(weights,values,capacity-weights[ind],n-1);
    //         ans = max(first,second);
    //     }
    //     return ans;
        

    // }


    int knapsack(vector<int>& weights, vector<int>& values, int W) {
        // return helper(weights,values,capacity,values.size());
        int n = values.size();
        int dp[n+1][W+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(weights[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    int inc= values[i-1] +dp[i-1][j-weights[i-1]];
                    int exc= dp[i-1][j];
                    dp[i][j]= max(inc,exc);
                }

            }


        }
        return dp[n][W];






    }
};

int main() {
    int n;
    cin >> n;

    vector<int> weights(n), values(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int capacity;
    cin >> capacity;

    Solution sol;
    cout << sol.knapsack(weights, values, capacity) << endl;

    return 0;
}

//output
// 5
// 1 2 3 4 5
// 1 2 5 6 7
// 7
// 11 *


// 3
// 10 20 30
// 60 100 120
// 50
// 220 *