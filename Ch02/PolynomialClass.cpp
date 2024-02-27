#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Polynomial;

class Term
{
    friend Polynomial;

private:
    float coef;
    int exp;
}

class Polynomial {
    public:
    Polynomial();
    Polynomial Add(Polynomial b);
    void NewTerm(const float theCoeff, const int theExp);
    int Display();
    int GetData();
    private:
    static Term* termArray;
    static int capacity;
    static int free;
    int start, finish;
    int terms;
};

Polynomial::Polynomial()
{
    start = -1;
    finish = -1;
    terms = 0;
}

int Polynomial::Display() {
    int aPos = start;
    for(; aPos <= finish; aPos++) {
        cout << termArray[aPos].coef << "x^" << termArray[aPos].exp;
        if((aPos - finish) != 0) cout <<  " + ";
    }
    cout << "\n";
    return 0;
}

void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    if(terms == capacity) {
        capacity *= 2;
        Term* temp = new Term[capacity];
        copy(termArray, termArray + free, temp);
        delete[] termArray;
        termArray = temp;
    }
    termArray[free].coef = theCoeff;
    termArray[free++].exp = theExp;
}

int Polynomial::GetData() {
    int i, degree;
    float coef;
    int expo;

    cout << "Enter Degree Of Polynomial : ";
    cin >> degree;

    start = free;
    for(i = degree; i > 0; i--) {
        cout << "Enter coefficient of X^" << i << " : ";
        cin >> coef;
        cout << "Enter exponent of X^" << i << " : ";
        cin >> expo;
        NewTerm(coef, expo);
    }
}

Polynomial Polynomial::Add(Polynomial b) {
    Polynomial c;
    int aPos = start, bPos = b.start;
    c.start = free;
    while((aPos <= finish) && (bPos <= b.finish)) {
        if((termArray[aPos].exp == b.termArray[bPos].exp)) {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++;
            bPos++;
        }
        else if ((termArray[aPos].exp <b.termArray[bPos].exp)) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    }
    for(; aPos < finish; aPos++) c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for(; bPos < b.finish; bPos++) c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    c.finish = free = 1;
    return c;
}

int Polynomial::capacity = 100;
Term* Polynomial::termArray = new Term[100];
int Polynomial::free = 0;

int main(void) {
    int choice;
    Polynomial P1, P2, P3, P4;

    cout << "Instruction :- \nExample:-\nP(x)=5x^3+3x^1\nEnter the Polynomial like\nP(x)=5x^3+0x^2+3x^1+0x^0\n";
    cout << "Enter Polynomial1 :- " << endl;
    cin >> P1; //P1.Getdata()
    cout << "Enter Polynomial2 :- " << endl;
    cin >> P2; //P2.Getdata()
    cout << "Enter Polynomial3 :- " << endl;
    cin >> P3; //P3.Getdata()

    while(1) {
        cout << "\n******v Menu Selection ******" << endl;
        cout << "1 : Addition\n2 : Substraction\n3 : Multiplication\n0 : Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
            cout << "\n--------------- Addition ------------------\n";
            cout << "Polynomial1 : ";
            cout << P1; //P1.Display()
            cout << "Polynomial2 : ";
            cout << P2; //P2.Display()
            //P3 = P1.Add(P2)
            cout << "Polynomial3 : ";
            cout << P3; //P3.Display()
            //P4 = P1 + P2 + P3
            cout << "Polynomial4 : ";
            cout << P4; //P4.Display()
            cout << "---------------------------------------------\n";
            break;

            case 2:
            cout << "\n-------------- Substration ----------------\n";
            cout << "Polynomial1 : ";
            cout << P1; //P1.Display()
            cout << "Polynomial2 : ";
            cout << P2; //P2.Display()
            //P3.Substract(P1, P2)
            cout << "Polynomial3 : ";
            cout << P3; //P3.Display()
            //P4 = P1 + P2 + P3
            cout << "Polynomial4 : ";
            cout << P4; //P4.Display()
            cout << "---------------------------------------------\n";
            break;

            case 3:
            cout << "\n------------ Multiplication ---------------\n";
            cout << "Polynomial1 : ";
            cout << P1; //P1.Display()
            cout << "Polynomial2 : ";
            cout << P2; //P2.Display()
            //P3 = P1.Multiply(P2)
            cout << "Polynomial3 : ";
            cout << P3; //P3.Display()
            //P4 = P1 + P2 + P3
            cout << "---------------------------------------------\n";
            break;
            
            case 4:
            cout << "Polynomial4 : ";
            cout << P4; //P4.Eval(5)

            case 0:
            cout << "Good Bye...!!!" << endl;
            exit(0);
        }
    }
    system("pause");
    return 0;
}