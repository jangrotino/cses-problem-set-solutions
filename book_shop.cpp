#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int book_num, total_price;

    cin >> book_num >> total_price;

    int prices[book_num] = {};
    int pages[book_num] = {};
    int max_pages_for[book_num + 1][total_price + 1] = {};

    for(int i = 0; i < book_num; i++)
    {
        cin >> prices[i];
    }

    for(int i = 0; i < book_num; i++)
    {
        cin >> pages[i];
    }

    for(int i = 1; i <= book_num; i++)
    {
        for(int j = 1; j <= total_price; j++)
        {
            max_pages_for[i][j] = max_pages_for[i - 1][j];

            if(j >= prices[i - 1])
            {
                max_pages_for[i][j] = max(max_pages_for[i - 1][j - prices[i - 1]] + pages[i - 1], max_pages_for[i][j]);
            }
        }
    }

    for(int i = 0; i <= book_num; i++)
    {
        for(int j = 0; j <= total_price; j++)
        {
           cout << max_pages_for[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}