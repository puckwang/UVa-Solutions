#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int src, dest;
    while(cin >> src >> dest){
        if(src == -1) break;
        cout << ( min(abs(src-dest), min(100-src, 100-dest)+min(src, dest)) ) << endl;
    }
    return 0;
}
