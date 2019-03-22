#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVV(const vector < vector <char> > &);
void fillVV(vector <vector <char> > &);
void caseBaseBigExpression(vector <char> bigExpression, vector < vector <char> > & casoBaseExpresionGrande);
std::vector < vector <char> > recursion(vector<vector<char> > expression, vector<vector<char> > outerVector);
void callBaseCase(vector <vector <char> > bigExpression, vector <vector <char> > & resultOfRecursion );
void callZeroTimes();

int main()
{
    vector < vector <char> > bigExpression;
    fillVV(bigExpression);

    callZeroTimes();
    vector < vector <char> > resultOfRecursion;
    callBaseCase(bigExpression, resultOfRecursion);

    vector < vector <char> > result;
    int n;
    cout << "How many times do you want to iterate? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        result = recursion(bigExpression, resultOfRecursion);
        cout << "----------" << endl;
        printVV(result);
    }
/*

    result = recursion(bigExpression, resultOfRecursion);
    printVV(result);
*/

    return 0;
}

void callZeroTimes()
{
    cout << "0 times: λ" << endl;
}

void callBaseCase(vector <vector <char> > bigExpression, vector <vector <char> > & resultOfRecursion )
{
    for (int i = 0; i < bigExpression.size(); ++i) {
        caseBaseBigExpression(bigExpression[i], resultOfRecursion);
    }
    cout << "1 time: ";
    printVV(resultOfRecursion);
}


void fillVV(vector<vector<char> > & vvExpression) {
    int numberExpressions = 0;
    cout << "How many expressions do you want?" << endl;
    cin >> numberExpressions;
    vector <char> tmp;
    string expression;
    for (int i = 0; i < numberExpressions; ++i) {
        cout << "Type your expressions (with an enter as a divider)" << endl;
        cin >> expression;
        tmp.clear();
        for (int j = 0; j < expression.size(); ++j) {
            tmp.push_back(expression[j]);
        }
        vvExpression.push_back(tmp);
    }
}

bool cleanVector(const vector <char> vectorResultado, vector < vector <char> > newVector)
{
    for (int i = 0; i < newVector.size(); ++i) {
        if(vectorResultado == newVector[i]){
            return false;
        }
    }
    return true;
}

std::vector < vector <char> > recursion(vector<vector<char> > bigVectorExpression, vector<vector<char> > casoBaseExpresionGrande)
{
    vector <vector <char> > newVector;
    vector <char> porComparar;
    vector <char> resultadoComparar;
    vector <char> singleExpression;

    for (int i = 0; i < casoBaseExpresionGrande.size(); ++i) {
        singleExpression = casoBaseExpresionGrande[i];
        for (int j = 0; j < bigVectorExpression.size(); ++j) {
            porComparar = bigVectorExpression[j];
            for (int k = 0; k < porComparar.size(); ++k) {
                if(porComparar[k] == 'a' || porComparar[k] == 'b' || porComparar[k] == 'c'){
                    resultadoComparar.push_back(porComparar[k]);
                }else{
                    for (int l = 0; l < singleExpression.size(); ++l) {
                        resultadoComparar.push_back(singleExpression[l]);
                    }
                }
            }
            if(cleanVector(resultadoComparar, newVector)){
                newVector.push_back(resultadoComparar);
            }
            resultadoComparar.clear();
        }
    }
    return newVector;
}

void caseBaseBigExpression(vector <char> bigExpression, vector < vector <char> > &casoBaseExpresionGrande)
{
    vector <char> tmp;
    for (int i = 0; i < bigExpression.size(); ++i) {
        if (bigExpression[i] == 'a' || bigExpression[i] == 'b' || bigExpression[i] == 'c'){
            tmp.push_back(bigExpression[i]);
        }
    }
    casoBaseExpresionGrande.push_back(tmp);
}


void printVV(const vector < vector <char> > & vec)
{
    for (int k = 0; k < vec.size(); ++k) {
        for (int i = 0; i < vec[k].size() ; ++i) {
            cout << vec[k][i] << " ";
        }
        cout << "| ";
    }
    cout << endl;
}
