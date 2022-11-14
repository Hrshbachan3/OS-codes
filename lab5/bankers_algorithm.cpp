#include<iostream>
using namespace std;

int main() {

    int p;
    cout<<"number of processes: ";
    cin>>p;
    int r;
    cout<<"number of resources: ";
    cin>>r;


    //forming allocation matrix
    int allocation[p][r]; //already allocated resources

    int* safe_sequence = (int*)malloc(p*sizeof(int));

    for(int i=0;i<p;i++) {
        
        cout<<"provide allocated resources of process "<<i+1<<": ";
        
        for(int j=0;j<r;j++) {
            
            cin>>allocation[i][j];
        }
    }

    //forming max matrix
    int max[p][r]; //maximum need of resources for process to terminate

    for(int i=0;i<p;i++) {
        
        cout<<"provide maximum resources of process "<<i+1<<": ";
        
        for(int j=0;j<r;j++) {
            
            cin>>max[i][j];
        }
    }

    //forming avaliable array
    int available[r]; //initially avaliable (unbound) resources

    cout<<"provide available resources: ";

    for(int i=0;i<r;i++) {
        cin>>available[i];
    }

    //forming need matrix
    int need[p][r]; //need = maximum resources required - pre-allocated resources

    for (int i=0;i<p;i++) {
        for (int j=0;j<r;j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int f[p]; //logic array

    for(int i=0;i<p;i++) {
        f[i]=0;
    }

    int counter=0;

    for (int k=0;k<p;k++) {
        
        for (int i=0;i<p;i++) {

            if (f[i]==0) {

                int flag=0;
                
                for (int j=0;j<r;j++) {

                    if (need[i][j] > available[j]) {
                        
                        flag = 1;

                        break; //for 1 process
                    }
                }

                if(flag==0) {

                    safe_sequence[counter] = i;
                    counter++;

                    for (int y=0;y<r;y++) {
    
                        available[y] = available[y] + allocation[i][y];
                            
                        f[i]=1;
                    }
                }
            }
        }
    }
   

    // To check for deadlock
    int checker=0;

    for(int i=0;i<p;i++) {
    
        if(f[i]!=1) {
            checker++;
        }
    }

    if(checker==0) {
        cout<<"all processes will execute sequentially."<<endl;

        cout<<"possible safe sequence: ";
        for(int i=0;i<p;i++) {

            if(i==p-1) {
                cout<<safe_sequence[i]+1;
            }
            else {
                cout<<safe_sequence[i]+1<<"->";
            }
        }
    }
    else {
        cout<<"deadlock occurs."<<endl;
    }

    cout<<endl;
}