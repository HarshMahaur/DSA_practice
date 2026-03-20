#include <bits/stdc++.h>
using namespace std;
void del_rep(string &n1,int k,int i);
void check_rep(string &n1, int k);
void del_rep(string &n1,int k,int i){


        n1.erase(i - k + 1, k);





}

void check_rep(string &n1, int k){
    int count{1};
 
    for(int i=1;i<n1.length();i++){
        int temp_check=n1[i];
        if(n1[i]==n1[i-1]){
            count++;
            if(count==k){
                del_rep(n1,k,i);
                check_rep(n1,k);
                return;
            }


        }
        else{
        
            count=1;
        }

    }

}


int main(){
    int k;
    std::cin>>k ;
    string n1;
    std::cin>>n1;  

    check_rep(n1,k);
    std::cout<< n1 <<std::endl;
 

    return 0;
}