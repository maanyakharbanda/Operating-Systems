#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[],int n,int c)
{
    int count = 0;
    vector<int> v;
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i <= n - 1; i++) {
        auto it = find(v.begin(), v.end(), pages[i]);
        if (it == v.end()) {
            if (v.size() == c) {
                int min_freq_page = v[0];
                for (int j = 1; j < c; j++) {
                    if (mp[v[j]] < mp[min_freq_page]) {
                        min_freq_page = v[j];
                    }
                }
                v.erase(remove(v.begin(), v.end(), min_freq_page), v.end());
                mp.erase(min_freq_page);
            }
            v.push_back(pages[i]);
            mp[pages[i]]++;
            count++;
        } else {
            mp[pages[i]]++;
        }
    }
    return count;
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
// capacity: 3
// total number of the pages: 7
// Enter the values: 1 2 3 4 2 1 5