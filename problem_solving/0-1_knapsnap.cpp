#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& weights, vector<int>& values, int capacity, int n){
        if(n==0 || capacity==0){
            return 0;
        }
        int ind= n-1;
        int first, second;
        int ans {0};
        if(capacity<weights[ind]){
            ans=helper(weights,values,capacity,n-1);
        }
        else{
            first = helper(weights,values,capacity,n-1);
            second = values[ind] + helper(weights,values,capacity-weights[ind],n-1);
            ans = max(first,second);
        }
        return ans;
        

    }


    int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
        return helper(weights,values,capacity,values.size());






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