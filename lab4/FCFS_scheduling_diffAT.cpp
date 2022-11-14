#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"number of processes: ";
    cin>>n;

    int* AT = (int*)malloc(n*sizeof(int));
    int* BT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        cout<<"provide Arrival time of process "<<i+1<<":";
        cin>>AT[i];
        cout<<"provide Burst time of process "<<i+1<<":";
        cin>>BT[i];
    }

    //finding Waiting time
    int* WT = (int*)malloc(n*sizeof(int));
    int* ST = (int*)malloc(n*sizeof(int));

    ST[0] = AT[0];
    WT[0] = 0;

    for(int i=0;i<n;i++) {

        ST[i] = ST[i-1] + BT[i-1];
        WT[i] = ST[i] - AT[i];

        if(WT[i]<0) {
            WT[i]=0;
        }
    }

    //finding Turn Around Time
    int* TAT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
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