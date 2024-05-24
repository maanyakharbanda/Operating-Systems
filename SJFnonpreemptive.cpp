#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void findTAT(process proc[],int n){
    for(int i=0;i<n;i++){
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}
void findWT(process proc[],int n){
    for(int i=1;i<n;i++){
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}
void findSJF(process proc[], int n){
    int current_time = 0;
    int completed = 0;
    while (completed < n) {
        int minBurst = INT_MAX; // Initialize with maximum value
        int shortest = -1; // Initialize with invalid index
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].burst_time < minBurst && proc[i].completion_time == 0) {
                minBurst = proc[i].burst_time;
                shortest = i;
            }
        }
        if (shortest == -1) {
            current_time++; // Idle CPU if no process arrived
        } else {
            current_time += proc[shortest].burst_time;
            proc[shortest].completion_time = current_time;
            completed++;
        }
    }
    findTAT(proc,n);
    findWT(proc,n);
}
void printSJF(process proc[], int n) {
    cout << "SJF Scheduling (preemptive)" << endl;
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time" << endl;
    for(int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t"
             << proc[i].completion_time << "\t\t" << proc[i].turn_around_time << "\t\t" << proc[i].waiting_time << endl;
    }
}
int main(){
    int n=5;
    process proc[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    findSJF(proc,n);
    printSJF(proc,n);
}