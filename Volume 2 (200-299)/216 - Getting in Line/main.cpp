#include<iostream>
#include <iomanip>
#include<stack>
#include<cmath>
using namespace std;
typedef pair<int, int> point;
double getdis(point a, point b){
    return sqrt((a.first - b.first)*(a.first - b.first)+
                (a.second - b.second)*(a.second - b.second));
}
void DFS(const double *dis, const int n, const int count, int *check, double currDis, int preNode, int *route, double *minDis, int *minDisNode){
    for(int i = 0; i < n; i++){
        if(*(check + i) != 1){
            if(count == n-1){
                currDis += *(dis + preNode * n + i);
                if(fabs(currDis - *minDis) < 0.001) return;
                if(currDis < *minDis){
                    *(route + count) = i;
                    *minDis = currDis;
                    // cout << "## " << currDis << endl;
                    for(int j = 0; j < n; j++)
                        *(minDisNode + j) = *(route + j);
                }
                return;
            }else{
                *(check + i) = 1;
                *(route + count) = i;
                if(preNode != -1){
                    DFS(dis, n, count+1, check, currDis+*(dis + preNode * n + i), i, route, minDis, minDisNode);
                }else{
                    DFS(dis, n, count+1, check, 0, i, route, minDis, minDisNode);
                }
                *(check + i) = 0;
            }


        }
    }
}
int main(){
    int n, Qcount = 1;
    cout << fixed << setprecision(2);
    while(cin >> n){
        if(n == 0) break;
        point node[n];
        double dis[n][n];
        for(int i = 0; i < n; i++)
            cin >> node[i].first >> node[i].second;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = getdis(node[i], node[j]);
        int check[n] = {0}, minDisNode[n], route[n];
        double minDis = 214748364.0;
        DFS(*dis, n, 0, check, 0.0, -1 ,route, &minDis, minDisNode);
        // for(int i = 0; i < n; i++)
        //     cout << minDisNode[i] << " ";
        // cout << endl;
        double DisSum = 0.0;
        cout << "**********************************************************" << endl;
        cout << "Network #" << Qcount << endl;
        Qcount++;
        for(int i = 1; i < n; i++){
            cout << "Cable requirement to connect ("
                 << node[minDisNode[i-1]].first << "," << node[minDisNode[i-1]].second
                 << ") to (" << node[minDisNode[i]].first << "," << node[minDisNode[i]].second
                 << ") is " << (dis[minDisNode[i-1]][minDisNode[i]] + 16.0) << " feet." << endl;
            DisSum += dis[minDisNode[i-1]][minDisNode[i]] + 16.0;
        }
        cout << "Number of feet of cable required is " << DisSum << "." << endl;
    }
    return 0;
}
