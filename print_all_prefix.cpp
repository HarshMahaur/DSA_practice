#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

//not effective using extra space.
// void prefix(char arr[]);
// void prefix(char arr[]){
//     char temp_arr[100];
//     std::cout<< "-------------------------------------" <<std::endl;
//     for (int i{0};arr[i]!='\0';i++){
//         temp_arr[i]=arr[i];
//         temp_arr[i+1]='\0';

//         std::cout<< temp_arr <<std::endl;
//     }
// }


void prefix(char arr[]);
void prefix(char arr[]){
    for(int end=strlen(arr);end>0;end--){
        for (int sp{0};sp<end-1;sp++){
            std::cout<< " " ;
        }
        for(int start{end-1};arr[start]!='\0';start++){
            std::cout<< arr[start] ;
        }
        std::cout<< "" <<std::endl;
    }


}

int main(){
    char arr[100];
    cin.getline(arr,100);

    prefix(arr);




    return 0;
}