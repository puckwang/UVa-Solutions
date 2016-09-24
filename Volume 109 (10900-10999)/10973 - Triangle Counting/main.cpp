#include <iostream>
using namespace std;
/*
    10973 - Triangle Counting
    2016-05-16 10:46:28
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1914
*/
int conutTriangle(const int *graph,const int n){
    int i, j, k, sum = 0;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
             if(*(graph + i * n + j) == 0)
                 continue;
            for(k = j+1; k < n; k++){
                sum += *(graph + i * n + k) * *(graph + j * n + k);
            }
        }
    }
    return sum;
}
int main(){
    int t, n, k;
    cin >> t;
    while(t-- > 0){
        cin >> n >> k;
        int *graph = new int [n*n];
        int a, b, i, j;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                *(graph + i * n + j) = 0;
        for(i = k; i > 0; i--){
            cin >> a >> b;
            a--, b--;
            *(graph + a * n + b) = 1;
            *(graph + b * n + a) = 1;
        }
        cout << conutTriangle(graph, n) << endl;
    }
    return 0;
}
