#include<iostream>
using namespace std;

int main() {
    
    int n;
    cout<<"number of blocks: ";
    cin>>n;
    
    int m;
    cout<<"number of processes: ";
    cin>>m;

    int* block = (int*)malloc(n*sizeof(int));
    cout<<"provide size of blocks: ";
    for(int i=0;i<n;i++) {
        cin>>block[i];
    }

    int* process = (int*)malloc(m*sizeof(int));
    cout<<"provide size of processes: ";
    for(int i=0;i<m;i++) {
        cin>>process[i];
    }

    //for first fit, we will check the blocks and processes in a contiguous manner

    int* unallocated = (int*)malloc(m*sizeof(int));

    for(int i=0;i<m;i++) {

        if(process[i]<=block[i]) {

            block[i] = block[i] - process[i];

            unallocated[i] = 0;
        }
        else {
            unallocated[i] = 1;
        }
    }

    cout<<"remaining memory: ";

    for(int i=0;i<n;i++) {
        cout<<block[i]<<" ";
    }

    cout<<endl;

    cout<<"unallocated processes: "<<endl;

    int counter=0;

    for(int i=0;i<n;i++) {

        if(unallocated[i]!=0) {
            cout<<"process "<<i+1<<" which needed "<<process[i]<<" memory"<<endl;
            counter++;
        }

        if(counter==0) {
            cout<<"none."<<endl;
        }
    }
}