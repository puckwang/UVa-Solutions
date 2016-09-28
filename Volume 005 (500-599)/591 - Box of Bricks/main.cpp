#include <iostream>
using namespace std;
int main(){
    int n, qc = 1;
    while(cin >> n){
        if(n == 0) break;
        int arr[n], avg = 0, count = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= n;
        for(int i = 0; i < n; i++){
            if(arr[i] < avg)
                count += avg - arr[i];
        }
        cout << "Set #" << qc << endl;
        qc++;
        cout << "The minimum number of moves is "<< count << "." << endl << endl;
    }
    return 0;
}
