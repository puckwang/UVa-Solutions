#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
int DFS(const int n, int sum, char c, int *check){
    int neg = 0, tmp = 0, f = 0;
    while( c != '(' && c != ')') cin >> c;
    while(1){
        cin >> c;
        if(isdigit(c)){
            tmp = tmp * 10 + c - int('0');
            f = 1;
        }else{
            if(c == '-'){
                neg = 1;
            }else if (c == ')') {
                return 1;
            }else{
                break;
            }
        }
    }
    if(neg) tmp *= -1;
    if(f == 0) return 1;
    // cout << "#" << tmp << endl;
    sum += tmp;
    int left = DFS(n, sum, c, check);
    int right = DFS(n, sum, ' ', check);
    if(left == 1 && right == 1) {
        if(sum == n)
            *check = 1;
        // cout << "## " << sum << endl;
    }
    while( c != ')' ) cin >> c;
    return 0;
}
int main(){
    int n;
    while( cin >> n ){
        int check = 0;
        DFS(n, 0, ' ', &check);
        cout << (check?"yes":"no") << endl;
    }
    return 0;
}
