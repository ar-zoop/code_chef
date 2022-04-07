#include<iostream>
using namespace std;

class person{
	char name[30];
	int age;
	public:
		void getdata(){
			cout<<"Enter name & age: ";
			cin>>name>>age;
		}
		void putdata(){
			cout<<"The deatils are: ";
			cout<<name<<age;
		}
};

int main(){
	int i;
	person x;
	x.getdata();
	x.putdata();
	person p[5];
	for (i=0;i<5;i++){
		p[i].getdata();
		cout<<"The deets are: ";
		p[i].putdata();
	}
	return 0;
}
