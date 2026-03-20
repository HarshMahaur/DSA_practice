#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

bool my_strcmp(char arr1[],char arr2[]);
bool my_strcmp(char arr1[],char arr2[]){
    if(strlen(arr1) != strlen(arr2)){
        return false;
    }
    for(int i=0;arr1[i]!='\0';i++){
        if (arr1[i] !=arr2[i]){
            return false;
        }
    }
    return true;

}


int main(){
    char arr1[100]{0},arr2[100]{0};
    cin.getline(arr1,100);
    cin.getline(arr2,100);
    if(my_strcmp(arr1,arr2)==true) {
        std::cout<< "they are same" <<std::endl;
    }
    else{
        std::cout<< "they are diff" <<std::endl;
    }
    




    return 0;
}