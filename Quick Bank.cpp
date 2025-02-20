#include<iostream>
using namespace std;

class BankAccount{
private:
    static const int MAX_ACCOUNTS = 100;
	static int accountNumber[MAX_ACCOUNTS];
    static string accountHolderName[MAX_ACCOUNTS];
    double balance[MAX_ACCOUNTS];
public:
    BankAccount(){
        for(int i=0;i<MAX_ACCOUNTS;i++){
            accountNumber[i]=-1;
            accountHolderName[i]="";
            balance[i]=0.0;
        }
        cout<<"Hi, there user! How can I help you today?"<<endl;
    }
    int createAccount(){
        string name;
        cout<<"Enter your name: ";
        cin>>name;
        for(int i=0;i<MAX_ACCOUNTS;i++){
            if(accountNumber[i]==-1){
                accountNumber[i]=i;
                accountHolderName[i]=name;
                balance[i]=0.0;
                cout<<"Your Account Number is: "<<i<<endl;
                return i;
            }
        }
        cout<<"Account limit reached!"<<endl;
        return -1;
    }
    void deposit(int AccNum){
        if(AccNum<0||AccNum>=MAX_ACCOUNTS||accountNumber[AccNum]==-1){
            cout<<"Account doesn't exist!"<<endl;
            return;
        }
        double amount;
        cout<<"Enter the amount you want to deposit: ";
        cin>>amount;
        if(amount>0){
            balance[AccNum]+=amount;
            cout<<"Deposit Successful!"<<endl;
        }
		else{
            cout<<"Invalid amount!"<<endl;
        }
    }
    void withdraw(int AccNum){
        if(AccNum<0||AccNum>=MAX_ACCOUNTS||accountNumber[AccNum]==-1){
            cout<<"Account doesn't exist!"<<endl;
            return;
        }
        double amount;
        cout<<"Enter the amount you want to withdraw: ";
        cin>>amount;
        if(amount>0&&balance[AccNum]>=amount){
            balance[AccNum]-=amount;
            cout<<"Withdrawal Successful!"<<endl;
        }
		else{
            cout<<"Insufficient balance or invalid amount!"<<endl;
        }
    }
    void displayBalance(int AccNum){
        if(AccNum<0||AccNum>=MAX_ACCOUNTS||accountNumber[AccNum]==-1){
            cout<<"Account doesn't exist!"<<endl;
            return;
        }
        cout<<"Your Balance: "<<balance[AccNum]<<endl;
    }
};

int BankAccount::accountNumber[BankAccount::MAX_ACCOUNTS];
string BankAccount::accountHolderName[BankAccount::MAX_ACCOUNTS];

int menu(){
    int choice;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit Amount"<<endl;
    cout<<"3. Withdraw Amount"<<endl;
    cout<<"4. Display Balance"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    while(choice<1||choice>5){
        cout<<"Invalid option! Try again: ";
        cin>>choice;
    }
    return choice;
}

int main(){
    BankAccount user;
    while(true){
        int choice=menu();
        int AccNum;
        switch(choice){
            case 1:
                AccNum=user.createAccount();
                if(AccNum!=-1){
                    user.deposit(AccNum);
                }
                break;
            case 2:
                cout<<"Enter your Account Number: ";
                cin>>AccNum;
                user.deposit(AccNum);
                break;
            case 3:
                cout<<"Enter your Account Number: ";
                cin>>AccNum;
                user.withdraw(AccNum);
                break;
            case 4:
                cout<<"Enter your Account Number: ";
                cin>>AccNum;
                user.displayBalance(AccNum);
                break;
            case 5:
                cout<<"Thank You for using our services!"<<endl;
                cout<<"HAVE A NICE DAY :)"<<endl;
                return 0;
            default:
                cout<<"System error! Please try again later!"<<endl;
                return 1;
        }
    }
    return 0;
}
