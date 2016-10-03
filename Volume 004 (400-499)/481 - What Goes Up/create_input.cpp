#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10000
using namespace std;
int main(){
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        cout << (30000 * rand() / RAND_MAX - 15000)<< endl;
    }
    return 0;
}
