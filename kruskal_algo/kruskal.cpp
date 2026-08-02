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
    int components{0};
    for(int i =0;i<n;i++){
        if(!visited[i]){
            printDFS(matrix,visited,i);
            components++;
            
        }
    }
    std::cout<< "no of components by BFS : " << components<<std::endl;
}

void BFS(vector<vector<int>> matrix){
    int n= matrix.size();
    vector<bool> visited(n,false);
    queue<int> que;
    int components{0};
    for(int i =0;i<n;i++){
        if(!visited[i]){
            printBFS(matrix,visited,que,i);
            components++;
        }

    }
    std::cout<< "no of components by BFS : " << components<<std::endl;
    
}

// mine code attempt to kruskal

void makeSet(vector<int>& parent, int i){
    parent[i]=i;
}
int find(vector<int>& parent, int i){
    while(parent[i]!=i){
        i = parent[i];
    }
    return i;

}
void Union(vector<int>& parent, int i,int j){
    int a= find(parent,i);
    int b= find(parent,j);
    parent[a]=b;

}

vector<pair<int,int>> MST_Kruskal(vector<vector<int>> grap){
    int n = grap.size();
    int m = grap[0].size();
    vector<int> parent(n,-1);
    // unordered_set<int> visited;

    // to make the indivisual set;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grap[i][j]==1){
                // if(!visited.count(i)){
                //     visited.insert(i);
                //     makeSet(i);
                // }
                if(parent[i]==-1){
                    makeSet(parent,i);
                }
                if(parent[j]==-1){
                    makeSet(parent,j);
                }
            }
        }
    }

    //
    



}



int main(){
    // adjecentry matrix implimentation by me ; 
    int n,e;
    std::cin>>n>>e ;
    vector<vector<int>> grap(n,vector<int>(n,0));

    for(int i=0;i<e;i++){
        int sn,en;
        std::cin>>sn>>en;
        // now will add weight; later
        // std::cin>>weight ;
        // grap[sn][en]=weight;
        // grap[sn][en]=weight;
        grap[sn][en]=1;
        grap[sn][en]=1;

    }

    std::cout<< "DFS output : " <<std::endl;
    DFS(grap);

    
    // std::cout<< "BFS output : " <<std::endl;
    // BFS(grap);





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

input 2-
11
6
0 1
3 4
4 5
2 6
6 7
8 9

input 3 - 
7
4
0 1
0 4
1 4
2 5
*/