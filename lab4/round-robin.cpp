#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"number of processes: ";
    cin>>n;

    int quantum;
    cout<<"provide time quantum: ";
    cin>>quantum;

    int* BT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        cout<<"provide Burst time of process "<<i+1<<":";
        cin>>BT[i];
    }

    int * rem_BT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        rem_BT[i] = BT[i];
    }

    int t=0;
    
    //finding waiting time
    int* WT = (int*)malloc(n*sizeof(int));

    while (1) {

        bool done = true;
 
        for (int i = 0 ; i < n; i++) {

            if (rem_BT[i] > 0) {

                done = false;
 
                if (rem_BT[i] > quantum) {

                    t = t + quantum;
 
                    rem_BT[i] -= quantum;
                }
 
                else {
                    t = t + rem_BT[i];

                    WT[i] = t - BT[i];

                    rem_BT[i] = 0;
                }
            }
        }

        if (done == true) {
            break;
        }
    }

    //finding turn around tiems
    int* TAT = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {

        TAT[i] = BT[i] + WT[i];
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