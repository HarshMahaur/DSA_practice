#include <bits/stdc++.h>
using namespace std;
vector<int> removeDupe(int *arr,int n){
    vector<int> ans;
    unordered_map<int,bool> mp;

    if(n==0){
        return ans;
    }
    for(int i=0;i<n;i++){
        if(mp.count(arr[i])==1){
            continue;
        }
        else{
            mp[arr[i]]=true;
            ans.push_back(arr[i]);
        }
    }
    return ans;

}

void printVec(vector<int> vec){
    for(auto c:vec){
        cout<< c << " ";
    }
}


int main(){
    int arr[10]={1,5,2,1,5,7,5,8,4,5};
    vector<int> vec=removeDupe(arr,10);
    printVec(vec);
    




    return 0;
}