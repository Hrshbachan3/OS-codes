#include<iostream>
#include<bits/stdc++.h>
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
    cout<<"provide number of processes: ";
    cin>>p;

    int* process = (int*)malloc(p*sizeof(int));

    cout<<"provide size of blocks: ";

    for(int i=0;i<p;i++) {
        cin>>process[i];
    }

    int* allocated_block_index = (int*)malloc(p*sizeof(int));

    //checker
    for(int i=0;i<p;i++) { //process

        int worst_index = -1;

        for(int j=0;j<b;j++) { //block

            if(block[j]>=process[i]) {

                if(worst_index == -1) {
                
                    worst_index = j;
                }
                else if(block[worst_index]<block[j]) {

                    worst_index = j;
                }
            }
        }

        if(worst_index != -1) {

            allocated_block_index[i] = worst_index;

            block[worst_index] = block[worst_index] - process[i];
        }
    }

    //allocated processes

    cout<<"processes ";
    for(int i=0;i<p;i++) {
        
        if(allocated_block_index[i]) {
            
            cout<<"["<<i+1<<"]"<<" ";
        }
    }
    cout<<"have been allocated to blocks ";
    for(int i=0;i<p;i++) {

        if(allocated_block_index[i]) {

            cout<<"["<<allocated_block_index[i]+1<<"]"<<" ";
        }
    }
    cout<<"respectively."<<endl;

    //unallocated processes

    cout<<"processes ";
    for(int i=0;i<p;i++) {

        if(!allocated_block_index[i]) {
            
            cout<<"["<<i+1<<"]"<<" ";
        }
    }
    cout<<"were not allocated."<<endl;

    //priting remain block sizes

    cout<<"The remaing memory blocks are ";
    for(int i=0;i<b;i++) {

        cout<<block[i]<<" ";
    }
    cout<<endl;
}