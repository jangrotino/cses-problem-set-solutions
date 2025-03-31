#include<bits/stdc++.h>

using namespace std;

struct lcs
{
    int* prev = nullptr;
    int val = 0;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word1 = " ";
    string word2 = " ";
    string answer = " ";
    lcs pom = {};

    cin >> word1;
    cin >> word2;

    vector<vector<lcs>> matrix(word1.length() + 1, vector<lcs>(word2.length() + 1));

    for(int i = 0; i < word1.length(); i++)
    {
        for(int j = 0; j < word2.length(); j++)
        {
            if(word1[i] == word2[j])
            {
                matrix[i+1][j+1].val = 1 + matrix[i][j+1].val;
                matrix[i+1][j+1].prev = &matrix[i][j].val;
            }
            else
            {
                if(matrix[i][j+1].val >= matrix[i+1][j].val)
                {
                    matrix[i+1][j+1].val = matrix[i][j+1].val;
                    matrix[i+1][j+1].prev = &matrix[i][j+1].val;
                }
                else
                {
                    matrix[i+1][j+1].val = matrix[i+1][j].val;
                    matrix[i+1][j+1].prev = &matrix[i+1][j].val;
                }
            }
        }
    }

    int i = word1.length();
    int j = word2.length();
    pom = matrix[word1.length()][word2.length()];

    while(pom.prev != nullptr)
    {
        if(pom.prev == &matrix[i-1][j-1].val)
        {
            i--;
            j--;
            answer += word1[i];
            pom = matrix[i][j];
        }
        else if (pom.prev == &matrix[i-1][j].val)
        {
            i--;
            pom = matrix[i][j];
        }
        else if(pom.prev == &matrix[i][j-1].val)
        {
            j--;
            pom = matrix[i][j];
        }
    }

    reverse(answer.begin(), answer.end());

    cout << answer <<endl;

    return 0;
}