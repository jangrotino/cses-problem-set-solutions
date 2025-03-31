#include<bits/stdc++.h>

using namespace std;

bool mycomp(const pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n_movies;
    int max_watch = 1;

    cin >> n_movies;

    vector<pair<int,int>> movies;

    for(int i = 0; i < n_movies; i++)
    {
        int pom1, pom2;

        cin >> pom1 >> pom2;

        movies.push_back(make_pair(pom1, pom2));
    }

    sort(movies.begin(), movies.end(), mycomp);
    
    int index = 0;

    for(int i = 1; i < n_movies; i++)
    {
        if(movies[index].second <= movies[i].first)
        {
            max_watch++;
            index = i;
        }
    }

    cout << max_watch << endl;

    return 0;
}