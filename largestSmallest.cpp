#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    std::cout<< "enter the no of element" <<std::endl;
    
    int no_of_elem{0};
    std::cin>>no_of_elem ;

    int Arr[no_of_elem];

    for (int i{0};i<no_of_elem;i++){
        std::cin>> Arr[i];
    }
    std::cout<< "---------------------------------------" <<std::endl;
    for (int i{0};i<no_of_elem;i++){
        std::cout<<  Arr[i]<<std::endl;
    
    std::cout<< "-----------------------------" <<std::endl;}

    int max_elem= Arr[0];
    int min_elem= Arr[0];

    for(int i{1};i<no_of_elem;i++){
        if (max_elem<Arr[i]){
            max_elem=Arr[i];
        }
    }
    for(int i{1};i<no_of_elem;i++){
        if (min_elem>Arr[i]){
            min_elem=Arr[i];
        }
    }

    std::cout<< "the max elem is " <<std::endl;
    std::cout<< max_elem <<std::endl;
    std::cout<< "the min elem is " <<std::endl;
    std::cout<< min_elem <<std::endl;




    return 0;
}