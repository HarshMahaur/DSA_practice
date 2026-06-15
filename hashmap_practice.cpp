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
    // printVec(vec);

    unordered_map<string, int> mymap;
    mymap["helo"]=2;
    mymap["helo1"]=5;
    mymap["helo2"]=264;
    mymap["helo3"]=6;
    mymap["helo4"]=2;
    mymap["helo5"]=64;
// instead of unordered_map<string,int>::iterator can use "auto"
    for(unordered_map<string,int>::iterator it=mymap.begin();it!=mymap.end();it++){
        std::cout<< it->first <<std::endl;
    }
    map<string, int> mymap2;
    mymap2["helo"]=2;
    mymap2["helo1"]=5;
    mymap2["helo2"]=264;
    mymap2["helo3"]=6;
    mymap2["helo4"]=2;
    mymap2["helo5"]=64;

    for(map<string,int>::iterator it=mymap2.begin();it!=mymap2.end();it++){
        std::cout<< it->first <<std::endl;
    }



    




    return 0;
}