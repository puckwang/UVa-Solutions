#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct figure{
    double x1, y1, x2, y2;
};
int main(){
    vector<figure> vec;
    figure tmp;
    char c;
    while(cin >> c){
        if(c == '*') break;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        vec.push_back(tmp);
    }
    double x, y;
    int pointCount = 1;
    bool flag;
    while(cin >> x >> y){
        flag = 0;
        if(fabs(x - 9999.9) < 0.1 || fabs(y - 9999.9) < 0.1) break;
        for(int i = 0; i < vec.size(); i++){
            if(x > vec[i].x1 && y < vec[i].y1 && x < vec[i].x2 && y > vec[i].y2){
                printf("Point %d is contained in figure %d\n", pointCount, (i+1));
                flag = 1;
            }
        }
        if(flag == 0)
            printf("Point %d is not contained in any figure\n", pointCount);
        pointCount++;
    }
    return 0;
}
