#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;


int main(){
    int arr[100][100];
    int m{0},n{0};
    std::cin>>m>>n ;
    std::cout<< "-----------------------------------" <<std::endl;

    for(int col{0};col<n;col++){
        for(int row{0};row<m;row++){
            std::cin>>arr[row][col] ; 
        }
    }
    for( int row{0};row<m;row++   ){
        for(  int col{0};col<n;col++){
            std::cout<< arr[row][col]<<" " ;
        }
        std::cout<< "" <<std::endl;
    }



    return 0;
}