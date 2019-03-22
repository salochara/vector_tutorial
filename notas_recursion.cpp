//
// Created by Salomón Charabati on 3/20/19.
// programa con mas cosas que no neesito para el pryecto... además de pruebas

#include <iostream>
#include <vector>

using namespace std;

// To fill vector
// we're passing everything as a reference! &
void fillVector(vector <char > &);
// To print vector
// void printVector(const vector <int> &);
// To search for a value in a vector and replace it with another
void replace(vector <int> &);

std::vector <char> recursion(vector <char> , vector < vector <char> > &);
void recursive_step(vector <char> expression, vector < vector <char> > & outerVector, int index);

void caseBase(vector <char>, vector < vector <char> > &);
void printVV(const vector < vector <char> > &);

int main()
{
    // se define la expresión
    vector <char> expression;
    fillVector(expression);
    cout << "imprimiendo expresión" << endl;
    for (char i : expression) {
        cout << i << " ";
    }
    cout << endl;

    vector < vector <char> > outerVector;
    caseBase(expression, outerVector);
    cout << "imprimiendo la primer iteración" << endl;
    printVV(outerVector);
    cout << endl;

    //cout << "El caso base es: " << endl;
    //printVV(outerVector);

    for (int k = 0; k < 2; ++k) {
        vector <char> tmp;
        tmp.push_back(expression.at(k));
        recursive_step(tmp,outerVector, k);
    }


    cout << "impeimiendo el outer vector final" << endl;
    printVV(outerVector);

    cout << endl;



    /*  vector < vector <char> > bigVector;
      vector <char> result;

      for (int i = 0; i < expression.size(); ++i) {
          vector <char> tmp;
          tmp.push_back(expression.at(i));
          result = recursion(tmp, outerVector);
          bigVector.emplace(bigVector.cbegin() + i, result);
      }
      cout << "imprimiendo bigVector" << endl;
      printVV(bigVector);
      cout << endl;

      vector < vector <char> > biggerVector;

      for (int j = 0; j < expression.size(); ++j) {
          vector <char> tmp;
          tmp.push_back(expression.at(j));
          result = recursion(tmp, bigVector);
          biggerVector.emplace(biggerVector.cbegin() + j, result);
      }
      cout << "impriminedo biggerVector" << endl;
      printVV(biggerVector);*/
    /* vector <char> result = recursion(expression, outerVector);
     bigVector.push_back(result);
     vector <char> tmp;
     tmp.push_back(expression.at(1));

     result = recursion(tmp, outerVector);
     bigVector.emplace(bigVector.cbegin() + 1, result);*/


    //cout << "El recursivo es: " << endl;
    //printVV(outerVector);




    // declaramos un vector de vectores
    //vector < vector <char> > outerVector;

    //recursion(expression, outerVector);



    /*
     vector < vector <int> > outerVector;
     vector <int> myVector;
     fillVector(myVector);
     outerVector.push_back(myVector);
     vector <int> constantVec = {1};
     outerVector.push_back(constantVec);*/





/*
    printVector(myVector);
    replace(myVector);
    printVector(myVector);
*/

    return 0;
}

void recursive_step(vector <char> single_expression, vector < vector <char> > & outerVector, int index)
{
    vector <char> result;
    for (unsigned int i = 0; i < single_expression.size(); ++i) {
        vector <char> tmp;
        tmp.push_back(single_expression.at(i));
        result = recursion(tmp, outerVector);
        outerVector.emplace(outerVector.cbegin() + index, result);

    }
}


std::vector <char> recursion(vector<char> expression , vector<vector<char> > & outerVector)
{
    vector <char> tmp;
    for (unsigned int i = 0; i < expression.size(); ++i) {
        if (expression[i] == 'a' || expression[i] == 'b' || expression[i] == 'c'){
            tmp.push_back(expression[i]);
        } else{
            for (int j = 0; j < outerVector.size(); ++j) {
                for (int k = 0; k < outerVector[j].size(); ++k) {
                    tmp.push_back(outerVector[j][k]);
                }
            }
        }
        return tmp;
    }
}

void caseBase(vector <char> expression, vector < vector <char> > & outerVector)
{
    for (int i = 0; i < expression.size(); ++i) {
        vector <char> tmp;

        if (expression[i] == 'a' || expression[i] == 'b' || expression[i] == 'c'){
            tmp.push_back(expression[i]);
            outerVector.push_back(tmp);
        }


    }

}

void printVV(const vector < vector <char> > & vec)
{
    for (int k = 0; k < vec.size(); ++k) {
        for (int i = 0; i < vec[k].size() ; ++i) {
            cout << vec[k][i] << " ";
        }
    }
}

void fillVector(vector<char> & vector ) {
    vector.push_back('u');
    vector.push_back('a');
    vector.push_back('v');
    vector.push_back('b');


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




