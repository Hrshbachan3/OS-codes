#include<iostream>
using namespace std;

int main() {

    int b;
    cout<<"provide number of blocks: ";
    cin>>b;

    int* block = (int*)malloc(b*sizeof(int));

    cout<<"provide size of blocks: ";

    for(int i=0;i<b;i++) {
        cin>>block[i];
    }


    int p;
    cout<<"provide number  of processes: ";
    cin>>p;

    int* process = (int*)malloc(p*sizeof(int));

    cout<<"provide size of processes: ";

    for(int i=0;i<p;i++) {
        cin>>process[i];
    }

    int* allocated_block_index = (int*)malloc(p*sizeof(int));

    //checker
    for(int i=0;i<p;i++) { //process

        int best_index = -1;

        for(int j=0;j<b;j++) { //block

            if(block[j]>=process[i]) {

                if(best_index == -1) {
                
                    best_index = j;
                }
                else if(block[best_index]>block[j]) {

                    best_index = j;
                }
            }
        }

        if(best_index != -1) {

            allocated_block_index[i] = best_index;

            block[best_index] = block[best_index] - process[i];
        }
    }

    //allcated processes

    cout<<"processes ";
    for(int i=0;i<p;i++) {
        
        if(allocated_block_index[i] != -1) {
            
            cout<<"["<<i+1<<"]"<<" ";
        }
    }
    cout<<"have been allocated to blocks ";
    for(int i=0;i<p;i++) {

        if(allocated_block_index[i] != -1) {

            cout<<"["<<allocated_block_index[i]+1<<"]"<<" ";
        }
    }
    cout<<"respectively."<<endl;

    //unallocated processes

    cout<<"processes ";
    for(int i=0;i<p;i++) {

        if(allocated_block_index[i] == -1) {
            
            cout<<"["<<i+1<<"]"<<" ";
        }
    }
    cout<<"were not allocated."<<endl;

    //printing remain block sizes

    cout<<"The remaing memory blocks are ";
    for(int i=0;i<b;i++) {

        cout<<block[i]<<" ";
    }
    cout<<endl;
}