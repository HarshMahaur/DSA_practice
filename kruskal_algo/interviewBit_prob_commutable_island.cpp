#include <bits/stdc++.h>
using namespace std;

// kruskal algo approach;

class Solution {
public:
    void makeSet(int N, int parent[]){
        for(int i =0;i<N;i++){ // we are including 0 as an vertex too...
            parent[i]=i;

        }
    }
    int find( int i,int parent[]){
        while(parent[i]!=i){
            i = parent[i];
        }
        return i;

    }
    void Union(int parent[], int i,int j){
        int a= find(i,parent);
        int b= find(j,parent);
        parent[a]=b;

    }
    static bool cmp(vector<int> A,vector<int> B){
        return A[2]<B[2];
    }
    int solve(int N, vector<vector<int>> &edges) {
/*
        // code after  lecture
        // first sort function as per weight;
        sort(edges.begin(),edges.end());
        int parent[N+1];
        makeSet(N,parent);
        int coast =0;
        for(int i =0;i<edges.size();i++){
            int s= edges[i][0];
            int d= edges[i][1];
            int rS = find()




        }
*/

        // mine code :
        int parent[N+1];
        // now will sort the vector;
        sort(edges.begin(), edges.end(),cmp); 
        // make set 
        makeSet(N,parent);
        int cost{0};
        //for now there will be no traversing on the basis of weight;
        vector<pair<int,int>> MST;
        for(auto c: edges){
            int a = c[0];
            int b = c[1];
            int w = c[2];
            if(find(a,parent)!=find(b,parent)){
                Union(parent,a,b);
                // MST.push_back({a,b});
                cost+=w;
            }
        }

        return cost;

    }
};

int main() {
    int A, M;
    cin >> A >> M;

    vector<vector<int>> B(M, vector<int>(3));

    for (int i = 0; i < M; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    Solution obj;
    std::cout<< "this the sum : " <<std::endl;
    cout << obj.solve(A, B) << endl; 


    return 0;
}

/*
sample input 1 -
4 5
1 2 1
2 3 4
1 4 3
4 3 2
1 3 10

sample input 2-
6 10
1 2 10
1 2 3
2 3 5
3 4 7
4 5 1
5 6 2
6 1 8
2 5 6
3 6 9
1 4 4
sample input 3-
7 12
1 2 2
1 3 2
2 3 1
2 4 4
3 5 3
4 5 2
4 6 7
5 6 4
5 7 6
6 7 1
3 7 8
1 7 9
sample input 4-
8 18
1 2 4
1 3 8
1 4 5
2 3 2
2 5 10
3 4 1
3 5 6
3 6 9
4 6 4
4 7 7
5 6 3
5 8 11
6 7 2
6 8 5
7 8 1
2 8 13
1 8 15
4 8 12
sample input 5-
9 15
1 2 1000
1 3 500
2 3 400
2 4 700
3 5 200
4 5 300
4 6 900
5 6 100
5 7 800
6 8 250
7 8 150
7 9 350
8 9 450
3 9 1200
2 8 600
sample input 6-
10 20
1 2 5
1 3 2
2 3 1
2 4 4
3 5 6
4 5 3
4 6 8
5 6 7
5 7 5
6 7 2
6 8 4
7 8 1
7 9 9
8 9 3
8 10 10
9 10 2
3 8 11
2 9 12
1 10 20
4 10 15
*/