#include <iostream>
using namespace std;

class Triad {
protected:
	int x, y, z; 
public:
	void add_x() {				//метод увеличения часов.
		if (x==24) {
			x=0;
		}
		else{
			x++;
		}
	}
	void add_y() {				//метод увеличения минут.
		if(y==59) {
			add_x();
			y=0;
		}
		else{
			y++;
		}
	}
	void add_z() {				//метод увеличения секунд.
		if(z==59) {
			add_y();
			z=0;
		}
		else {
			z++;
		}
	}
	void set_hours(int& x){
		this->x=x;
	}
	void set_minuts(int& y){
		this->y=y;
	}
	void set_second(int& z){
		this->z=z;	
	}
	int get_hours(){
		return x;
	}
	int get_minuts(){
		return y;
 	}
 	int get_second(){
 		return z;
 	}
};

class Time :public Triad {
private:
	int hour, minute, second; //переопределить метод увеличения на 1 и увеличение на n секунд и минут.
public:
	Time(){}
	void set(int hour, int minute, int second) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	void setTime(){
		set_hours(hour);
		set_minuts(minute);
		set_second(second);
	}
	void getTime(){
		hour = get_hours();
		minute = get_minuts();
		second = get_second();
	}
	void input() {
		cout << "Введите количество часов: "; cin >> hour;
		cout << "Введите количество минут: "; cin >> minute;
		cout << "Введите количество секунд: "; cin >> second;
		cout << endl;
	}

	void display(){
		cout << "Время: (" << hour << ":" << minute << ":" << second << ")" << endl;
		cout << endl;
	}

	void add_input() {
		int choice;
		int add=0;
		cout << "Введите количество единиц времени: "; cin >> add;
		cout << endl;
		cout << "Введите 1 если добавить в минуты" << endl;
		cout << "Введите 2 если добавить в секунды" << endl;
		cin >> choice;
		setTime();
		if (choice == 1) {
			for(int i=0; i<add; i++){
				add_y();
			}
		}
		else if (choice == 2) {
			for(int i=0; i<add; i++){
				add_z();
			}
		}
		else {
			throw string("Такой команды нет.");
		}
		getTime();
	}
};


int main() {
	int hour, minute, second;
	cout << "Введите количество часов: "; cin >> hour;
	cout << "Введите количество минут: "; cin >> minute;
	cout << "Введите количество секунд:  "; cin >> second;
	Time time1;
	try{
		if(second > 60 || hour > 24 || minute > 60) {
			throw string("Ошибка !!! Введено невереное время");
		}
		else{
			time1.set(hour, minute, second);
		}
	}	
	catch(string mistake){
		cout <<"mistake"<< endl;
	}
	time1.add_input();
	time1.display();
}