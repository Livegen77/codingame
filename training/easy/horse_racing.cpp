#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main()
{
    int MinimumDifference = 100000;
    int puissanceList[100000];
    int N;
    cin >> N; cin.ignore();

    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        puissanceList[i] = Pi;
        //cout << puissanceList[i] << endl;
    }

    qsort((void*)puissanceList, N, sizeof(int), compare);
    
    for (int i = 1; i < N; i++) 
    {
        if((puissanceList[i]-puissanceList[i-1])<MinimumDifference)
            MinimumDifference=(puissanceList[i]-puissanceList[i-1]);
    }
        

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << MinimumDifference << endl;
}
