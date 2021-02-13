#include <bits/stdc++.h> 
using namespace std;

class person{
   string name;
   int age;

  public:
   //setters
    person(string name,int age){
        cout<<"constructer called"<<endl;
        this->name=name;
        this->age =age;
    }
    //getters    
    void get(){
        cout<<"name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
    }
    //destructors
    //~person(){}
};

int main(){
    person p1("Ankit",18);
    p1.get();
    // person* ptr("Akhil",21)=new person;
    // ptr.get();
     delete p1;
   return 0;
}