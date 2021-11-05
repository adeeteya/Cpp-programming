#include<bits/stdc++.h>
#include<string>
using namespace std;
int noofaccounts=-1;
class SSNBank{
	char Username[20],Password[20];
	float accbal;
	public:
		friend void registration();
		friend void login();
		void transfer();
		void menu(){
			int choice;float temp;
			while(1){
				cout<<"SSN Coin Transfer Main Menu\n";
				cout<<"1.Deposit Coins\n";
				cout<<"2.Transfer Coins\n";
				cout<<"3.Check Balance\nAnything Else to logout,enter your choice: ";cin>>choice;
				switch(choice)
				{
					case 1:cout<<"Enter the Coins to be deposited: ";cin>>temp;accbal+=temp;cout<<"\n"<<temp<<" number of coins deposited successfully\n";break;
					case 2:transfer();break;
					case 3:cout<<"Coins Present in Account: "<<accbal<<endl;break;
					default:cout<<"Logging out user\n";return;
				}
			}
		}
}accounts[20];
void SSNBank::transfer(){
	char uname[20];int status=0,i;float trans;
	cout<<"Enter the Account Username to Transfer the Coins to: ";cin>>uname;
	for(i=0;i<20;i++){
		if(strcmp(accounts[i].Username,uname)==0){
			status=1;break;
		}
	}
	if(status==1){
		cout<<"Enter the no of coins to Transfer: ";cin>>trans;
		if(trans>accbal){cout<<"Not Enough Balance in the Account\n";return;}
		else{
			accounts[i].accbal+=trans;
			accbal-=trans;
			cout<<"Coins Transferred Successfully\n";
		}
	}
	else{
		cout<<"No Such Account Found\n";return;
	}
}
void registration(){
	char Username[20],Password[20];
	cout<<"SSN Bank Registration Page\n";
	cout<<"Enter your Username: ";cin>>Username;
	for(int i=0;i<20;i++){
		if(strcmp(accounts[i].Username,Username)==0){
			cout<<"Username already Exists please try again\n";return;
		}
	}
	strcpy(accounts[++noofaccounts].Username,Username);
	cout<<"Enter your Password: ";cin>>Password;
	strcpy(accounts[noofaccounts].Password,Password);
	cout<<"Enter the number of coins you are depositing: ";cin>>accounts[noofaccounts].accbal;
}
void login(){
	char Username[20],Password[20];
	int status=0,i=0;
	cout<<"SSN Login Page\n";
	cout<<"Enter your Username: ";cin>>Username;
	for(i=0;i<20;i++){
		if(strcmp(accounts[i].Username,Username)==0){
			status=1;break;
		}
	}
	if(status==0){cout<<"Account Doesn't Exist,Please try again\n";return;}
	cout<<"Enter your Password: ";cin>>Password;
	if(strcmp(accounts[i].Password,Password)==0){cout<<"Logged in Successfully\n";accounts[i].menu();}
	else cout<<"Wrong Password,Please try again!\n";
}
int main()
{
    int choice;
    while(1){
	    cout<<"Enter 1 to Register or 2 to Login and anything else to exit: ";cin>>choice;
	    switch(choice){
	    	case 1:registration();break;
	    	case 2:login();break;
	    	default:cout<<"Thank you for using our bank\n";exit(0);
		}
	}
    return 0;
}
