#include <iostream>
#include <vector>

using namespace std;

// To fill vector
// we're passing everything as a reference! &
void fillVector(vector <int> &);
// To print vector
void printVector(const vector <int> &);
// To search for a value in a vector and replace it with another
void replace(vector <int> &);

int main()
{
    vector < vector <int> > outerVector;
    vector <int> myVector;
    fillVector(myVector);
    outerVector.push_back(myVector);
    vector <int> constantVec = {1};
    outerVector.push_back(constantVec);





/*
    printVector(myVector);
    replace(myVector);
    printVector(myVector);
*/

    return 0;
}

void fillVector(vector<int> & vector ) {
    int input = 0;
    cout << "Type in numbers to fill the vector" << endl;
    cin >> input;
    while( input != -1)
    {
        vector.push_back(input);
        cin >> input;
    }
}

void printVector(const vector <int> & vector)
{
    for (int i : vector) {
        cout << i << " ";
    }
}

void replace(vector<int> & vector)
{
    int old, new_value;
    cout << "Type a value to be replaced and the value to be replaced with: " << endl;
    cin >> old >> new_value;

    for(int i : vector){
        if(vector[i] == old){
            vector[i] = new_value;
        }
    }
}


