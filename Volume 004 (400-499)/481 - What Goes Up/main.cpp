#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> seq, LTS, posit;
    int in, LTSlen = 0;
    while(cin >> in){
        seq.push_back(in);
    }
    LTS.push_back(seq[0]);
    posit.push_back(0);
    for(int i = 1; i < seq.size(); i++){
        if(seq[i] > LTS.back()){
            LTSlen++;
            LTS.push_back(seq[i]);
            posit.push_back(LTS.size()-1);
        }else if(seq[i] == LTS.back()){
            posit.push_back(LTS.size()-1);
        }else {
            bool flag = 0;
            for(int j = LTS.size()-2; j >= 0; j--){
                if(seq[i] > LTS[j]){
                    LTS[j+1] = seq[i];
                    posit.push_back(j+1);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                LTS[0] = seq[i];
                posit.push_back(0);
            }
        }
    }
    LTS.clear();
    int tmpLTSlen = LTSlen;
    for(int i = posit.size()-1; i >= 0; i--){
        if(posit[i] == tmpLTSlen){
            LTS.insert(LTS.begin(),seq[i]);
            tmpLTSlen--;
            if(tmpLTSlen == -1)
                break;
        }
    }
    cout << (LTSlen+1) << endl << "-" << endl;
    for(int i = 0; i < LTS.size(); i++)
        cout << LTS[i] << endl;
    return 0;
}
