#include <iostream>
#include <algorithm>
using namespace std;
/*
* Problem: #10905 - Children's Game
* URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1846
*/
bool cmp(string a, string b){
    return (a+b) > (b+a);
}
int main(){
    int n;
    while(cin >> n){
        if(n == 0) break;
        string str[n];
        for(int i = 0; i < n; i++)
            cin >> str[i];
        sort(str, str+n, cmp);
        for(int i = 0; i < n; i++)
            cout << str[i];
        cout << endl;
    }
}
