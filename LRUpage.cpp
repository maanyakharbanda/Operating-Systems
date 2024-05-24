#include<bits/stdc++.h>
using namespace std;
int pageFaults(int pages[],int n,int capacity){
    unordered_set<int>s;
    unordered_map<int,int>indexes;
    int page_faults=0;
    for(int i=0;i<n;i++){
        if(s.size()<capacity){
            if(s.find(pages[i])==s.end()){
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]]=i;
        }
        else{
            if(s.find(pages[i])==s.end()){
                int lru=INT_MAX,val;
                for(auto it=s.begin();it!=s.end();it++){
                    if(indexes[*it]<lru){
                        lru=indexes[*it];
                        val=*it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;;
            }
            indexes[pages[i]]=i;
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