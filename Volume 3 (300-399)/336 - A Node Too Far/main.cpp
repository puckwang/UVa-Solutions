#include <iostream>
#include <set>
#include <queue>
using namespace std;
int BFS(const int n, const int nodeNum, pair<int, int> *connect, const int start, const int ttl){
    queue< pair<int, int> > que;
    set<int> count;
    pair<set<int>::iterator, bool> check;
    pair<int, int> tmp;
    tmp.first = start, tmp.second = ttl;
    que.push(tmp);
    int flag;
    while(!que.empty()){
        int currNode = que.front().first, currTTL = que.front().second, nextNode;
        que.pop();
        check = count.insert(currNode);
        if(check.second == false || currTTL == 0) continue;
        for(int i = 0; i < n; i++){
            flag = 0;
            if((connect + i)->first == currNode){
                nextNode = (connect + i)->second;
                flag = 1;
            }else if((connect + i)->second == currNode){
                nextNode = (connect + i)->first;
                flag = 1;
            }
            if(flag == 1){
                tmp.first = nextNode, tmp.second = currTTL-1;
                que.push(tmp);
            }
        }
    }
    return nodeNum - count.size();
}
int main(){
    int n, countQ = 1;;
    while(cin >> n){
        if (n == 0) break;
        pair<int, int> connect[n];
        set<int> countSet;
        pair<set<int>::iterator, bool> check;
        for(int i = 0; i < n; i++){
            cin >> connect[i].first >> connect[i].second;
            countSet.insert(connect[i].first);
            countSet.insert(connect[i].second);
        }
        int start, ttl, countNode;
        while(1){
            cin >> start >> ttl;
            if(start == 0 && ttl == 0)
                break;
            check = countSet.insert(start);
            if(check.second == true){ //不存在於網路
                countSet.erase(countSet.find(start));
                countNode = countSet.size();
            }else{
                countNode = BFS(n, countSet.size(), connect, start, ttl);
            }
            cout << "Case " << countQ << ": " << countNode <<
                    " nodes not reachable from node " << start <<
                    " with TTL = " << ttl << "." << endl;
            countQ++;
        }
    }
    return 0;
}
