#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

string Curling(string str)
{

  istringstream is(str);
  int T;
  is >> T;
  string output = "";
  for (int i = 1; i < T + 1; i++)
  {
    int Rs, Rh, N, M;
    vector<pair<double, int>> pairs;
    is >> Rs;
    is >> Rh;
    is >> N;
    for (int j = 0; j < N; j++)
    {
      int x, y;
      is >> x;
      is >> y;
      if (sqrt(x * x + y * y) <= Rh + Rs)
      {
        pairs.push_back(make_pair(sqrt(x * x + y * y), 0));
      }
    }
    is >> M;
    for (int j = 0; j < M; j++)
    {
      int x, y;
      is >> x;
      is >> y;
      if (sqrt(x * x + y * y) <= Rh + Rs)
      {
        pairs.push_back(make_pair(sqrt(x * x + y * y), 1));
      }
    }
    int red = 0;
    int yellow = 0;
    if (pairs.size() != 0)
    {
      sort(pairs.begin(), pairs.end());
      if (pairs[0].second == 0)
      {
        red = 1;
        for (int j = 1; j < pairs.size(); j++)
        {
          if (pairs[j].second == 1)
          {
            break;
          }
          red++;
        }
      }
      else
      {
        yellow = 1;
        for (int j = 1; j < pairs.size(); j++)
        {
          if (pairs[j].second == 0)
          {
            break;
          }
          yellow++;
        }
      }
    }
    output += "Case #" + to_string(i) + ": " + to_string(red) + " " + to_string(yellow) + "\n";
  }
  return output;
}