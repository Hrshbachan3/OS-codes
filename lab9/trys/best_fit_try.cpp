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

    int decider[m][n]; //2d array stores the differences

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {

            if(process[i]<=block[j]) {
                decider[i][j] = block[j]-process[i];
            }
            else {
                decider[i][j] = 0;
            }
        }
    }

    for(int i=0;i<m;i++) {

        int temp=decider[i][0];

        for(int j=0;j<n;j++) {

            if(decider[i][j]>temp) {
                temp = decider[i][j];
            }
        }

        for(int j=0;j<n;j++) {

            if(decider[i][j]<temp) {
                decider[i][j] = 0;
            }
        }

        for(int j=0;j<n;j++) {
            

        }
    }

    //int* final_memory = (int*)malloc(n*sizeof(int));
    //int counter=0;

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<decider[i][j]<<" ";
        }
        cout<<endl;
    }

    /*for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {

            if(decider[i][j]!=0) {
                final_memory[j]=decider[i][j];
            }
            else {
                counter++;
                if(counter==n) {
                    final_memory[j] = block[j];
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout<<final_memory[i]<<" ";
    }
    cout<<endl;*/
}