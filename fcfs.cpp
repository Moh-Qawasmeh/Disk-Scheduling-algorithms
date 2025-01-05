#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

 void fcfs(){
     int cylinders = 0;
     int headPointer, numberOfRequests; 
     cin >> numberOfRequests >> headPointer;
     vector<int> request(numberOfRequests);
     for(int i = 0; i < numberOfRequests; i++ ){
        cin >> request[i];
     }
     vector<int> headPointerAllocations;
     for(int i = 0; i < numberOfRequests; i++ ){
        headPointerAllocations.push_back(request[i]);
        cylinders += abs(headPointer - request[i]);
        headPointer = request[i];
     } 
     cout << "The number of cylinders is: " << cylinders << endl; 
     cout << "Allocations visited by the head pointer: " << endl;
     for(auto i: headPointerAllocations) cout << i << ' ';
 }
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    fcfs();
    return 0;
} 
