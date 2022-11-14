#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"number of processes: ";
    cin>>n;
    int m;
    cout<<"number of resources: ";
    cin>>m;


    //forming allocation matrix
    int allocation[n][m]; //already allocated resources

    int* safe_sequence = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++) {
        
        cout<<"provide allocated resources of process "<<i+1<<": ";
        
        for(int j=0;j<m;j++) {
            
            cin>>allocation[i][j];
        }
    }

    //forming max matrix
    int max[n][m]; //maximum need of resources for process to terminate

    for(int i=0;i<n;i++) {
        
        cout<<"provide maximum resources of process "<<i+1<<": ";
        
        for(int j=0;j<m;j++) {
            
            cin>>max[i][j];
        }
    }

    //forming avaliable array
    int available[m]; //initially avaliable (unbound) resources

    cout<<"provide available resources: ";

    for(int i=0;i<m;i++) {
        cin>>available[i];
    }

    //forming need matrix
    int need[n][m]; //need = maximum resources required - pre-allocated resources

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int f[n]; //logic array

    for(int i=0;i<n;i++) {
        f[i]=0;
    }

    int counter=0;

    for (int k=0;k<n;k++) {
        
        for (int i=0;i<n;i++) {

            if (f[i]==0) {

                int flag=0;
                
                for (int j=0;j<m;j++) {

                    if (need[i][j] > available[j]) {
                        
                        flag = 1;

                        break;
                    }
                }

                if(flag==0) {

                    safe_sequence[counter] = i;
                    counter++;

                    for (int y=0;y<m;y++) {
    
                        available[y] = available[y] + allocation[i][y];
                            
                        f[i]=1;
                    }
                }
            }
        }
    }
   

    // To check for deadlock
    int checker=0;

    for(int i=0;i<n;i++) {
    
        if(f[i]!=1) {
            checker++;
        }
    }

    if(checker==0) {
        cout<<"all processes will execute sequentially."<<endl;

        cout<<"possible safe sequence: ";
        for(int i=0;i<n;i++) {

            if(i==n-1) {
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