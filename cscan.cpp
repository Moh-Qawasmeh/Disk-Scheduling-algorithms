#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

/*
  The request queue ends at 1000 
*/
 void scan(){
     int cylinders = 0;
     int headPointer, numberOfRequests; 
     cin >> numberOfRequests >> headPointer;
     set<int> request;
     cout << "Enter the initial head pointer direction(Right or Left): " << endl;
     string direction; 
     cin >> direction;
     int minimum = 1001, maximum = -1;
     for(int i = 0; i < numberOfRequests; i++ ){
        int r; cin >> r;
        minimum = min(minimum, r);
        maximum = max(maximum, r);
        request.insert(r);
     }
     vector<int> headPointerAllocations;
     if(direction == "Right"){
       for(int i = headPointer + 1; i <= 1000; i++ ){
          if(request.count(i)){
             headPointerAllocations.push_back(i);
             request.erase(i);
          }
       }
        headPointerAllocations.push_back(0);
       for(int i = 0 ; i < headPointer; i++){
            if(request.count(i)){ headPointerAllocations.push_back(i);
             request.erase(i);
            }
       } 
     }
     else if(direction == "Left"){
        for(int i = headPointer - 1 ; i >= 0; i--){
            if(request.count(i)){
             headPointerAllocations.push_back(i);
             request.erase(i);
            }
        }
        headPointerAllocations.push_back(1000);
        for(int i = 1000; i > headPointer; i-- ){
        if(request.count(i)){
             headPointerAllocations.push_back(i);
             request.erase(i);
        }
       } 
     }
    for(int i = 0; i < (int)headPointerAllocations.size(); i++ ){
       cylinders += abs(headPointer - headPointerAllocations[i]);
       headPointer = headPointerAllocations[i];
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
    scan();
    return 0;
} 