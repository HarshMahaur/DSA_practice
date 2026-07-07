#include <bits/stdc++.h>
using namespace std;

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
    std::cout<< minStepTo1(7) <<std::endl;
    return 0;
}