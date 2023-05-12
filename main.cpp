#include <iostream>
#include <vector>
using namespace std;

#include "algorithms/FIFO.hpp"
#include "algorithms/LRU.hpp"
void test();

int main(){
    // string input;

    // int frames, numOfProcesses;
    // vector<int> processes;

    // cout<<"Enter the number of processes: ";
    // cin>>numOfProcesses;
    // cout<<"Enter your processes: ";
    // for(int i=0;i<numOfProcesses;i++){
    //     int temp;
    //     cin>>temp;
    //     processes.push_back(temp);
    // }
    // cout<<"\nEnter the number of frames: ";
    // cin>>frames;

    test();

    // cout<<"Enter your proceses without spaces(12345): "
}
void test(){
    // FIFO fifo;
    vector<int>p = {7 ,0 ,1 ,2 ,0 ,3 ,0 ,4 ,2, 3, 0, 3 ,2};
    // {3 ,2 ,1 ,4 ,2 ,1 ,7 ,6 ,2 ,1 ,2 ,3 ,6 ,5 ,1, 2, 3 ,6 ,4 ,2};
    int frames=4;
    LRU lru;
    lru.executeLRU(p,frames);
    cout<<lru.getHits()<<endl;
    cout<<lru.getFaults()<<endl;
}
