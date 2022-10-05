#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>A(n);
    vector<int>R;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        A[i]=temp;
    }
    for (int i = 0; i < q; i++)
    {
        int a,b,res;
        cin>>a>>b;
        for (int j =a;b>0&&j<n; j++)
        {
            if(A[j]>A[a-1]){
                b--;
                res=j;
            }
        }
        if(b>0){
            R.push_back(-1);
        }
        else{
            R.push_back(res+1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<R[i]<<endl;
    }
}