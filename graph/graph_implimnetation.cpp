#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,e;
    std::cin>>n>>e ;
    vector<vector<int>> grap(n,vector<int>(n,0));

    for(int i=0;i<e;i++){
        int sn,en;
        std::cin>>sn>>en;
        grap[sn][en]=1;
        grap[sn][en]=1;
    }




    return 0;
}