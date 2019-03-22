#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVV(const vector < vector <char> > &);

void fillVV(vector <vector <char> > &);
void caseBaseBigExpression(vector <char> bigExpression, vector < vector <char> > & casoBaseExpresionGrande);
std::vector < vector <char> > pruebaRecursionGrande(vector < vector<char> > expression, vector<vector<char> > outerVector);


int main()
{
    vector < vector <char> > expresionGrande;
    fillVV(expresionGrande);

//    printVV(expresionGrande);

    vector < vector <char> > casoBaseExpresionGrande;
    for (int i = 0; i < expresionGrande.size(); ++i) {
        caseBaseBigExpression(expresionGrande[i], casoBaseExpresionGrande);
    }

//    printVV(casoBaseExpresionGrande);

    vector < vector <char> > result;
    result = pruebaRecursionGrande(expresionGrande, casoBaseExpresionGrande);
    printVV(result);
//    result = pruebaRecursionGrande(expresionGrande, result);
//    printVV(result);

    return 0;
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

void recursionExtra(vector < vector <char> > & newResult, vector < vector<char> > bigVectorExpression )
{
    vector <char> singleExpression;
    vector < vector <char> > newVector;
    vector <char> singleNewResult;
    vector <char> tmp;
    for (int i = 0; i < bigVectorExpression.size(); ++i) {
        singleExpression = bigVectorExpression[i];
        for (int j = 0; j < newResult.size(); ++j) {
            singleNewResult = newResult[j];
            for (int k = 0; k < singleExpression.size(); ++k) {
                if(singleExpression[k] == 'a' || singleExpression[k] == 'b' || singleExpression[k] == 'c'){
                    tmp.push_back(singleExpression[k]);
                }else{
                    for (int l = 0; l < singleNewResult.size(); ++l) {
                        tmp.push_back(singleNewResult[l]);
                    }
                }
            }
            newVector.push_back(tmp);
        }
    }
}


std::vector < vector <char> > pruebaRecursionGrande(vector < vector<char> > bigVectorExpression, vector<vector<char> > casoBaseExpresionGrande)
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
//    recursionExtra(newVector, bigVectorExpression);
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
