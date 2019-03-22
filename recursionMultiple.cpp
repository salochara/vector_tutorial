//
// Created by Salomón Charabati on 3/20/19.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// To fill vector
// we're passing everything as a reference! &
void fillVector(vector <char > &);
std::vector <char> recursion(vector <char> , vector < vector <char> > &);
void recursive_step(vector <char> expression, vector < vector <char> > & outerVector, int index);
void caseBase(vector <char>, vector < vector <char> > &);
void printVV(const vector < vector <char> > &);

void fillVV(vector <vector <char> > &);
void caseBaseBigExpression(vector <char> bigExpression, vector < vector <char> > & casoBaseExpresionGrande);
std::vector < vector <char> > pruebaRecursionGrande(vector < vector<char> > expression, vector<vector<char> > outerVector);

std::vector < vector <char> > pruebaRecursion(vector<char>, vector<vector<char> > &outerVector);

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
//    printVV(result);
    result = pruebaRecursionGrande(expresionGrande, result);
    printVV(result);

   /* // se define la expresión
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

    *//*outerVector = pruebaRecursion(expression, outerVector);
    cout << "imprimiendo la segunda iteración" << endl;
    printVV(outerVector);
    cout << endl;

    outerVector = pruebaRecursion(expression, outerVector);
    cout << "imprimiendo la tercera iteración" << endl;
    printVV(outerVector);
    cout << endl;*//*
    int n;
    cout << "Cuantas veces quieres repetirlo ? " << endl;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        outerVector = pruebaRecursion(expression,outerVector);
        cout << "------------" << endl;
        printVV(outerVector);
        cout << endl;
    }


    *//*for (int k = 0; k < 2; ++k) {
        vector <char> tmp;
        tmp.push_back(expression.at(k));
        recursive_step(tmp,outerVector, k);
    }
*//*
    cout << endl;
*/
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
    return newVector;
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

