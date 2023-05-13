#include <iostream>
#include <vector>
using namespace std;

#include "algorithms/FIFO.hpp"
#include "algorithms/LRU.hpp"
#include "algorithms/OPT.hpp"
#include "algorithms/SCD.hpp"
void testFIFO();
void testLRU();
void testOPT();
void testSCD();


int runFIFO(vector<int>proc, int frames);
int runLRU(vector<int>proc, int frames);
int runSCD(vector<int>proc, int frames);
int runOPT(vector<int>proc, int frames);
void runAll(vector<int>proc, int frames);


int main(){
    // string input;

    // int frames, numOfProcesses;
    int frames=3;
    vector<int> processes={3 ,2 ,1 ,4 ,2 ,1 ,7 ,6 ,2 ,1 ,2 ,3 ,6 ,5 ,1, 2, 3 ,6 ,4 ,2};
    
    runAll(processes, frames);
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
	//   testOPT();
    // testSCD();
    // cout<<"Enter your proceses without spaces(12345): "
}
void runAll(vector<int>proc, int frames){
    cout<<"Page Replacement Algorithms\n";
    cout<<"---------------------------\n";
    cout<<"Frames: "<<frames<<endl;
    cout<<"Processes("<<proc.size()<<"):";
    for(int i=0;i<proc.size();i++){
        cout<<proc[i]<<" ";
    }
    cout<<endl;
    int faults[4];
    string names[4]={"FIFO", "LRU", "SCD", "OPT"};
    faults[0]=runFIFO(proc, frames);
    faults[1]=runLRU(proc, frames);
    faults[2]=runSCD(proc, frames);
    faults[3]=runOPT(proc, frames);

    cout<<"\n\tComparison Chart\n";
    cout<<"---------------------------------\n";
    cout<<"Algorithm|Pages Hits|Page Faults|\n";
    cout<<"---------|----------|-----------|\n";
    for(int i=0;i<4;i++){
        cout<<names[i]<<"   \t |"<<proc.size()-faults[i]<<"\t    |"<<faults[i]<<" \t|\n";
    }
    

}

int runFIFO(vector<int>proc, int frames){
   FIFO fifo;
   fifo.executeFIFO(proc,frames);
   cout<<"FIFO HITS: "<<fifo.getHits()<<endl;
   cout<<"FIFO FAULTS: "<<fifo.getFaults()<<endl<<endl;
   return fifo.getFaults();
}
int runLRU(vector<int>proc, int frames){
   LRU lru;
   lru.executeLRU(proc,frames);
   cout<<"LRU HITS: "<<lru.getHits()<<endl;
   cout<<"LRU FAULTS: "<<lru.getFaults()<<endl<<endl;
   return lru.getFaults();
}
int runSCD(vector<int>proc, int frames){
    SCD scd;
    scd.executeSCD(proc,frames);
    cout<<"\nFaults: "<<scd.getFaults();
    cout<<"Hits: "<<scd.getHits();
    return scd.getFaults(); 
}
int runOPT(vector<int>proc, int frames){
    OPT opt;
    opt.executeOPT(proc,frames);
    cout<<"OPT HITS: "<<opt.getHits()<<endl;
    cout<<"OPT FAULTS: "<<opt.getFaults()<<endl<<endl;
    return opt.getFaults();
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
void testSCD(){
    
    vector<int> proc={2, 5, 10, 1, 2 ,2 ,6, 9 ,1 ,2 ,10, 2, 6, 1, 2, 1 ,6 ,9, 5, 1};
    //vector<int> p1={2 ,5 ,10, 1 ,2 ,2, 6, 9, 1,2, 10, 2, 6, 1 ,2 ,1, 6 ,9 ,5 ,1};
   vector<int> p={3, 2, 1, 4, 2, 1, 7, 6, 2, 1, 2, 3, 6, 5, 1, 2, 3, 6, 4, 2};
    //list l(3);
    SCD test;
    test.executeSCD(p,3);
    cout<<"\nFaults: "<<test.getFaults();
    cout<<"Hits: "<<test.getHits();

}
void testFIFO(){
   cout<<"FIFO TEST\n";
   vector<int>p = {1, 3, 0, 3, 5, 6};
//    {3 ,2 ,1 ,4 ,2 ,1 ,7 ,6 ,2 ,1 ,2 ,3 ,6 ,5 ,1, 2, 3 ,6 ,4 ,2};

   int frames=3;
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