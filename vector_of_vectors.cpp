#include <iostream>
#include <vector>
using namespace std;


int main()
{
   // defining a vector of vectors
    vector<vector <int> >outerVector;

    // fill the inner vector and push it back to the outer vector

    for (int i = 0; i < 5; ++i)
    {
        vector <int> innerVector;
        for (int j = 0; j < 3; ++j) {
            // gives an error
            //innerVector[j] = i;
            // should use this
            innerVector.push_back(i);
        }
        outerVector.push_back(innerVector);
    }



    for (int k = 0; k < outerVector.size(); ++k) {
        for (int i = 0; i < outerVector[k].size() ; ++i) {
            cout << outerVector[k][i] << " ";
        }
    }

}

