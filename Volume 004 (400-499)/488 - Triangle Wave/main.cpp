#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int f, a;
        cin >> a >> f;
        while(f-- > 0){
            for(int i = 1; i < a; i++){
                for(int j = 0; j < i; j++)
                    cout << i;
                cout << endl;
            }
            for(int i = a; i > 0; i--){
                for(int j = 0; j < i; j++)
                    cout << i;
                cout << endl;
            }
            if(f != 0 || n != 0)
                cout << endl;
        }
    }
    return 0;
}
