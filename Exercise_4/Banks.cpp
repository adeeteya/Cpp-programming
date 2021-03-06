#include<iostream>
using namespace std;
class Customer{
string name;
int age;
long long int phoneno;
public:
  friend class RBI;
};
class Account{
int accno;
int balance;
public:
  friend class RBI;
};
class RBI{
protected:
  Customer c;
  Account a;
  float InterestRate,WithdrawlLimit,MinimumBalance;
public:
  void displaydetails(){
    cout<<"\nCustomer Details\n";
    cout<<"Name: "<<c.name<<"\tAge: "<<c.age<<"\tPhone no: "<<c.phoneno;
    cout<<"\nAccount Details\n";
    cout<<"Account number: "<<a.accno<<"\tBalance: "<<a.balance;
    cout<<"\nBank Details\n";
    cout<<"Interest Rate: "<<InterestRate<<"\tWithdrawl Limit: "<<WithdrawlLimit
    <<"\nMinimum Balance: "<<MinimumBalance<<endl;
  }
  void setCustomerDetails(){
    cout<<"Enter name: ";cin>>c.name;
    cout<<"Enter age: ";cin>>c.age;
    cout<<"Enter phoneno: ";cin>>c.phoneno;
  }
  void setAccountDetails(){
    cout<<"Enter Account number: ";cin>>a.accno;
    cout<<"Enter Balance: ";cin>>a.balance;
  }
  virtual void setInterestRate(){
    cout<<"Enter Interest Rate: ";cin>>InterestRate;
    if(InterestRate<4){
      cout<<"Interest Rate should be atleast 4%,Therefore setting it as it's default value!\n";
      InterestRate=4;}
  }
  virtual void setWithdrawlLimit(){
    cout<<"Enter the Withdraw Limit: ";cin>>WithdrawlLimit;
    if(WithdrawlLimit>50000){
      cout<<"WithDrawal Limit too High,Therefore setting it as it's default value!\n";
      WithdrawlLimit=50000;}
  }
  virtual void setMinimumBalance(){
    cout<<"Enter the Minimum Balance: ";cin>>MinimumBalance;
    if(MinimumBalance<5000){cout<<"Minimum Balance should be atleast 5000rs,Therefore setting it as it's default value!\n";
    MinimumBalance=5000;}
  }
};
class SBI:public RBI{};
class ICICI:public RBI{
public:
  void setInterestRate(){
    cout<<"Enter Interest Rate: ";cin>>InterestRate;
    if(InterestRate<10){
      cout<<"Interest Rate should be atleast 10%,Therefore setting it as it's default value!\n";
      InterestRate=10;}
  }
  void setWithdrawlLimit(){
    cout<<"Enter the Withdrawl Limit: ";cin>>WithdrawlLimit;
    if(WithdrawlLimit>100000){
      cout<<"WithDrawal Limit too High,Therefore setting it as it's default value!\n";
      WithdrawlLimit=100000;}
  }
  void setMinimumBalance(){
    cout<<"Enter the Minimum Balance: ";cin>>MinimumBalance;
    if(MinimumBalance<8000){cout<<"Minimum Balance should be atleast 8000rs,Therefore making the balance 8000rs\n";
    MinimumBalance=8000;}
  }
};
class PNB:public RBI{
public:
  void setInterestRate(){
    cout<<"Enter Interest Rate: ";cin>>InterestRate;
    if(InterestRate<6){
      cout<<"Interest Rate should be atleast 6%,Therefore setting it as it's default value!\n";
      InterestRate=6;}
  }
  void setWithdrawlLimit(){
    cout<<"Enter the Withdrawl Limit: ";cin>>WithdrawlLimit;
    if(WithdrawlLimit>60000){
      cout<<"Withdrawal Amount is too High,Therefore withdrawing only 60000rs\n";
    WithdrawlLimit=60000;}
  }
  void setMinimumBalance(){
    cout<<"Enter the Minimum Balance: ";cin>>MinimumBalance;
    if(MinimumBalance<2000){cout<<"Minimum Balance should be atleast 2000rs,Therefore making the balance 2000rs!\n";
    MinimumBalance=2000;}
  }
};
int main(){
  RBI *r;SBI s;ICICI i;PNB p;
  int choice;
  cout<<"Choose a bank:1.SBI 2.ICICI 3.PNB\nEnter your choice: ";cin>>choice;
  if(choice==1)r=&s;
  else if(choice==2)r=&i;
  else if(choice==3)r=&p;
  r->setCustomerDetails();r->setAccountDetails();
  r->setInterestRate();r->setMinimumBalance();r->setWithdrawlLimit();
  r->displaydetails();
  return 0;
}
