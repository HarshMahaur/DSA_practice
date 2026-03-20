#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    char str[100];
    cin.getline(str,100);

    int count=0;
    for(int i{0};str[i]!='\0';i++){
        count++;
    }

    int start{0};
    int end{count-1};

    while(end>start){
        int temp= str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }


    std::cout<< str <<std::endl;


    return 0;
}