#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"number of processes: ";
    cin>>n;

    int* AT = (int*)malloc(n*sizeof(int)); //considering sequential arrival times
    int* BT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        cout<<"provide Burst time of process "<<i+1<<": ";
        cin>>BT[i];
    }

    int* WT = (int*)malloc(n*sizeof(int));
    int* TAT = (int*)malloc(n*sizeof(int));

    WT[0] = 0;

    for(int i=0;i<n;i++) {

        if(i!=0) {
            WT[i] = WT[i-1] + BT[i-1];
        }
        TAT[i] = WT[i] + BT[i];
    }

    cout<<"The Waiting Time is : ";

    for(int i=0;i<n;i++) {
        cout<<WT[i]<<" ";
    }

    cout<<endl;

    cout<<"The Turn Around Time is : ";

    for(int i=0;i<n;i++) {
        cout<<TAT[i]<<" ";
    }

    cout<<endl;
}