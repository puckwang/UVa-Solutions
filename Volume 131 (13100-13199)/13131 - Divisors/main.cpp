#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int n, k, end, sum = 0;
        cin >> n >> k;
        if(k == 1){
            cout << 0 << endl;
            continue;
        }
        end = sqrt(n);
        for(int i = 1; i <= end; i++){
            if(n % i == 0){
                if(i % k != 0) sum += i;
                if(i != (n/i) && (n/i) % k != 0) sum += (n/i);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
