#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class Fraction {
private:
  double count;
  double m;
  double celoe;
  double drob;
public:
  Fraction(double count, double celoe, double drob) {
    this->celoe = celoe;
    this->drob = drob;
    this->count = count;
  }
  Fraction() {
    this->celoe = 0;
    this->drob = 0;
    this->count = 0;
  }
  void todouble() {
      m=celoe+(drob / (pow(10.0,count)));
  }
  double get_double(){
    return m;
  }
};
double Decimal = 0.0;
string fractional;
double s;
double x;

void input() {
  cout << "Введите целую часть: "; cin >> Decimal;
  cout << "Введите дроб  ную часть: "; cin >> fractional;
  s = fractional.length(); //s - количество знаков после запятой
  x = stod(fractional); //stod - string - to double
  Fraction h(s, Decimal, x); //h - первое число
  h.todouble();
  cout << "Введите целую часть: "; cin >> Decimal;
  cout << "Введите дроб  ную часть: "; cin >> fractional;
  s = fractional.length();
  x = stod(fractional);
  Fraction t(s, Decimal, x);
  t.todouble();
  double q=h.get_double();
  double w=t.get_double();
  double summ=q+w;
  cout << "Сложение: "<<summ<<endl;
  double subt = q - w;
  cout << "Вычитание: "<<subt<<endl;
  double multiply = q*w;
  cout<<"Умножение: "<<multiply<<endl;
  if(q<w){
    cout<<"Второе число больше"<<endl;
  }
  else if(q>w){
    cout<<"Первое число больше"<<endl;
  }
  else{
    cout<<"Числа равны"<<endl;
  }
};

int main() {
  input();
}