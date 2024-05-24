#include<bits/stdc++.h>
using namespace std;
struct process{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void findTAT(process proc[], int n){
    for(int i = 0; i < n; i++){
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
    }
}
void findWT(process proc[], int n){
    for(int i = 0; i < n; i++){
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }
}
void findP(process proc[], int n){
    int current_time = 0;
    int completed = 0;
    while(completed < n){
        int highest_priority = INT_MAX;
        int highest_index = -1;
        for(int i = 0; i < n; i++){
            if(proc[i].arrival_time <= current_time && proc[i].completion_time == 0 && proc[i].priority < highest_priority){
                highest_priority = proc[i].priority;
                highest_index = i;
            }
        }
        if(highest_index == -1){
            current_time++; // Idle CPU if no process arrived
        } else {
            proc[highest_index].completion_time = current_time + proc[highest_index].burst_time;
            current_time = proc[highest_index].completion_time;
            completed++;
        }
    }
    findTAT(proc, n);
    findWT(proc, n);
}
void printPriority(process proc[], int n) {
    cout << "Priority Scheduling (non-preemptive)" << endl;
    cout << "PID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurn Around Time\tWaiting Time" << endl;
    for(int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t"
             << proc[i].priority << "\t\t" << proc[i].completion_time << "\t\t" << proc[i].turn_around_time
             << "\t\t" << proc[i].waiting_time << endl;
    }
}
int main(){
    int n = 4;
    process proc[n] = {{1, 0, 2, 1, 0}, {2, 1, 3, 2, 0}, {3, 2, 4, 1, 0}, {4, 3, 1, 3, 0}};
    findP(proc, n);
    printPriority(proc, n);
    return 0;
}