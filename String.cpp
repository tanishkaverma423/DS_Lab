#include<iostream>
#include<string.h>
using namespace std;
int main(){
    // string s;
    // cin>>s;
    // cout<<s<<" "<<s.length()<<endl;
    // cout<<s<<" "<<s.size()<<endl;

    int n;
    cout<<"input size of string array"<<endl;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    int size = sizeof(s)/sizeof(s[0]);
    cout<<size<<endl;
}

