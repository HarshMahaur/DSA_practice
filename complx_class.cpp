#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
using namespace std;

class Complex{
    private:
    int real;
    int img;
    public:
    int get_real(){
        return real;
    }
    int get_img() {
        return img;
    }
    void set_real(int a){
        real=a;
    }
    void set_img(int b) {
        img=b;
    }
    void sum(Complex &c2){
        set_real(real+c2.get_real());
        set_img(img+c2.get_img());

    }
    void multi(Complex &c2){
        int newreal=real*c2.get_real() - img*c2.get_img();
        int newimg=img*c2.get_real()+ real*c2.get_img();
        set_real(newreal);
        set_img(newimg);

    }


    Complex(int a,int b){    
    real=a;
    img=b;
    }
    void print_it(){
        std::cout<< real << " + "<<img<<"i" <<std::endl;
    }

};

int main(){
    Complex c1(1,3);
    Complex c2(4,2);

    int n;
    std::cin>>n ;
    
    if (n==1)
    {
        c1.sum(c2);
        c1.print_it();
    }
    if (n==2)
    {
        c1.multi(c2);
        c1.print_it();
    }
    
    




    return 0;
}







