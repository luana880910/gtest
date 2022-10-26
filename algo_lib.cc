#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string Walktober(string str)
{
  istringstream is(str);
  int T;
  is >> T;
  string output = "";
  for (int i = 1; i < T + 1; i++)
  {
    int M, N, P;
    is >> M;
    is >> N;
    is >> P;
    int table[M + 1][N];
    int totalnum = 0;
    for (int j = 1; j < M + 1; j++)
    {
      for (int k = 0; k < N; k++)
      {
        is >> table[j][k];
      }
    }
    for (int j = 0; j < N; j++)
    {
      int maxnum = 0;
      for (int k = 1; k < M + 1; k++)
      {

        if (table[k][j] > maxnum)
        {
          maxnum = table[k][j];
        }
      }
      if (table[P][j] < maxnum)
      {
        totalnum += maxnum - table[P][j];
      }
    }
    // cout << "Case #" << i << ": " << totalnum << "\n ";

    output += "Case #" + to_string(i) + ": " + to_string(totalnum);
    if (i != T)
      output += "\n";
  }
  return output;
}