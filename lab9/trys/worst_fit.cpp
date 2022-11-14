#include<iostream>
#include<bits/stdc++.h>
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

    //sorted blocks for reference
    int* sorted_block = (int*)malloc(b*sizeof(int));
    for(int i=0;i<b;i++) {
        sorted_block[i]=block[i];
    }
    sort(sorted_block,sorted_block+b,greater<int>());

    int* decider = (int*)malloc(b*sizeof(int));
    int* final_memory = (int*)malloc(b*sizeof(int));

    for(int i=0;i<b;i++) {

        for(int j=0;j<p;j++) {

            decider[j]=sorted_block[i]-process[j];

            if(decider[j]<0) {
                decider[j]=0;
            }
        }

        int temp=0;
        int zerocount=0;

        for(int j=0;j<p;j++) {
                
            if(decider[j]!=0) {
                if(decider[j]>temp) {
                    temp = decider[j];
                }
            }
            else {
                zerocount++;
            }
        }

        if(zerocount!=p) {
                
            for(int j=0;j<b;j++) {

                if(sorted_block[i]==block[j]) {

                    final_memory[j] = temp;
                }
            }
        }
        else {
            
            for(int j=0;j<b;j++) {

                if(sorted_block[i]==block[j]) {

                    final_memory[j] = block[j];
                }
            }
        }
        process[i]=0;
    }

    cout<<"final memory: ";

    for(int i=0;i<b;i++) {
        cout<<final_memory[i]<<" ";
    }

    cout<<endl;
}