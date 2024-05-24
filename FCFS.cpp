#include<iostream>
using namespace std;
struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void findCT(process proc[],int n){
    proc[0].completion_time=proc[0].burst_time;
    for(int i=1;i<n;i++){
        proc[i].completion_time=proc[i-1].completion_time+proc[i].burst_time;
    }
}
void findTAT(process proc[],int n){
    for(int i=0;i<n;i++){
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}
void findWT(process proc[],int n){
    proc[0].waiting_time=0;
    for(int i=1;i<n;i++){
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}
void findFCFS(process proc[],int n){
    findCT(proc,n);
    findTAT(proc,n);
    findWT(proc,n);
}
void printFCFS(process proc[],int n){
    cout<<"FCFS Scheduling"<<endl;
    cout<<"PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].completion_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<<endl;
    }
}
// sort using arrival time
int main(){
    int n=5;
    process proc[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    findFCFS(proc,n);
    printFCFS(proc,n);
}