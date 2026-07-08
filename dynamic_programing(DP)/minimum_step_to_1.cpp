#include <bits/stdc++.h>
using namespace std;

// memorization solution
int helper(int n,int *ans){
    if(n==1){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x= helper(n-1,ans);
    int y{INT_MAX};
    int z{INT_MAX};
    if(n%2==0){
        y= helper(n/2,ans);
    }
    if(n%3==0){
        z= helper(n/3,ans);
    }
    int output = min({x, y, z})+1;
    ans[n]=output;
    return output;


}
int minStepto1Mem(int n ){
    int *ans=new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    return helper(n,ans);
}


//solution by me for - minStepTo1

int minStepTo1(int n){
    if(n==1){
        return 0;
    }
    int x= minStepTo1(n-1);
    int y{INT_MAX};
    int z{INT_MAX};
    if(n%2==0){
        y= minStepTo1(n/2);
    }
    if(n%3==0){
        z= minStepTo1(n/3);
    }
    int ans = min({x, y, z})+1;
    return ans;


}


int main(){
    // std::cout<< minStepTo1(1000) <<std::endl;
    std::cout<< minStepto1Mem(1000) <<std::endl;
    return 0;
}