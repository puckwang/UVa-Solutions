#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
/*
    10226 - Hardwood Species
    2016-07-21 16:58:45
    https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1167
*/
int main(){
    string s;
    int count, n;
    cin >> n;
    getchar();getchar();
    while (n-- > 0){
        map<string, int> mp;
        map<string, int>::iterator it;
        count = 0;
        while(getline(cin, s)){
            if(s.compare("") == 0)
                break;
            count++;
            if(mp.find(s) == mp.end()){
                mp[s] = 1;
            }else{
                mp[s]++;
            }
        }
        for(it = mp.begin(); it != mp.end(); it++){
            cout << fixed << setprecision(4) << it->first << " "
                << ((double)it->second / count)*100 << endl;
        }
        if(n != 0)
            cout << endl;
    }
    return 0;
}
