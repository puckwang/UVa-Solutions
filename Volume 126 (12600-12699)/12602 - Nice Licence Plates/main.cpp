#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        string s;
        int part1, part2;
        cin >> s;
        part1 = (s[0]-int('A')) * 26;
        part1 = (part1 + s[1]-int('A')) * 26;
        part1 += s[2]-int('A');

        part2 = (s[4]-int('0'))*1000 +
                (s[5]-int('0'))*100 +
                (s[6]-int('0'))*10 +
                (s[7]-int('0'));
        cout << ( abs(part1 - part2) <= 100 ? "nice":"not nice") << endl;
    }
    return 0;
}
