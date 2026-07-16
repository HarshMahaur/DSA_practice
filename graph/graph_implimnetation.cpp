#include <bits/stdc++.h>
using namespace std;
// this guntion kinda useless- hashmap for visited would make more sence as visted array suppose that the graph valud are under the n and no repeated values.
void print(vector<vector<int>> matrix,vector<bool>& visited,int sv){
    
    std::cout << sv<<std::endl;
    visited[sv]=true;

    int n = matrix.size();
    for(int i =0;i<n;i++){
        if(matrix[sv][i]==1 && visited[i]==false){
            print(matrix,visited,i);
        }

    }
}


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

    vector<bool> visited(n,false);
    print(grap,visited,0);





    return 0;
}
/*
test input - 
7
7
0 1
0 2
1 5
5 4
3 4
2 3
2 6

*/