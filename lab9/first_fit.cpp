#include<iostream>
using namespace std;

int main() {
    
    int b;
    cout<<"number of blocks: ";
    cin>>b;
    
    int p;
    cout<<"number of processes: ";
    cin>>p;

    int* block = (int*)malloc(b*sizeof(int));
    cout<<"provide size of blocks: ";
    for(int i=0;i<b;i++) {
        cin>>block[i];
    }

    int* process = (int*)malloc(p*sizeof(int));
    cout<<"provide size of processes: ";
    for(int i=0;i<p;i++) {
        cin>>process[i];
    }

    //for first fit, we will check the blocks and processes in a contiguous manner

    int* unallocated = (int*)malloc(p*sizeof(int));

    for(int i=0;i<p;i++) {

        if(process[i]<=block[i]) {

            block[i] = block[i] - process[i];

            unallocated[i] = 0;
        }
        else {
            unallocated[i] = 1;
        }
    }

    cout<<"remaining memory: ";

    for(int i=0;i<b;i++) {
        cout<<block[i]<<" ";
    }

    cout<<endl;

    cout<<"unallocated processes: "<<endl;

    int counter=0;

    for(int i=0;i<b;i++) {

        if(unallocated[i]!=0) {
            cout<<"process "<<i+1<<" which needed "<<process[i]<<" memory"<<endl;
            counter++;
        }

        if(counter==0) {
            cout<<"none."<<endl;
        }
    }
}