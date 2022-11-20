#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main() {

    vector<int> queue;

    int n;
    cout<<"provide number of requests: ";
    cin>>n;

    int head;
    cout<<"provide position of read/write: ";
    cin>>head;

    cout<<"provide values for queue: ";

    for(int i=0;i<n;i++) {
        int val;
        cin>>val;
        queue.push_back(val);
    }

    cout<<"requests will be addressed in the following sequence: ";
    int temp;
    for(auto e : queue) {

        cout<<e;
        temp++;

        if(temp<n) {
            cout<<"->";
        }
    }

    cout<<endl;

    int seek_time=0;

    for(int i=0;i<queue.size();i++) {

        seek_time = seek_time + abs(head-queue[i]);

        cout<<"going from: "<< head <<" to: "<<queue[i]<<" => "<<seek_time<<endl;

        head=queue[i];
    }

    cout<<"seek time using FCFS: "<<seek_time<<endl;
}