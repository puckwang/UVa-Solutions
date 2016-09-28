#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string s;
    while(getline(cin, s)){
        bool flag = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                flag = 1;
            }else if(flag == 1){
                count++;
                flag = 0;
            }
        }
        if(flag == 1)
        cout << count << endl;
    }
    return 0;
}
