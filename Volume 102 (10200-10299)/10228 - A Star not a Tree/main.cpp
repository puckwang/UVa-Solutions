#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#define CTH 15 //重新嘗試退火次數
#define EPS 0.01 //停止精準度
#define STEP 1000 //初始退火速
#define RATE 0.7 //退火率
using namespace std;
struct Point{
    double x, y;
};
double getTotalDis(Point o, Point *p, int n){
    double dis = 0.0;
    for(int i = 0; i < n; i++){
        dis += sqrt((o.x-p[i].x)*(o.x-p[i].x) + (o.y-p[i].y)*(o.y-p[i].y));
    }
    return dis;
}
int getrand(){
    return rand() % 10001;
}
int xm[4] = {0, 1, 0, -1}, ym[4] = {1, 0, -1, 0};
double SA(Point *data, int ncmp){
    int cth = CTH;
    double rate = RATE, GlobMinDis = 1E20;
    while(cth-- > 0){
        Point now;
        int step = STEP;
        now.x = getrand(), now.y = getrand();
        double AreaMinDis = getTotalDis(now, data, ncmp);
        while(step > EPS){
            for(int i = 0; i < 4; i++){
                Point next = {now.x + step * xm[i], now.y + step * ym[i]};
                double nextDis = getTotalDis(next, data, ncmp);
                if(nextDis < AreaMinDis){
                    AreaMinDis = nextDis;
                    now = next;
                }
            }
            step *= rate;
        }
        GlobMinDis = min(AreaMinDis, GlobMinDis);
    }
    return GlobMinDis;
}
int main(){
    int n;
    cin >> n;
    while(n-- > 0){
        int ncmp;
        cin >> ncmp;
        Point data[ncmp];
        for(int i = 0; i < ncmp; i++)
            cin >> data[i].x >> data[i].y;
        cout << round(SA(data, ncmp)) << endl;
        if(n != 0) cout << endl;
    }
    return 0;
}
