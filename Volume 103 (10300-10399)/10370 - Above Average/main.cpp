#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int num;
        double avg = 0;
        cin >> num;
        int arr[num];
        for(int i = 0; i < num; i++){
            cin >> arr[i];
            avg += arr[i];
        }
        avg /= num;
        double upave = 0;
        for(int i = 0; i < num; i++)
            if(arr[i] > avg)
                upave++;
        cout << fixed << setprecision(3) << (upave/num)*100.0 << "%" << endl;
    }
    return 0;
}
