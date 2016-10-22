#include <iostream>
/*
* Problem: #913 - Joana and the Odd Numbers
* URL: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=854
*/
using namespace std;
int main(){
    long long int n;
    while(cin >> n){
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        long long int odd = ((1 + n)*(n+1)/4-1)*2+1,
                      sum = odd * 3 - 6;
        cout << sum << endl;
    }
    return 0;
}
