#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    int no_elem{0};
    std::cin>>no_elem ;
    int arr[no_elem];

    for(int i{0};i<no_elem;i++){
        std::cin>>arr[i] ;
    }

    int Reverse_arr[no_elem];

    for(int i{0};i<no_elem;i++){
        Reverse_arr[i]=arr[no_elem-1-i] ;
    }
std::cout<< "--------------------------------" <<std::endl;
    for(int i{0};i<no_elem;i++){
        std::cout<< Reverse_arr[i] <<" ";  ;
    }




    return 0;
}