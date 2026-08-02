#include <bits/stdc++.h>
using namespace std;


// mine code attempt to kruskal
// and this shi actually worked.

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
    // i also need a vector of vector/or set that contains the edges only, so i do not have to loop over the whole matrix again and again;
    // i will create a unsorted set of pair that contains edges;
    set<pair<int,int>> edges;
    
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
                if(edges.count({i,j})==0 && edges.count({j,i})==0){
                    edges.insert({i,j});
                }
            }
        }
    }

    //for now there will be no traversing on the basis of weight;
    vector<pair<int,int>> MST;
    for(auto c: edges){
        int a = c.first;
        int b = c.second;
        if(find(parent,a)!=find(parent,b)){
            Union(parent,a,b);
            MST.push_back(c);
        }
    }
    return MST;

    



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

    // std::cout<< "DFS output : " <<std::endl;
    // DFS(grap);

    
    // std::cout<< "BFS output : " <<std::endl;
    // BFS(grap);

    std::cout<< "output fo the minimum spanning tree is : " <<std::endl;
    vector<pair<int,int>> MST;
    MST= MST_Kruskal(grap);
    for(auto c: MST){
        std::cout<< c.first << " " << c.second <<std::endl;
    }





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

/*

input for the kurskal:
9
13
0 1
0 7
1 2
7 8
7 6
7 1
8 2
8 6
6 5
5 2
5 3
2 3
5 4
3 4

input 2 - 
7
11
0 1
0 2
0 3
1 2
1 4
2 5
3 4
3 6
4 5
4 6
5 6

big ahh input-
30
80
0 1
0 2
0 5
0 10
1 2
1 3
1 6
1 11
2 3
2 4
2 7
2 12
3 4
3 8
3 13
4 9
4 14
5 6
5 10
5 15
6 7
6 11
6 16
7 8
7 12
7 17
8 9
8 13
8 18
9 14
9 19
10 11
10 15
10 20
11 12
11 16
11 21
12 13
12 17
12 22
13 14
13 18
13 23
14 19
14 24
15 16
15 20
15 25
16 17
16 21
16 26
17 18
17 22
17 27
18 19
18 23
18 28
19 24
19 29
20 21
21 22
22 23
23 24
24 29
25 26
26 27
27 28
28 29
0 29
2 28
4 26
6 24
8 22
10 20
1 21
3 23
5 25
7 27
9 29
11 29 

*/