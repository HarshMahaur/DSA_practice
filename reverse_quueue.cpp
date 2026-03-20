#include <bits/stdc++.h>
using namespace std;

void rev(queue <int>& q){
    if (q.empty()){
        return;
    }
    ''
    int temp=q.front();
    q.pop();
    rev(q);
    q.push(temp);

    
}


int main(){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    rev(q);
    while(!q.empty()){
        std::cout<< q.front() <<std::endl;
        q.pop();
    }





    return 0;
}