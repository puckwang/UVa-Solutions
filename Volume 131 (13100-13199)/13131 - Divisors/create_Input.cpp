#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define N 100000
using namespace std;
int main(){
    srand(time(NULL));
    int n, k;
    cout << N << endl;
    for(int i = 0; i < N; i++){
        n = abs(500000 * rand()/RAND_MAX)+1;
        k = abs(n * rand()/RAND_MAX)+1;
        cout << n << " " << k << endl;
    }
    return 0;
}
