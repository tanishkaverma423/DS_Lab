#include <bits/stdc++.h>
using namespace std;
int main(){
int arr[100];
int val;
cout<<"enter no of elements ";
int n;
cin>>n;
cout<<"enter "<<n<<" elements"<<endl;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout << "input a number to insert" << endl;
cin >> val;
    for (int i = n; i >= 0; i--)
    {
        if(arr[i]>val){
            arr[i+1]=arr[i];
            arr[i]=val;
        }
    }
n++;
    for(int i=0;i<n;i++){ 
        cout<<arr[i]<<" ";
    }
return 0;
}