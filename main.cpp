#include <iostream>
#include <vector>
using namespace std;

#include "algorithms/FIFO.hpp"
#include "algorithms/LRU.hpp"
#include "algorithms/OPT.hpp"
//void testFIFO();
//void testLRU();
void testOPT();
int main(){
    // string input;

    // int frames, numOfProcesses;
    // vector<int> processes;

    //code commented out for testing
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

//    testFIFO();
//    testLRU();
	  testOPT();
    // cout<<"Enter your proceses without spaces(12345): "
}
void testFIFO(){
   cout<<"FIFO TEST\n";
   vector<int>p = {3 ,2 ,1 ,4 ,2 ,1 ,7 ,6 ,2 ,1 ,2 ,3 ,6 ,5 ,1, 2, 3 ,6 ,4 ,2};
   int frames=4;
   FIFO fifo;
   fifo.executeFIFO(p,frames);
   cout<<"FIFO HITS: "<<fifo.getHits()<<endl;
   cout<<"FIFO FAULTS: "<<fifo.getFaults()<<endl<<endl;
}
void testLRU(){
   cout<<"LRU TEST\n";
   vector<int>p = {7 ,0 ,1 ,2 ,0 ,3 ,0 ,4 ,2, 3, 0, 3 ,2};
   int frames=4;
   LRU lru;
   lru.executeLRU(p,frames);
   cout<<"LRU HITS: "<<lru.getHits()<<endl;
   cout<<"LRU FAULTS: "<<lru.getFaults()<<endl<<endl;
}
void testOPT(){
	cout<<"OPT TEST\n";
	// vector<int>p={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    //frames=3

	vector<int>p={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

	int frames=4;
    OPT opt;
    opt.executeOPT(p,frames);
    cout<<"OPT HITS: "<<opt.getHits()<<endl;
    cout<<"OPT FAULTS: "<<opt.getFaults()<<endl<<endl;
}
