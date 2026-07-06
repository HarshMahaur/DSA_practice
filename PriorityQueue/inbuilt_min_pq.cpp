#include <bits/stdc++.h>
using namespace std;


int main(){
    
    priority_queue<int,vector<int>,greater<int>> pq; //  this is max heap 
    //priority_queue<int,vector<int>,greater<int>> pq(a,a+n); // O(N) - array
    //priority_queue<int,vector<int>,greater<int>> pq(v.begoin(),v.end()); // O(N)- vector
    
    pq.push(68);
    pq.push(67);
    pq.push(9);
    pq.push(100);
    pq.push(56);
    pq.push(2);

    std::cout<< "size: "<<pq.size() <<std::endl;  //6
    std::cout<< "top is : " << pq.top()<<std::endl; //1

    while(!pq.empty()){
        std::cout<< pq.top() <<" ";
        pq.pop();
    }



    return 0;
}