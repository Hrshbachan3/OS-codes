#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 
void CSCAN(int arr[], int head, int size, int disk_size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    left.push_back(0);
    right.push_back(disk_size - 1);
 
    for (int i = 0; i < size; i++) {

        if (arr[i] < head) {

            left.push_back(arr[i]);
        }

        if (arr[i] > head) {

            right.push_back(arr[i]);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    for (int i = 0; i < right.size(); i++) {

        cur_track = right[i];

        seek_sequence.push_back(cur_track);
 
        distance = abs(cur_track - head);
 
        seek_count += distance;
 
        head = cur_track;
    }

    head = 0;
 
    seek_count = seek_count + (disk_size - 1);

    for (int i = 0; i < left.size(); i++) {

        cur_track = left[i];
 
        seek_sequence.push_back(cur_track);
 
        distance = abs(cur_track - head);
 
        seek_count = seek_count + distance;

        head = cur_track;
    }
 
    cout << "Seek Sequence is" << endl;
 
    for (int i = 0; i < seek_sequence.size(); i++) {

        cout << seek_sequence[i];

        if(i!=seek_sequence.size()-1) {
            cout<<"->";
        }
    }

    cout<<endl<<"seek time using C-SCAN:"<<seek_count<<endl;
}

int main() {
 
    int size;
    cout<<"provide number of requests: ";
    cin>>size;

    int disk_size;
    cout<<"provide disk size: ";
    cin>>disk_size;

    int* A = (int*)malloc(size*sizeof(int));

    int head;
    cout<<"provide position of read/write: ";
    cin>>head;

    cout<<"provide values for queue: ";

    for(int i=0;i<size;i++) {
        cin>>A[i];
    }
 
    CSCAN(A,head,size,disk_size);
}