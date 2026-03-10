#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job{
    char id;
    int deadline, profit;
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

int main(){
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registration Number: 24BCE2198"<<endl;
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;

    if(n<=0){ cout<<"Invalid input"; return 0; }

    vector<Job> j(n);
    for(int i=0;i<n;i++){
        cin>>j[i].id>>j[i].deadline>>j[i].profit;
        if(j[i].deadline<=0 || j[i].profit<0){
            cout<<"Invalid input";
            return 0;
        }
    }

    sort(j.begin(),j.end(),cmp);

    int maxd=0, profit=0;
    for(int i=0;i<n;i++)
        maxd=max(maxd,j[i].deadline);

    vector<char> slot(maxd+1, '-');

    for(int i=0;i<n;i++)
        for(int t=min(maxd,j[i].deadline);t>0;t--)
            if(slot[t]=='-'){
                slot[t]=j[i].id;
                profit+=j[i].profit;
                break;
            }

    cout<<"Scheduled Jobs: ";
    for(int i=1;i<=maxd;i++)
        if(slot[i]!='-') cout<<slot[i]<<" ";

    cout<<"\nMax Profit = "<<profit;
}