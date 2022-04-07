#include <iostream>
using namespace std;
int main(void)
{
    int n, m, flag;
    cin >> n >> m;
    int arr[n], unique[n], count[n];
    int end;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        flag = 0;
        
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == unique[j])
            {
                count[j]++;
                
                flag = 1;
            }
        }
        if (flag == 0)
        {
            end++;
            unique[end] = arr[i];
            count[end] = 1;
        }
    }
    for (int i=0;i<end;i++){
        printf("count= %d, unique= %d",count[i],unique[i]);
    }
}