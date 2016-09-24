#include <iostream>
#include <queue>
#define INF 9999999
using namespace std;
typedef pair<int, int> point;

int BFS(point src, point dest){
    int dis[9][9], xm[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ym[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    queue<point> que;
    point tmp;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            dis[i][j] = INF;
    dis[src.first][src.second] = 0;
    que.push(src);
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        int xc = tmp.first, yc = tmp.second, dc = dis[xc][yc];
        for(int i = 0; i < 8; i++){
            for(int j = 1; j <= 7; j++){
                int xn = xc + xm[i] * j, yn = yc + ym[i] * j;
                if(xn < 1 || yn < 1 || xn > 8 || yn > 8) break;
                if(xn == dest.first && yn == dest.second) return dc + 1;
                if(dis[xn][yn] != INF) continue;
                tmp.first = xn, tmp.second = yn, dis[xn][yn] = dc + 1;
                que.push(tmp);
            }
        }
    }
}
int main(){
    point src, dest;
    while(cin >> src.first >> src.second >> dest.first >> dest.second){
        if(src.first == 0) break;
        if(src.first == dest.first && src.second == dest.second)
            cout << 0 << endl;
        else
            cout << BFS(src, dest) << endl;
    }
    return 0;
}
