#include <iostream>

using namespace std;

int main()
{
    int arr_size;
    long long int sum = 0;
    long long int pom = 0;

    cin >> arr_size;

    int tab[arr_size];

    for(int i = 0; i < arr_size; i++)
    {
        cin >> tab[i];
    }

    sum = tab[0];

    for(int i = 0; i < arr_size; i++)
    {
        pom += tab[i];
        sum = max(pom, sum);
        if(pom < 0)
        {
            pom = 0;
        }
    }

    cout << sum << endl;

    return 0;
}