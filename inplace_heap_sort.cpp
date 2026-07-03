#include <bits/stdc++.h>
using namespace std;
void insertHeap(vector<int>& vec){
    // this insert function code is mine not sir; it works yeah!!!
    int n = vec.size();
    

    if(n==1){
        return;
    }
    int start{1};
    while(start<vec.size()){
        int childInd= start;
        int parentInd=(childInd-1)/2;


        while(childInd>0 && vec[parentInd]>vec[childInd]){
            swap(vec[parentInd],vec[childInd]);
            childInd=parentInd;
            parentInd=(childInd-1)/2;
        }
        start++;
    }
}

void removeMinHeap(vector<int>& vec){
// this is my implimentation of code not by the sir- has varified and is totally working;
    int n = vec.size();
    if(n==0){
        return ;
    }

    while(n>0){
        swap(vec[0],vec[n-1]);
        n--;
        int i{0};


        while((2*i+1<n && vec[i]>vec[2*i+1]) || (2*i+2<n && vec[i]>vec[2*i+2])){
    
            if(2*i+2<n && vec[2*i+1]>vec[2*i+2]){
                swap(vec[i], vec[2*i+2]);
                i=2*i+2;
            }
            else{
                swap(vec[i], vec[2*i+1]);
                i=2*i+1;
            }
    
    
        }
    }
}

void inplaceHeapSort(vector<int>& vec){
    insertHeap(vec);
    removeMinHeap(vec);

}




int main(){
    vector<int> vec={4,7,15,10,67,69,1,42,99};
    inplaceHeapSort(vec);
    for(auto c:vec){
        cout<<c<<" "; 
    }

    




    return 0;
}