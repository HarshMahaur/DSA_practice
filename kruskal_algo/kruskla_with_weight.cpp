#include <bits/stdc++.h>
using namespace std;


// mine code attempt to kruskal
// and this shi the weighted shi also actually worked.

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
    parent[a]=b; // make the parent of i and make child of j; so all child of i become child of j.

}


vector<pair<int,int>> MST_Kruskal(vector<vector<int>> grap){
    int n = grap.size();
    int m = grap[0].size();
    vector<int> parent(n,-1);


    // updated
    // if i take vector i have to make a search of o(n) 
    //then sort it after all the set are made
    //or i can take extra space, have a vector and a set;
    // set for just search as "visited" array
    vector<vector<int>> edges;
    set<tuple<int,int,int>> edgesset;
    
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grap[i][j]!=-1){
                int wt= grap[i][j];
                if(parent[i]==-1){
                    makeSet(parent,i);
                }
                if(parent[j]==-1){
                    makeSet(parent,j);
                }
                if(edgesset.count({wt,i,j})==0 && edgesset.count({wt,j,i})==0){
                    edgesset.insert({wt,i,j});
                    edges.push_back({wt,i,j});
                }
            }
        }
    }
    //delete the extra space 
    edgesset.clear();
    // now will sort the vector;
    sort(edges.begin(), edges.end()); 

    //for now there will be no traversing on the basis of weight;
    vector<pair<int,int>> MST;
    for(auto c: edges){
        int w = c[0];
        int a = c[1];
        int b = c[2];
        if(find(parent,a)!=find(parent,b)){
            Union(parent,a,b);
            MST.push_back({a,b});
        }
    }
    return MST;

}



int main(){
    // adjecentry matrix implimentation by me ; 
    int n,e;
    std::cin>>n>>e ;
    vector<vector<int>> grap(n,vector<int>(n,-1));

    for(int i=0;i<e;i++){
        int sn,en, wt;
        std::cin>>sn>>en>>wt;
        // now will add weight; later
        // std::cin>>weight ;
        grap[sn][en]=wt;
        grap[sn][en]=wt;
        // grap[sn][en]=1;
        // grap[sn][en]=1;

    }

    // std::cout<< "DFS output : " <<std::endl;
    // DFS(grap);

    
    // std::cout<< "BFS output : " <<std::endl;
    // BFS(grap);

    std::cout<< "output fo the minimum spanning tree is : " <<std::endl;
    vector<pair<int,int>> MST;
    MST= MST_Kruskal(grap);
    for(auto c: MST){
        std::cout<< c.first << " " << c.second<< " : "<<grap[c.first][c.second]<<std::endl;
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
9 14
0 1 4
0 7 8
1 2 8
7 8 7
7 6 1
7 1 11
8 2 2
8 6 6
6 5 2
5 2 4
5 3 14
2 3 7
5 4 10
3 4 9

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
0 1 12
0 2 7
0 5 19
0 10 4
1 2 15
1 3 9
1 6 21
1 11 6
2 3 14
2 4 8
2 7 25
2 12 11
3 4 18
3 8 5
3 13 23
4 9 10
4 14 16
5 6 13
5 10 22
5 15 7
6 7 17
6 11 3
6 16 20
7 8 12
7 12 24
7 17 9
8 9 6
8 13 15
8 18 27
9 14 11
9 19 19
10 11 8
10 15 26
10 20 5
11 12 13
11 16 18
11 21 7
12 13 21
12 17 10
12 22 28
13 14 14
13 18 6
13 23 17
14 19 25
14 24 9
15 16 12
15 20 23
15 25 4
16 17 16
16 21 8
16 26 20
17 18 11
17 22 29
17 27 7
18 19 15
18 23 22
18 28 5
19 24 18
19 29 13
20 21 6
21 22 24
22 23 10
23 24 19
24 29 27
25 26 8
26 27 14
27 28 21
28 29 12
0 29 30
2 28 16
4 26 7
6 24 23
8 22 11
10 20 26
1 21 15
3 23 28
5 25 9
7 27 18
9 29 4
11 29 25

*/
