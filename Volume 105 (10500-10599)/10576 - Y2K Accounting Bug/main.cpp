#include <iostream>
using namespace std;
/*
    10576 - Y2K Accounting Bug
    2016-07-21 16:24:34
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1517
*/
int main(){
    int s, d, i, ans;
    while( cin >> s >> d){
        ans = 0;
        for(i = 4; i > 0; i--)
            if(i * s - (5-i) * d < 0){
                if(i == 1){
                    ans = s * 3 - d * 9;
                }else{
                    ans = s * i * 2 - d * (5-i) * 2 + s * 2;
                }
                break;
            }
        if(ans > 0)
            cout << ans << endl;
        else
            cout << "Deficit" << endl;
    }
    return 0;
}
