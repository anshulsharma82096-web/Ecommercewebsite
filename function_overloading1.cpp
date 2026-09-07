#include <bits/stdc++.h>
using namespace std;
class Employee{
    int Id;
    string name;
    string department;
    double salary;
public:
    Employee(){
        Id=0;
        name="unknown";
        department="Not Assigned";
        salary=0;
    }
    Employee(int Id,string name){
        this->Id=Id;
        this->name=name;
    }
    Employee(int Id,string name,string department,double salary){
        this->Id=Id;
        this->name=name;
        this->department=department;
        this->salary=salary;
    }
    void display();
    double BaseSalary(){
        cout<<"\nBase salary->"<<salary;
        return salary;
    }
    double calculatepay(double bonus){
        double total=salary+bonus;
        cout<<"\nBase salary+Bonus->"<<total;
        return total;
    }
    double calculatepay(int hour,double hourlyrate){
        double total=salary+(hour*hourlyrate);
        cout<<"\nsalary+overtime_pay->"<<total;
        return total;
    }
    double calculatepay(double bonus,double taxpercentage){
        double basesalary=salary+bonus;
        double tax=basesalary*taxpercentage/100;
        double total=basesalary-tax;
        cout<<"\nsalary after tax->"<<total;
        return total;
    }
    void updateprofile(string d){
        department=d;
        cout<<"\nDepartment Updated successfully";
    }
    void updateprofile(double s){
        salary=s;
        cout<<"\nSalary updated successfully";
    }
    void updateprofile(string d,double s){
        department=d;
        salary=s;
        cout<<"\nsalary and department updated successfully";
    }
    

};
void Employee::display(){
    cout<<"\nId->"<<Id;
    cout<<"\nName->"<<name;
    cout<<"\ndepartment->"<<department;
    cout<<"\nSalary->"<<salary;
}

int main(){
    Employee e1;
    e1.display();
    Employee e2(3345,"Anshul");
    e2.display();
    Employee e3(3456,"Aman","IT",76500.00);
    e3.display();
    e3.BaseSalary();
    e3.calculatepay(90000.00);
    e3.calculatepay(3,1200.00);
    e3.calculatepay(90000.00,18.00);
    e3.updateprofile("Civil");
    e3.updateprofile(56000.00);
    e3.updateprofile("Electrical",50000.00);
    return 0;


}