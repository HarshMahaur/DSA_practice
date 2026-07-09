#include <bits/stdc++.h>
using namespace std;
//my first thaught to approach; kinda sliding window;
int climbingStairsWithK(int n , int k){
    if(k==0 || k>n ){
        std::cout<< "invalid input" <<std::endl;
        return -1;
    }
    if(n==1){
        return n;
    }
    int start{0};
    int end{2};
    int store{1};
    vector<int> vec(n+1,-1);
    vec[0]=1;
    vec[1]=1;
    while(end<=n){
        if(end>k){
            store-= vec[start];
            start++;
            
        }
        store = store+vec[end-1];
        vec[end]= store;
        end++;
    }
    end--;

    return vec[end];

}


int main(){
    std::cout<< climbingStairsWithK(5,5) <<std::endl;
    return 0;
}