#include<iostream>
using namespace std;
int arrange(int n, int r){ //function to calculate nCr
    if(n-r > r) r=n-r; 
    int i, ans=1;
    for(i=1;i<=r;i++){
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}
int main(){
    int i,j,r,n; cin>>r>>n; // r=no of table; n=no of people
    int a[r], d1, d2, x, y; // array of r tables for storing no of people on every table
    if(n%r==0){ // check if people can be seated equally on all tables
        for(i=0;i<r;i++) a[i]=n/r;
    }
    else{ // otherwise find d1 and d2, the min and max no of people allowed on a table
        d1=n/r; d2=d1+1;
        x=abs((n-d2*r)/(d1-d2));
        y=r-x;
        for(i=0;i<r;i++){
            if(i<x) a[i]=d1;
            else a[i]=d2;
        }
    }
    int p=arrange(n, a[0]); //a[0] people to be selected from n people for table 1
    for(i=1;i<r;i++){
        n=(n-a[i-1]);
        p*=arrange(n, a[i]);//similarly as above for all the tables
    }
    cout<<p;
    return 0;
}
