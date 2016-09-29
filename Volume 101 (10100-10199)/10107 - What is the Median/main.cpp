#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long int tmp, size = 0;
    vector<long long int> vec;
    while(cin >> tmp){
        vec.push_back(tmp);
        sort(vec.begin(), vec.end());
        size++;
        if(size % 2 != 0){
            cout << vec[size/2] << endl;
        }else{
            cout << ((vec[size/2]+vec[size/2-1])/2) << endl;
        }
    }
    return 0;
}
