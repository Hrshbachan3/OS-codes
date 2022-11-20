#include<iostream>
#include<bits/stdc++.h>
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

    int seek_time=0;
    int i;

    int x = queue.size();

    while(queue.size()!=0) {

        int mini=-1;
        int mini_time=pow(2,31)-1;

        for(i=0;i<queue.size();i++) {

            if(abs(head-queue[i]<mini_time)) {

                mini_time=abs(head-queue[i]);
                mini=i;
            }
        }

        cout<<"going from: "<<head<<" to: "<<queue[mini]<<endl;

        seek_time = seek_time + mini_time;
        head=queue[mini];

        swap (queue [mini], queue [queue. size() -1]);
        queue.pop_back();

        cout<<"remaining I/O requests: ";

        for(auto e : queue) {
            
            cout<<e<<" ";
        }
        cout<<endl;
    }

    cout<<"seek time using SSTF: "<<seek_time<<endl;
}