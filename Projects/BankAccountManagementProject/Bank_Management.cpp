#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
    public:
        string account_holder;
        string address;
        int age;
        int account_number;
    protected:
        int balance;
    private:
        string password;
    public:
        BankAccount(string account_holder, string address, int age, string password)
        {
            this->account_holder = account_holder;
            this->address = address;
            this->age = age;
            this->password = password;
            this->account_number = rand()%100000000;
            this->balance = 0;
            cout << this->account_holder << "'s account no is " << this->account_number << endl;
        }
        int checkPassword(string pass)
        {
            if(this->password == pass)
                return 1;
            else
                return 0;
        }
        int show_balance(string password)
        {
            if(this->password == password)
                return this->balance;
            else
                return -1;
        }
        void add_money(string password, int amount)
        {
            if (amount < 0)
            {
                cout << "Invalid amount" << endl;
                return;
            }
            if(this->password == password)
            {
                this->balance += amount;
                cout << "Money added successfully" << endl;
            }
            else
                cout << "Password didn't matched!" << endl;
        }
        void deposit_money(string password, int amount)
        {
            if (amount < 0)
            {
                cout << "Invalid amount" << endl;
                return;
            }
            if (this->balance < amount)
            {
                cout << "Insufficient amount" << endl;
                return;
            }
            if(this->password == password)
            {
                this->balance -= amount;
                cout << "Deposit money successfully" << endl;
            }
            else
                cout << "Password didn't matched!" << endl;
        }
        
        friend class MyCash;
};

class MyCash
{
    protected:
        int balance;
    public:
        MyCash()
        {
            this->balance = 0;
        }
        void add_money_form_bank(BankAccount *myAccount, string password, int amount)
        {
            if (amount < 0)
            {
                cout << "Invalid amount" << endl;
                return;
            }
            if (myAccount->balance < amount)
            {
                cout << "Insufficient amount" << endl;
                return;
            }
            if (myAccount->password == password)
            {
                this->balance += amount;
                myAccount->balance -= amount;
                cout << "Add money form bank is successful." << endl;
            }
            else
                cout << "Password didn't match" << endl;
        }
        int show_balance()
        {
            return balance;
        }
};

BankAccount* create_account()
{
    string account_holder, password, address;
    int age;
    cout << "Create Account" << endl;
    cout << "Name: ";
    cin >> account_holder;
    cout << "Address: ";
    cin >> address;
    cout << "Age: ";
    cin >> age;
    cout << "Password: "; 
    cin >> password;
    BankAccount *myAccount =new BankAccount(account_holder, address, age, password);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "Add Money" << endl;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Enter amount of money: ";
    cin >> amount;
    cout << endl;
    myAccount->add_money(password, amount);
    cout << "Your bank balance is " << myAccount->show_balance(password) << endl << endl;
}
void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "Deposit Money" << endl;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Enter amount of money: ";
    cin >> amount;
    cout << endl;
    myAccount->deposit_money(password, amount);
    cout << "Your bank balance is " << myAccount->show_balance(password) << endl << endl;
}

void add_money_form_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "Add Money From Bank" << endl;
    cout << "Please enter your password: ";
    cin >> password;
    cout << "Enter amount of money: ";
    cin >> amount;
    cout << endl;
    myCash->add_money_form_bank(myAccount, password, amount); 
    cout << "Your bank balance is " << myAccount->show_balance(password) << endl << endl;  
    cout << "MyCash balance is " << myCash->show_balance() << endl;
}

int main()
{
    int n;
    cout << "Number of account: ";
    cin >> n;
    BankAccount *myAccount[n];
    MyCash *myCash[n];
    for (int i = 0; i < n; i++)
    {
        myAccount[i] = create_account();
        myCash[i] = new MyCash();
        cout << endl;
    }
    int flag=1;
    while (flag)
    {
        cout << endl << "Select option:" << endl;
        cout << " 1. Login in any account" << endl;
        cout << " 0. Exit" << endl;
        int check, accNum;
        string pass;
        cout << "Enter option: ";
        cin >> check;
        if (check == 1)
        {
            cout << "Enter account number: ";
            cin >> accNum;
            cout << "Enter password: ";
            cin >> pass;
            cout << endl;
            int find = 0;
            for (int i = 0; i < n; i++)
            {
                if(myAccount[i]->account_number==accNum)
                {
                    if(myAccount[i]->checkPassword(pass) == 1)
                    {
                        find=1;
                        int start=1;
                        while (start)
                        {
                            cout << "Select Option:" << endl;
                            cout << " 1. Add money to bank" << endl;
                            cout << " 2. Deposit money from bank" << endl;
                            cout << " 3. Add money to MyCash from bank" << endl;
                            cout << " 0. To exit" << endl;
                            int option;
                            cout << "Enter option: ";
                            cin >> option;
                            if(option == 1)
                                add_money(myAccount[i]);
                            else if(option == 2)
                                deposit_money(myAccount[i]);
                            else if(option == 3)
                                add_money_form_bank(myCash[i], myAccount[i]);
                            else if(option == 0)
                                break;
                            else
                                cout << "Invalid option" << endl << endl;
                        }
                        
                    }

                }
            }
            if(find==0)
                cout << "Invalid account number or password!" << endl << endl;
        }
        else if(check == 0)
            break;
        else 
            cout << "Invalid input!" << endl;
    }

    // BankAccount *myAccount = create_account();
    // MyCash *myCash = new MyCash();
    // Flag: 
    //     cout << "Select Option:" << endl;
    //     cout << " 1. Add money to bank" << endl;
    //     cout << " 2. Deposit money from bank" << endl;
    //     cout << " 3. Add money to MyCash from bank" << endl;
    //     cout << " 0. To exit" << endl;
    //     int option;
    //     cin >> option;
    //     if(option == 1)
    //         add_money(myAccount);
    //     else if(option == 2)
    //         deposit_money(myAccount);
    //     else if(option == 3)
    //         add_money_form_bank(myCash, myAccount);
    //     else if(option == 0)
    //         goto exitLoop;
    //     else
    //         cout << "Invalid option" << endl;
    //     goto Flag;
    //     exitLoop:
    
    return 0;
}