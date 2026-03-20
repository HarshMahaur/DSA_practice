#include <bits/stdc++.h>
using namespace std;

int count_zero(int the_num);
int count_zero(int the_num){

    //my code

    // if (the_num==0)
    // {
    //     return count;
    // }
    // int last_dig= the_num%10;
    // if (last_dig==0)
    // {
    //     count++;
    // }
    // return multiply(the_num/10,count);

    if (the_num==0)
    {
        return 0;
    }
    
    int sml_ans= count_zero(the_num/10);
    int lst_dig=the_num%10;
    if (lst_dig==0)
    {
        return 1+ sml_ans;
    }
    else
    {
        return sml_ans;
    }
    
    

    
}


int main(){
    
    std::cout<<count_zero(200750) <<std::endl;



    return 0;
}