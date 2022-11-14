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

    int* sorted_block = (int*)malloc(b*sizeof(int));
    for(int i=0;i<b;i++) {
        sorted_block[i]=block[i];
    }
    sort(sorted_block,sorted_block+b);


    int* process = (int*)malloc(p*sizeof(int));
    cout<<"provide size of processes: ";
    for(int i=0;i<p;i++) {
        cin>>process[i];
    }

    int* sorted_process = (int*)malloc(b*sizeof(int));
    for(int i=0;i<b;i++) {
        sorted_process[i]=block[i];
    }
    sort(sorted_process,sorted_process+p);

    int* final_memory = (int*)malloc(b*sizeof(int));

    for(int i=0;i<b;i++) {

        int decider[p];

        for(int j=0;j<p;j++) {

            if((block[i]-process[j])>=0) {
                
                decider[j]=sorted_block[i]-sorted_process[j];
            }
            else {
                decider[j]=0;
            }
        }

        int temp=10000;
        int count=0;

        for(int j=0;j<p;j++) {

            if(decider[j]<temp && decider[j]!=0) {
                temp=decider[j];
            }
            else {
                count++;
            }
        }

        if(count==p) {
            final_memory[i]=block[i];
        }
        else {

        int counter=0;

        for(int j=0;j<b;j++) {
            
            if(sorted_block[i]!=block[j]) {
                counter++;
            }
            else {
                break;
            }
        }

        if(temp!=0) {
            final_memory[counter]=temp;
        }
    }
    }

    /*for(int i=0;i<p;i++) {
        cout<<process[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<b;i++) {
        cout<<block[i]<<" ";
    }
    cout<<endl;*/

    cout<<"Final memory: ";

    for(int i=0;i<b;i++) {
        cout<<final_memory[i]<<" ";
    }

    cout<<endl;
}