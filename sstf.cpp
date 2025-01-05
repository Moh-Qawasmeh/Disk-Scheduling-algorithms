#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

 void sstf(){
     int cylinders = 0;
     int headPointer, numberOfRequests; 
     cin >> numberOfRequests >> headPointer;
     set<pair<int, int>> requests;
     for(int i = 0; i < numberOfRequests; i++ ){
        int r; cin >> r; 
        requests.insert({r, i+1});
     }
     vector<int> headPointerAllocations;
     while(!requests.empty()){
        bool r1 = true, r2 = true;
        auto it = requests.upper_bound({headPointer, INT_MAX});
        if(it == requests.end()) r1 = false;
        auto it2 = it;
        if(it2 == requests.begin()) r2 = false;
        it2--;
        if(r1 && r2){
           if((it->first) - headPointer < headPointer - (it2->first)){
               cylinders += (it->first) - headPointer;
               headPointer = it->first;
               requests.erase(it);
           }
           else if((it->first) - headPointer > headPointer - (it2->first)){
              cylinders += headPointer - (it2->first);
              headPointer = it2->first;
              requests.erase(it2);
           }
           else {
              if(it->second < it2->second){
                   cylinders += (it->first) - headPointer;
                   headPointer = it->first;
                   requests.erase(it);
              }
              else{
                  cylinders += headPointer - (it2->first);
                   headPointer = it2->first;
                   requests.erase(it2);
              }
           }
        }
        else if (r1){
            cylinders += (it->first) - headPointer;
               headPointer = it->first;
               requests.erase(it);
        }
        else{
           cylinders += headPointer - (it2->first);
                   headPointer = it2->first;
                   requests.erase(it2);
        }
        headPointerAllocations.push_back(headPointer);
     }
     cout << "The number of cylinders is: " << cylinders << endl; 
     cout << "Allocations visited by the head pointer: " << endl;
     for(auto i: headPointerAllocations) cout << i << ' ';
 }
 
int main() {
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0);  cout.tie(0);
    sstf();
    return 0;
} 