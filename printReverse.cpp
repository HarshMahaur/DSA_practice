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

std::cout<< "-----------------------------------" <<std::endl;

    for (int i{no_elem-1};i>=0;i--){
        std::cout<< arr[i] <<std::endl;
    }
    return 0;
}