#include <bits/stdc++.h>
using namespace std;
class BaseAccount{
    int AccountNumber;
    double balance;
    string Name;
    bool flag;
public:
    BaseAccount(double b,bool f,string n): balance(b),flag(f),Name(n){
        cout<<"Base Constructor is called"<<endl;
    }
    virtual void sendMoney(double amount){
        if(flag){
            cout<<"flagged Account,Money send denied"<<endl;
        }
        else if(balance<amount){
            cout<<"Insufficient balance"<<endl;
        }
        else if(balance>amount){
            balance-=amount;
        }
        else{
            cout<<"Invalid amount"<<endl;
        }
    }
    virtual void receiveMoney(double amount){
        balance+=amount;
        cout<<"Money deposit successfully"<<endl;
    }
    virtual void display(){
        cout<<"Balance->"<<balance;
        cout<<"flagged->"<<(flag?"Yes": "No")<<endl;
    }
    
};
class consumerAccount: public BaseAccount{
public:
    consumerAccount(double b,bool f,string n):BaseAccount(b,f,n){
        cout<<"Overridden constructor called"<<endl;
    }
    void receiveMoney(double amount) override{
        cout<<"consumer send money"<<endl;
        BaseAccount::receiveMoney(amount);   
    }
    void sendMoney(double amount) override{
        cout<<"Consumer receive money"<<endl;
        BaseAccount::sendMoney(amount);
    }
    void display() override{
        cout<<"Consumer account details"<<endl;
        BaseAccount::display();
    }
};
int main(){
    consumerAccount c(5000,true,"Anshul");
    BaseAccount *a=&c;
    a->display();
    a->sendMoney(1000);
    a->receiveMoney(2000);
    a->display();


}
