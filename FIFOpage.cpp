#include<bits/stdc++.h>
using namespace std;
int pageFaults(int pages[],int n,int capacity){
    unordered_set<int>s;
    queue<int>indexes;
    int page_faults=0;
    for(int i=0;i<n;i++){
        if(s.size()<capacity){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
        else{
            if(s.find(pages[i])==s.end()){
                int val=indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}
int main(){
    int capacity;
    cout<<"Enter the capacity: "<<endl;
    cin>>capacity;
    int n;
    cout<<"Enter total number of the pages: "<<endl;
    cin>>n;
    int pages[n];
    cout<<"Enter the values: "<<endl;
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<"Number of page faults= "<<pageFaults(pages,n,capacity)<<endl;
    cout<<"Number of Hits= "<<n-pageFaults(pages,n,capacity)<<endl;
}
//pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2}
//capacity=4
// n=13
