#include<iostream>
using namespace std;
int main(){
    char c;
    bool flag = 1;
    while((c = getchar()) != EOF){
        if(c == '\"'){
            if(flag){
                putchar('`');
                putchar('`');
            }else{
                putchar('\'');
                putchar('\'');
            }
            flag = !flag;
        }else{
            putchar(c);
        }
    }
    return 0;
}
