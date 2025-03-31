#include<iostream>
#include<algorithm>

using namespace std;

/*void quicksort(int *time, int begin, int end)
{
    if(begin >= end)
    {
        return;
    }

    int pivot = (begin + end) / 2;
    int i = begin - 1;
    int j = end + 1;

    while(1)
    {
        while(time[pivot] > time[++i]);
        while(time[pivot] < time[--j]);

        if(i <= j)
        {
            swap(time[i], time[j]);
        }
        else
        {
            break;
        }
    }

    quicksort(time, begin, j);
    quicksort(time, i, end);
}*/

int main()
{
    int n = 0;
    long long int sum = 0;

    cin >> n;

    int time[n] = {};

    for(int i = 0; i < n; i++)
    {
        cin >> time[i];
        sum += time[i];
    }

    sort(time, time + n);
    long long int pom_sum = time[n - 1];
    sum -= time[n - 1];
    int counter = n - 1;

    while(pom_sum < sum)
    {
        counter--;
        pom_sum += time[counter];
        sum -= time[counter];
    }

    if(counter == n - 1 || pom_sum == sum)
        cout << pom_sum * 2 << endl;
    else
        cout << pom_sum + sum << endl;

    return 0;
}