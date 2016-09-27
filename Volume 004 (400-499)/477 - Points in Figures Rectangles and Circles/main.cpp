#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct figure{
    char c;
    double x1, y1, x2, y2, r;
};
int main(){
    vector<figure> vec;
    figure tmp;
    char c;
    while(cin >> c){
        if(c == '*') break;
        if(c == 'r') cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        if(c == 'c') cin >> tmp.x1 >> tmp.y1 >> tmp.r;
        tmp.c = c;
        vec.push_back(tmp);
    }
    double x, y;
    int pointCount = 1;
    bool flag;
    while(cin >> x >> y){
        flag = 0;
        if(fabs(x - 9999.9) < 0.1 || fabs(y - 9999.9) < 0.1) break;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].c == 'r' && x > vec[i].x1 && y < vec[i].y1 && x < vec[i].x2 && y > vec[i].y2){
                printf("Point %d is contained in figure %d\n", pointCount, (i+1));
                flag = 1;
            }else if(vec[i].c == 'c' && (vec[i].x1 - x)*(vec[i].x1 - x) + (vec[i].y1 - y)*(vec[i].y1 - y) < vec[i].r * vec[i].r){
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
