#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999
#define max(a, b) (a > b)?a:b
using namespace std;
typedef pair<int, int> point;
int BFS(int *grp, point p, int n){
    int dis[n][n], xm[4] = {0, 1, 0, -1}, ym[4] = {-1, 0, 1, 0}, xn, yn, xc, yc;
    queue<point> que;
    point tmp;
    que.push(p);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            dis[i][j] = INF;
    dis[p.first][p.second] = 0;
    while(!que.empty()){
        xc = que.front().first, yc = que.front().second;
        que.pop();
        for(int i = 0; i < 4; i++){
            xn = xc + xm[i], yn = yc + ym[i];
            if(xn < 0 || xn >= n || yn < 0 || yn >= n) continue;
            if( *(grp + xn * n + yn) != 3 && dis[xn][yn] == INF){
                tmp.first = xn, tmp.second = yn;
                que.push(tmp);
                dis[xn][yn] = dis[xc][yc]  + 1;
            }else if(*(grp + xn * n + yn) == 3 ){
                return dis[xc][yc] + 1;
                break;
            }
        }
    }
}
int main(){
    int n;
    char c;
    while(cin >> n){
        int grp[n][n], maxdis = 0;
        vector<point> vec;
        point tmp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> c;
                grp[i][j] = c - int('0'); //輸入地圖
                if(grp[i][j] == 1){
                    tmp.first = i;
                    tmp.second = j;
                    vec.push_back(tmp);
                }
            }
        }
        for(vector<point>::iterator p = vec.begin(); p < vec.end(); p++){
            maxdis = max(maxdis, BFS(*grp, *p, n));
        }
        cout << maxdis << endl;
    }
}
