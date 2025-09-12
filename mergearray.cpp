#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"input size of array 1 and array 2"<<endl;
    cin>>n>>m;
    int a[n];
    int b[m];
    int c[n+m];
    int i,j,k=0;
    cout<<"input array 1"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"input array 2"<<endl;
    for(int j=0;j<m;j++){
        cin>>b[j];
    }
    i=0;
    j=0;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;
        k++;
    }
    for(k=0;k<n+m;k++){
        cout<<c[k]<<" ";
    }
}