#include<bits/stdc++.h>
using namespace std;
int choice,track,no_req,head,head1,distance;
int disc_req[100],finish[100];
void input(){
    int i;
    cout<<"Enter the total number of the tracks: "<<endl;
    cin>>track;
    cout<<"Enter the total number of the disc requests: "<<endl;
    cin>>no_req;
    cout<<"Enter the disc requests: "<<endl;
    for(int i=0;i<no_req;i++){
        cin>>disc_req[i];
    }
    cout<<"Enter the current head position: "<<endl;
    cin>>head1;
}
void sortR(){
    for(int i=0;i<no_req;i++){
        for(int j=0;j<no_req;j++){
            if(disc_req[i]<disc_req[j]){
                int temp=disc_req[i];
                disc_req[i]=disc_req[j];
                disc_req[j]=temp;
            }
        }
    }
}
void FCFS(){
    int distance=0;
    int head=head1;
    cout<<"Current head: "<<head<<endl;
    for(int i=0;i<no_req;i++){
        distance+=abs(head-disc_req[i]);
        head=disc_req[i];
        cout<<head<<endl;
    }
    cout<<"Total Distance travelled: "<<distance<<endl;
}
void SSTF(){
    int min,diff;
    int pending=no_req;
    int distance=0;
    int index;
    int head=head1;
    for(int i=0;i<no_req;i++){
        finish[i]=0;
    }
    cout<<"Current head position: "<<head<<endl;
    while(pending>0){
        min=9999;
        for(int i=0;i<no_req;i++){
            diff=abs(head-disc_req[i]);
            if(finish[i]==0 && diff<min){
                min=diff;
                index=i;
            }
        }
        finish[index]=1;
        distance+=abs(head-disc_req[index]);
        head=disc_req[index];
        pending--;
        cout<<head<<endl;
    }
    cout<<endl;
    cout<<"Total distance travelled is: "<<distance<<endl;
}
void SCAN(){
    int index;
    int dir;
    int distance=0;
    head=head1;
    cout<<"Enter the direction: (0 for the left direction and 1 for the right direction)"<<endl;
    cin>>dir;
    sortR();
    cout<<"Sorted Disc Requests are: "<<endl;
    for(int i=0;i<no_req;i++){
        cout<<disc_req[i]<<" ";
    }
    int i=0;
    while(head>=disc_req[i]){
        index=i;
        i++;
    }
    cout<<"Index: "<<index;
    cout<<"Head: "<<head;
    if(dir==1){
        for(int i=index+1;i<no_req;i++){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        distance+=abs(head-(track-1));
        cout<<(track-1);
        head=track-1;
        for(int i=index;i>=0;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    else{
        for(int i=index;i>=0;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        distance+=abs(head-0);
        head=0;
        for(int i=index+1;i<no_req;i++){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    cout<<endl;
    cout<<"Total Distance Travelled: "<<distance<<endl;
}
void LOOK(){
    int index;
    int dir;
    int distance=0;
    head=head1;
    cout<<"Enter the direction: (0 for the left direction and 1 for the right direction)"<<endl;
    cin>>dir;
    sortR();
    cout<<"Sorted Disc Requests are: "<<endl;
    for(int i=0;i<no_req;i++){
        cout<<disc_req[i]<<" ";
    }
    int i=0;
    while(head>=disc_req[i]){
        index=i;
        i++;
    }
    cout<<"Index: "<<index;
    cout<<"Head: "<<head;
    if(dir==1){
        for(int i=index+1;i<no_req;i++){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        for(int i=index;i>=0;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    else{
        for(int i=index;i>=0;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        for(int i=index+1;i<no_req;i++){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    cout<<endl;
    cout<<"Total Distance Travelled: "<<distance<<endl;
}
void CSCAN(){
    int index;
    int dir;
    int distance=0;
    head=head1;
    cout<<"Enter the direction: (0 for the left direction and 1 for the right direction)"<<endl;
    cin>>dir;
    sortR();
    cout<<"Sorted Disc Requests are: "<<endl;
    for(int i=0;i<no_req;i++){
        cout<<disc_req[i]<<" ";
    }
    int i=0;
    while(head>=disc_req[i]){
        index=i;
        i++;
    }
    cout<<"Index: "<<index;
    cout<<"Head: "<<head;
    if(dir==1){
        for(int i=index+1;i<no_req;i++){
            cout<<disc_req[i]<<endl;
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        distance+=abs(head-(track-1));
        cout<<(track-1);
        head=0;
        distance+=abs(head-disc_req[0]);
        head=disc_req[0];
        for(int i=0;i<index;i++){
            cout<<disc_req[i]<<endl;
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    else{
        for(int i=index;i>=0;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
        distance+=abs(head-0);
        cout<<"0 "<<endl;
        head=0;
        distance+=abs(head-(track-1));
        cout<<(track-1);
        for(int i=(track-1);i>index;i--){
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];
        }
    }
    cout<<endl;
    cout<<"Total Distance Travelled: "<<distance<<endl;
}
void CLOOK(){
    int index;
    int dir;
    int distance=0;
    head=head1;
    cout<<"Enter the direction: (0 for the left direction and 1 for the right direction)"<<endl;
    cin>>dir;
    sortR();
    cout<<"Sorted Disc Requests are: "<<endl;
    for(int i=0;i<no_req;i++){
        cout<<disc_req[i]<<" ";
    }
    int i=0;
    while(head>=disc_req[i]){
        index=i;
        i++;
    }
    cout<<"Index: "<<index;
    cout<<"Head: "<<head;
    if(dir==1)
    {
        for(i=index+1;i<no_req;i++)
        {
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        for(i=0;i<index;i++)
        {
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
    }
    else
    {
        for(i=index;i>=0;i--)
        {
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
        for(i=(no_req-1);i>index;i--)
        {
            cout<<disc_req[i];
            distance+=abs(head-disc_req[i]);
            head=disc_req[i];          
        }
    }
    cout<<endl;
    cout<<"Total Distance Travelled: "<<distance<<endl;
}
int main(){
    cout<<"INPUT"<<endl;
    input();
    cout<<"Enter the choice: "<<endl;
    cout<<"1. FCFS"<<endl;
    cout<<"2. SSTF"<<endl;
    cout<<"3. SCAN"<<endl;
    cout<<"4. LOOK"<<endl;
    cout<<"5. C SCAN"<<endl;
    cout<<"6. C LOOK"<<endl;
    cout<<"7. EXIT"<<endl;
    cin>>choice;
    while(1){
        switch(choice){
             case 1: 
             FCFS();
             break;
             case 2:
             SSTF();
             break;
             case 3: 
             SCAN();
             break;
             case 4:
             LOOK();
             break;
             case 5:
            CSCAN();
             break;
             case 6:
             CLOOK();
             break;
             case 7:
             exit(0);
             break;
             default:
             cout<<"Enter the valid choice: "<<endl;
             break;
        }
    }
    return 0;
}