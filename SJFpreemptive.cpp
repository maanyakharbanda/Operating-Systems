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
void findSJF(process proc[], int n) {
    int remaining_time[n];
    for(int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }
    int current_time = 0;
    int complete = 0;
    int shortest = 0;
    int minBurst = 9999;
    while(complete < n) {
        minBurst = 9999;
        for(int i = 0; i < n; i++) {
            if(proc[i].arrival_time <= current_time && remaining_time[i] < minBurst && remaining_time[i] > 0) {
                minBurst = remaining_time[i];
                shortest = i;
            }
        }
        remaining_time[shortest]--;
        if(remaining_time[shortest] == 0) {
            complete++;
            proc[shortest].completion_time = current_time + 1;
            proc[shortest].turn_around_time = proc[shortest].completion_time - proc[shortest].arrival_time;
            proc[shortest].waiting_time = proc[shortest].turn_around_time - proc[shortest].burst_time;
        }
        current_time++;
    }
}
void printSJF(process proc[], int n) {
    cout << "SJF Scheduling (preemptive)" << endl;
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time" << endl;
    for(int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t\t" << proc[i].arrival_time << "\t\t" << proc[i].burst_time << "\t\t"
             << proc[i].completion_time << "\t\t" << proc[i].turn_around_time << "\t\t" << proc[i].waiting_time << endl;
    }
}
int main() {
    int n = 4; 
    process proc[n];
    cout << "Enter process details: (Id, Arrival, Burst)" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Enter processes: " << i + 1 << endl;
        cin >> proc[i].pid >> proc[i].arrival_time >> proc[i].burst_time;
    }//1,0,6  2,1,4  3,2,2  4,3,3
    findSJF(proc, n);
    printSJF(proc, n);
    return 0;
}
