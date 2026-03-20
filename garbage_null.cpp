/*
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    char a[10];
    std::cin>>a ;
    a[3]='c';
    a[4]='g';

    std::cout<< a <<std::endl;


    return 0;
}

*/

/*
#include <ctype.h>
using namespace std;

int main(){
    char a[10];
    std::cin >> a;  // Input a string of up to 9 characters
    a[3] = 'c';  // Modify the character at index 3
    a[4] = 'g';  // Modify the character at index 4

    // Loop to print each character until null character
    for(int i = 0; i < 10; i++) {
        cout << a[i];  // Print each character in the array
    }
    cout << endl;

    return 0;
}

*/



#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;


int main(){
    char a[99];
    std::cin>>a ;
    a[3]='c';
    a[4]='g';

    for(int i = 0; i < 10; i++) {
        cout << a[i];  // Print each character in the array
    }


    return 0;
}