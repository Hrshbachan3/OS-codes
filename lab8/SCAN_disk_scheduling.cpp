#include<iostream>
#include <bits/stdc++.h>
using namespace std;
 
int size = 8;
int disk_size = 200;
 
void SCAN(int arr[], int head, string direction,int size,int disk_size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;

    if (direction == "left") {

        left.push_back(0);
    }
    else if (direction == "right") {

        right.push_back(disk_size - 1);
    }
 
    for (int i = 0; i < size; i++) {

        if (arr[i] < head) {

            left.push_back(arr[i]);
        }
        if (arr[i] > head) {

            right.push_back(arr[i]);
        }
    }
 
    // sorting left and right vectors
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
 
    // run the while loop two times.
    // one by one scanning right
    // and left of the head
    int run = 2;
    while (run--) {

        if (direction == "left") {

            for (int i = left.size() - 1; i >= 0; i--) {

                cur_track = left[i];

                seek_sequence.push_back(cur_track);
 
                distance = abs(cur_track - head);

                seek_count += distance;
 
                head = cur_track;
            }

            direction = "right";
        }
        else if (direction == "right") {

            for (int i = 0; i < right.size(); i++) {

                cur_track = right[i];
                seek_sequence.push_back(cur_track);
 
                distance = abs(cur_track - head);
 
                seek_count = seek_count + distance;

                head = cur_track;
            }

            direction = "left";
        }
    }

    cout << "Seek Sequence is: ";
 
    for (int i = 0; i < seek_sequence.size(); i++) {

        cout <<seek_sequence[i];

        if(i!=seek_sequence.size()-1) {
            cout<<"->";
        }
    }

    cout<<endl<<"Seek time using SCAN: "<<seek_count<<endl;
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

    cout<<"provide traversal direction: ";
    string direction;
    cin>>direction;
 
    SCAN(A,head,direction,size,disk_size);
}