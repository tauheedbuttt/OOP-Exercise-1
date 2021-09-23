/*

Exercise 
- Create an Account class that a bank might use to represent customers' bank accounts. he account has 3 attributes: name, account number and balance. Provide set() and get() functions for these attributes. The setBalance() function should validate the initial balance to ensure that it's greater than or equal to 0. If not, set the balance to.
- Provide three other member functions. Member function credit should add an amount to the current balance. Member function debit should withdraw money from the Account and ensure that the debit amount does not exceed the Account's balance. If it does, the balance should be left unchanged.
- Create a program that creates an Account object. Your program should initialise the object to a starting balance, then run continuously offering the user the opportunity to either credit, debit, show balance or exit the program.


*/

#include <iostream>
#include <string>
using namespace std;

class Account{
    string name;
    int accNo;
    float balance;
public:
    //constructor
    Account(){
        name=" ";
        accNo=0;
        balance=0;
    }

    //set functions
    void setName(string value){
        name = value;
    }
    void setAccNo(int value){
        accNo = value;
    }
    bool setBalance(float value){
        if(value >= 0){
            balance = value;
            return true;
        }
        return false;
    }

    //get functions
    string getName(){
        return name;
    }
    int getAccNo(){
        return accNo;
    }
    float getBalance(){
        return balance;
    }

    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Account No: "<<accNo<<endl;
        cout<<"Balance: "<<balance<<endl<<endl;
    }

    //credit = insert money into account
    bool credit(float amount){
        if(amount < 0) return false;
        balance += amount;
        return true;
    }
    //debit = take out money from account
    bool debit(float amount){
        if(amount < 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }
};

void menu(){
    cout<<"\nSelect from Following: \n";
    cout<<"1 -> Credit Cash\n";
    cout<<"2 -> Debit Cash\n";
    cout<<"3 -> Show Balance\n";
    cout<<"0 -> Exit\n";
    cout<<"Choice: ";
}

int main(){
    Account a;
    a.setName("Khoka");
    a.setAccNo(123);
    a.setBalance(100);

    //program
    int choice = 0;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1:{
                float amount = 0;
                cout<<"Enter Ammount you wish to Credit: ";
                cin>>amount;
                if (a.credit(amount) == true){
                    cout<<"Sucessfull\n";
                }
                else{
                    cout<<"Unsucessfull\n";
                }
                break;
            }
            case 2:{
                float amount = 0;
                cout<<"Enter Ammount you wish to Debit: ";
                cin>>amount;
                if (a.debit(amount) == true){
                    cout<<"Sucessfull\n";
                }
                else{
                    cout<<"Unsucessfull\n";
                }
                break;
            }
            case 3:{
                cout<<"Current Balance: "<<a.getBalance()<<endl;
                break;
            }
            case 0:{
                cout<<"Exiting Program...\n";
                break;
            }
            default:{
                cout<<"Invalid Input\n";
            }
        }
    }while(choice!=0);
}