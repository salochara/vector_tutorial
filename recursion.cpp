#include <iostream>
#include <vector>

using namespace std;

// To fill vector
// we're passing everything as a reference! &
void fillVector(vector <char > &);
std::vector <char> recursion(vector <char> , vector < vector <char> > &);
void recursive_step(vector <char> expression, vector < vector <char> > & outerVector, int index);
void caseBase(vector <char>, vector < vector <char> > &);
void printVV(const vector < vector <char> > &);

std::vector < vector <char> > pruebaRecursion(vector<char>, vector<vector<char> > &outerVector);

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

    /*outerVector = pruebaRecursion(expression, outerVector);
    cout << "imprimiendo la segunda iteración" << endl;
    printVV(outerVector);
    cout << endl;

    outerVector = pruebaRecursion(expression, outerVector);
    cout << "imprimiendo la tercera iteración" << endl;
    printVV(outerVector);
    cout << endl;*/
    int n;
    cout << "Cuantas veces quieres repetirlo ? " << endl;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        outerVector = pruebaRecursion(expression,outerVector);
        cout << "------------" << endl;
        printVV(outerVector);
        cout << endl;
    }


    /*for (int k = 0; k < 2; ++k) {
        vector <char> tmp;
        tmp.push_back(expression.at(k));
        recursive_step(tmp,outerVector, k);
    }
*/
    cout << endl;

    return 0;
}



// esto funciona sin problema con cualquier expresión, pero UNA sola expresión.
std::vector < vector <char> > pruebaRecursion(vector<char> expression, vector<vector<char> > &outerVector)
{
    vector <char> pastOuterVector;
    for (int i = 0; i < outerVector.size(); ++i) {
        for (int j = 0; j < outerVector[i].size(); ++j) {
            pastOuterVector.push_back(outerVector[i][j]);
        }
    }

    vector < vector <char> > newOuterVector;
    vector <char> tmp;
    for (int i = 0; i < expression.size(); ++i) {
        if(expression[i] == 'a' || expression[i] == 'b' || expression[i] == 'c' ){
            tmp.clear();
            tmp.push_back(expression[i]);
            newOuterVector.push_back(tmp);
        } else{
            newOuterVector.push_back(pastOuterVector);
        }
    }
    return newOuterVector;

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
    vector.push_back('u');
}

