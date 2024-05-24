#include<bits/stdc++.h>
using namespace std;
void FirstFit(vector<int>&blocksize,int m,vector<int>&processsize,int n){
    vector<int>allocation(n,-1);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        { 
            if (blocksize[j]>=processsize[i]) 
            { 
                allocation[i]=j; 
                blocksize[j] -= processsize[i]; 
                break; 
            } 
        } 
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << " " << i+1 << "\t\t" << processsize[i] << "\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
}
void NextFit(vector<int>&blocksize,int m,vector<int>&processsize,int n){
    vector<int> allocation(n, -1);
    int j = 0, t = m - 1;
    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blocksize[j] >= processsize[i]) {
                allocation[i] = j;
                blocksize[j] -= processsize[i];
                t = (j - 1 + m) % m;
                break;
            }
            if (t == j) {
                t = (j - 1 + m) % m;
                break;
            }
            j = (j + 1) % m;
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t\t\t" << processsize[i] << "\t\t\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}
void BestFit(vector<int>&blocksize,int m,vector<int>&processsize,int n){
    vector<int>allocation(n,-1); 
    for (int i = 0; i < n; i++)  
    {  
        int bestIdx = -1;  
        for (int j = 0;j<m; j++)  
        {  
            if (blocksize[j] >= processsize[i])  
            {  
                if (bestIdx == -1)  
                    bestIdx = j;  
                else if (blocksize[bestIdx] > blocksize[j])  
                    bestIdx = j;  
            }  
        }  
        if (bestIdx != -1)  
        {    
            allocation[i] = bestIdx;  
            blocksize[bestIdx] -= processsize[i];  
        }  
    }  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";  
    for (int i = 0; i < n; i++)  
    {  
        cout << " " << i+1 << "\t\t" << processsize[i] << "\t\t";  
        if (allocation[i] != -1)  
            cout << allocation[i] + 1;  
        else
            cout << "Not Allocated";  
        cout << endl;  
    }  
}
void WorstFit(vector<int>&blocksize,int m,vector<int>&processsize,int n){
    int allocation[n];
    for (int i=0; i<n; i++) 
    { 
        int wstIdx = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (blocksize[j] >= processsize[i]) 
            { 
                if (wstIdx == -1) 
                    wstIdx = j; 
                else if (blocksize[wstIdx] < blocksize[j]) 
                    wstIdx = j; 
            } 
        } 
         if (wstIdx != -1) 
        { 
            allocation[i] = wstIdx; 
            blocksize[wstIdx] -= processsize[i]; 
        } 
    } 
  
    cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << "   " << i+1 << "\t\t" << processsize[i] << "\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
}
int main(){
    int b;
    cout<<"Enter total blocks: "<<endl;
    cin>>b;
    vector<int>blocksize(b);
    cout<<"Enter the blocks size: "<<endl;
    for(int i=0;i<b;i++){
        cin>>blocksize[i];
    }
    int p;
    cout<<"Enter total processes: "<<endl;
    cin>>p;
    vector<int>processsize(p);
    cout<<"Enter the processes size: "<<endl;
    for(int i=0;i<p;i++){
    cin>>processsize[i];
    }
    int m=blocksize.size(); // same as b
    int n=processsize.size(); // same as p
    cout<<"FIRST FIT ALGORITHM"<<endl;
    FirstFit(blocksize,m,processsize,n);
    cout<<"NEXT FIT ALGORITHM"<<endl;
    NextFit(blocksize,m,processsize,n);
    cout<<"BEST FIT ALGORITHM"<<endl;
    BestFit(blocksize,m,processsize,n);
    cout<<"WORST FIT ALGORITHM"<<endl;
    WorstFit(blocksize,m,processsize,n);
}