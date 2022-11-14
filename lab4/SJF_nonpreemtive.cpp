#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"enter number of processes: ";
    cin>>n;

    int* BT = (int*)malloc(n*sizeof(int));

    //since its SJF non-preemtive, processes will be sorted by Burst times and Arrival times will not be considered.
    for(int i=0;i<n;i++) {
        cout<<"provide Burst time of process "<<i+1<<": ";
        cin>>BT[i];
    }

    int x;
    int temp;

    //sorting burst times
    for(int i=0;i<n;i++) {

        x = i;
        
        for(int j=i+1;j<n;j++) {

            if(BT[j]<BT[x]) {
                x = j;
            }
        }
  
        temp=BT[i];
        BT[i]=BT[x];
        BT[x]=temp;
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

    cout<<"The considered/sorted Burst time is : ";

    for(int i=0;i<n;i++) {
        cout<<BT[i]<<" ";
    }

    cout<<endl;

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