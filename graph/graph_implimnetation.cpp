#include <bits/stdc++.h>
using namespace std;
// this guntion kinda useless- hashmap for visited would make more sence as visted array suppose that the graph valud are under the n and no repeated values.
void printDFS(vector<vector<int>> matrix,vector<bool>& visited,int sv){
    
    std::cout << sv<<std::endl;
    visited[sv]=true;
    
    int n = matrix.size();
    for(int i =0;i<n;i++){
        if(matrix[sv][i]==1 && visited[i]==false){
            printDFS(matrix,visited,i);
        }
        
    }
}

// mine code attempt
void printBFS(vector<vector<int>> matrix,vector<bool>& visited,queue<int> q,int sv){
    int n = matrix.size();
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        sv= q.front();
        std::cout<< sv <<std::endl;
        q.pop();
        
        for(int i =0;i<n;i++){
            if(matrix[sv][i]==1 && visited[i]==false){
                visited[i]=true;
                q.push(i);
            }
        }
    }
    
}
void DFS(vector<vector<int>> matrix){
    int n= matrix.size();
    vector<bool> visited(n,false);
    for(int i =0;i<n;i++){
        if(!visited[i]){
            printDFS(matrix,visited,i);

        }
    }
}

void BFS(vector<vector<int>> matrix){
    int n= matrix.size();
    vector<bool> visited(n,false);
    queue<int> que;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            printBFS(matrix,visited,que,i);
    
        }
    }
    
}



int main(){
    // adjecentry matrix implimentation; 
    int n,e;
    std::cin>>n>>e ;
    vector<vector<int>> grap(n,vector<int>(n,0));

    for(int i=0;i<e;i++){
        int sn,en;
        std::cin>>sn>>en;
        grap[sn][en]=1;
        grap[sn][en]=1;
    }

    DFS(grap);
    std::cout<< "BFS output : " <<std::endl;
    BFS(grap);





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

input case 2- 
7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
6 5



disconnected graph case;
input 1 -
7
7
0 1
1 6
1 3
6 3
2 4
2 5
4 5

*/