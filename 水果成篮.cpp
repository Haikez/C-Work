#include<iostream>
#include<vector>
using namespace std;
int totalFruit(vector<int>& fruits) {
    if(fruits.size()<=2) return fruits.size();
    int bas1=0;
    int bas2=0;
    int count=1,max=0;
    for (int i = 1; i < fruits.size(); i++)
    {
        if (fruits[i]!=fruits[bas1]&&fruits[i]!=fruits[bas2])
        {
            if (bas1!=bas2)
            {
                int j=i-1;
                while (j>bas2&&fruits[j]==fruits[j-1])
                    j--;
                bas1=j;
                bas2=i;
            }else{
                bas2=i;
            }   
        }
        count=i-bas1+1;
        if (max<count)
        {
            max=count;
        }
    }
    return max;
}
int main(){
    vector<int> fruits={1,0,1,4,1,4,1,2,3};
    cout<<totalFruit(fruits);
}