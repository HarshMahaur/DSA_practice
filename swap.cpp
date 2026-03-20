#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;

void swaptor(int* a,int* b);
void swaptor(int* a,int* b){
    int temp{0};
    temp=*a;
    *a=*b;
    *b=temp;
}


int main(){
    int first_no{0}, second_no{0};
    std::cin>>first_no ;
    std::cin>>second_no ;

    std::cout<< "before swap" <<std::endl;
    std::cout<< "first num : "<<first_no <<std::endl;
    std::cout<< "second num : "<<second_no <<std::endl;


    swaptor(&first_no, &second_no);

    // first_no=first_no^second_no;
    // second_no=first_no^second_no;
    // first_no=first_no^second_no;

    std::cout<< "after swap" <<std::endl;
    std::cout<< "first num : "<<first_no <<std::endl;
    std::cout<< "second num : "<<second_no <<std::endl;


    return 0;
}