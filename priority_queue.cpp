#include <bits/stdc++.h>
using namespace std;
class PriorityQ{
public:
    vector<int> pq;
    PriorityQ(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0; // pq is zero
        }
        return pq[0];
    }
    int removeMin(){
// this is my implimentation of code not by the sir- has varified and is totally working;
        int n = pq.size();
        if(n==0){
            return 0;
        }
        int ans = pq[0];
        pq[0]= pq[n-1];
        pq.pop_back();
        n= pq.size();
        int i{0};
        while((2*i+1<n && pq[i]>pq[2*i+1]) || (2*i+2<n && pq[i]>pq[2*i+2])){

            if(2*i+2<n && pq[2*i+1]>pq[2*i+2]){
                swap(pq[i], pq[2*i+2]);
                i=2*i+2;
            }
            else{
                swap(pq[i], pq[2*i+1]);
                i=2*i+1;
            }


        }




//code by the sir;
        // if(isEmpty()){
        //     return 0;
        // }
        // int ans = pq[0];
        // swap(pq[0],pq[pq.size()-1]);
        // pq.pop_back();
        //                     //cbt - yes; heap - no yet;
        //                     //down heaapify

        // int pI= 0;
        // while(true){
        //     int lci= 2*pI+1;
        //     int rci= 2*pI+2;
        //     int miniI= pI;
        //     if(lci<pq.size() && pq[lci]<pq[pI]){
        //         miniI=lci;
        //     }
        //     if(rci<pq.size() && pq[rci]<pq[pI]){
        //         miniI=rci;
        //     }
        //     if(pI==miniI){
        //         break;
        //     }
        //     swap(pq[pI],pq[miniI]);
        //     pI=miniI;

        // }


        return ans;
        
    }
    void insert(int val){
        // this insert function code is mine not sir; it works yeah!!!
        pq.push_back(val);
        int n= pq.size();

        if(n==1){
            return;
        }
        int childInd= n-1;
        int parentInd=(childInd-1)/2;
        while(childInd>0 && pq[parentInd]>pq[childInd]){
            swap(pq[parentInd],pq[childInd]);
            childInd= parentInd;
            parentInd=(childInd-1)/2;
        }

//this is code by sir
        // pq.push_back(val);
        // int n= pq.size();
        // int cI= n-1;
        // while(childInd>0 ){
        //     int pI = (cI-1)/2;
        //     if(pq[cI]<pq[pI]){
        //         swap(pq[cI],pq[pI]);
        //         cI= pI;
        //     }
        //     else{
        //         break;
        //     }
        // }


    }
};


int main(){
    PriorityQ q;
    q.insert(100);
    q.insert(10);
    q.insert(15);
    q.insert(4);
    q.insert(17);
    q.insert(21);
    q.insert(67);
    std::cout<< q.getSize() <<std::endl;
    std::cout<< q.getMin() <<std::endl;

    while(!q.isEmpty()){
        std::cout<< q.removeMin() <<" ";
    }
    




    return 0;
}