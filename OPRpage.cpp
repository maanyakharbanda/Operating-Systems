#include <bits/stdc++.h>
using namespace std;
bool search(int key, vector<int>& fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int>& fr, int pn, int index)
{
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If a page is never referenced in future,
        // return it.
        if (j == pn)
            return i;
    }
    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    return (res == -1) ? 0 : res;
}
void optimalPage(int pg[], int pn, int fn)
{
    // Create an array for given number of
    // frames and initialize it as empty.
    vector<int> fr;
    // Traverse through page reference array
    // and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < pn; i++) {
        // Page found in a frame : HIT
        if (search(pg[i], fr)) {
            hit++;
            continue;
        }
        // Page not found in a frame : MISS
        // If there is space available in frames.
        if (fr.size() < fn)
            fr.push_back(pg[i]);
        // Find the page to be replaced.
        else {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
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
    optimalPage(pages,n,capacity);
}
//pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2}
//capacity=4
// n=13