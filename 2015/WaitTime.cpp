#include <iostream>
#include  <bits/stdc++.h>
using namespace std;


int main(){

    // freopen("traffic.in", "r" , stdin);
    // freopen("traffic.out", "w", stdout);

    map<int, int> ans;
    map<int, int> last_seen;
    set<int> replied;
    int n;
    cin >> n;

    char action;
    int number;
    int time=-1;
    for(int i=0;i<n;++i){
        cin >> action >> number;

        if(action=='R'){
            time++;    
            auto it = last_seen.find(number);
        //checking if it is a new number, so we can intialise it
            if(it==last_seen.end()) ans[number]=0; 

            last_seen[number] = time;

            replied.insert(number);

        }
        else if(action == 'S'){
            time++;
            ans[number]+= time-last_seen[number];

            replied.erase(number);

        }
        else if(action=='W') {

            time+= number-1;
            continue;  
        }
        
    }

    auto it = ans.begin();
    while(it!=ans.end()){
        int num = it->first;
        auto k=replied.find(num);
        if(k==replied.end())        cout << it->first << " " << it->second << endl;
        else cout << it->first << " -1" << endl;

        ++it;
    }

    return 0;
}
