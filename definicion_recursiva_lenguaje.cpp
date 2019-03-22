#include <vector>
#include <iostream>
#include <string>
using namespace std;

// Para imprimir un vector de vectores. Utilizando const y por referencia (para no copiar el vector cada llamada)
void printVV(const vector < vector <char> > &);

// Se pasa un vector de vectores por referencia para llenarlo con caracteres
void fillVV(vector <vector <char> > &);

// La primera iteración de recursión. Se recibe una expresión con la definición de lenguaje y otro vector para almacenar el resultado (por referencia).
void caseBaseBigExpression(vector <char>, vector < vector <char> > &);

// El método de recursión. Regresa un vector de vectores como resultado.
std::vector < vector <char> > recursion(vector<vector<char> >, vector<vector<char> >);

// Para llamar a la función caseBaseBigExpression desde el main.
void callBaseCase(vector <vector <char> >, vector <vector <char> > &);

// Para llamar a la función para la iteración 0.
void callZeroTimes();

// Función booleana para revisar que haya vectores duplicados dentro del vector de vectores de los resultados.
bool cleanVector(const vector <char> &, vector < vector <char> > );

int main()
{
    vector < vector <char> > bigExpression;
    fillVV(bigExpression);
    vector < vector <char> > resultOfRecursion;
    vector < vector <char> > result;
    int n;
    cout << "How many times do you want to iterate? ";
    cin >> n;

    callZeroTimes();
    callBaseCase(bigExpression, resultOfRecursion);

    result = recursion(bigExpression, resultOfRecursion);
    printVV(result);
    cout << "---------------------------------" << endl;

    for (int i = 0; i < n; ++i) {
        result = recursion(bigExpression, result);
        printVV(result);
        cout << "---------------------------------" << endl;
    }

    return 0;
}

void callZeroTimes()
{
    cout << "0 times: λ" << endl;
}

void callBaseCase(vector <vector <char> > bigExpression, vector <vector <char> > & resultOfRecursion )
{
    for (unsigned int i = 0; i < bigExpression.size(); ++i) {
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

bool cleanVector(const vector <char> & vectorResultado, vector < vector <char> > newVector)
{
    for (const auto &i : newVector) {
        if(vectorResultado == i){
            return false;
        }
    }
    return true;
}

std::vector < vector <char> > recursion(vector<vector<char> > bigVectorExpression, vector<vector<char> >  casoBaseExpresionGrande)
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
    for (char i : bigExpression) {
        if (i == 'a' || i == 'b' || i == 'c'){
            tmp.push_back(i);
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