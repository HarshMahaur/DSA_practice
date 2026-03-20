#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    int no_elem{0};
    std::cin>>no_elem ;
    int arr[no_elem]{0};

    for(int i{0};i<no_elem;i++){
        std::cin>>arr[i] ;
    }

    //my method

    // for (int i{0};i<no_elem/2;i++){
    //     int temp=arr[i];
    //     arr[i]=arr[no_elem-1-i];
    //     arr[no_elem-1-i]=temp;
    // }



    //sir method
    int start{0},end{no_elem-1};
    while (end>start)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    


    std::cout<< "------------------------------" <<std::endl;

    for(int i{0};i<no_elem;i++){
        std::cout<<  arr[i] <<" " ;
    }


    return 0;
}