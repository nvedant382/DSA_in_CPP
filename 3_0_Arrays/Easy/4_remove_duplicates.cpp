#include <iostream>
#include <set>
using namespace std;

int removeDup(int arr[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]); // log(n)* n:size of array
    }
    // S.C. = O(N)
    int index = 0;
    for (auto it : st)
    {
        arr[index] = it;
        index++;
    }

    return index;
}

int removeDup_opt(int arr[], int n)
{
    int i = 0;
    int j = 1;

    /*

    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j]
            i++;
        }
    }
    return i+1;

    */

    while (j < n)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    return i + 1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3};

    cout << removeDup(arr, 7) << endl;
    cout << removeDup_opt(arr, 7) << endl;

    return 0;
}