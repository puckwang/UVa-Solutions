#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    getline(cin, s);
    while(n-- > 0){
        getline(cin, s);
        stack<char> stk;
        if(s == ""){
            cout << "Yes" << endl;
            continue;
        }
        bool flag = 0;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(':
                case '[':
                    stk.push(s[i]);
                    break;
                case ']':
                    if(stk.empty() || stk.top() != '['){
                        flag = 1;
                        break;
                    }
                    stk.pop();
                    break;
                case ')':
                    if(stk.empty() || stk.top() != '('){
                        flag = 1;
                        break;
                    }
                    stk.pop();
                    break;

            }
            if(flag == 1)
                break;
        }
        if(!stk.empty()) flag = 1;
        cout << ((flag == 0)?"Yes":"No") << endl;
    }
    return 0;
}
