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
void calculateTAT(process proc[],int n){
    for(int i=0;i<n;i++){
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}
void calculateWT(process proc[],int n){
    for(int i=0;i<n;i++){
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}
void calculateTimes(process proc[],int n,int quantum){
    int remaining_time[n];
    for(int i=0;i<n;i++){
        remaining_time[i]=proc[i].burst_time;
    }
    int current_time=0;
    bool alldone=false;
    while(!alldone){
        alldone=true;
        for(int i=0;i<n;i++){
            if(remaining_time[i]>0){
                alldone=false;
                if(remaining_time[i]>quantum){
                current_time=current_time+quantum;
                remaining_time[i]=remaining_time[i]-quantum;
            }
            else{
                current_time=current_time+remaining_time[i];
                proc[i].completion_time=current_time;
                remaining_time[i]=0;
            }
            }
        }
    }
}
void printRR(process proc[],int n){
    cout<<"FCFS Scheduling"<<endl;
    cout<<"PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t\t"<<proc[i].arrival_time<<"\t\t"<<proc[i].burst_time<<"\t\t"<<proc[i].completion_time<<"\t\t"<<proc[i].turn_around_time<<"\t\t"<<proc[i].waiting_time<<endl;
    }
}
int main(){
    int n;
    int quantum;
    cout<<"Enter the number of the processes: "<<endl;
    cin>>n;
    cout<<"Enter the time quantum: "<<endl;
    cin>>quantum;
    process proc[n];
    for(int i=0;i<n;i++){
        cout<<"Process "<<i+1<<":\n";
        proc[i].pid=i+1;
        cout<<"Arrival Time: "<<endl;
        cin>>proc[i].arrival_time;
        cout<<"Burst Time: "<<endl;
        cin>>proc[i].burst_time;
    }
    calculateTimes(proc,n,quantum);
    calculateTAT(proc,n);
    calculateWT(proc,n);
    cout<<"ROUND ROBIN: "<<endl;
    printRR(proc,n);    
}