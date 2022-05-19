#include <iostream>
using namespace std;

class account
{
    private:
        string name;
        int accno;
        string atype;
    public:
        void getAccountdetails()
        {
            cout<<"Enter the customer name: "<<endl;
            cin>>name;
            cout<<"Enter account number: "<<endl;
            cin>>accno;
            cout<<"Enter the account type: "<<endl;
            cin>>atype;
        }
        void displayDetails()
        {
            cout<<"Customer name: "<<name<<endl;
            cout<<"Account name: "<<accno<<endl;
            cout<<"Account type: "<<atype<<endl;
        }
};

class current_account: public account
{
    private: 
        float balance;
        public:
            void c_display()
            {
                cout<<"Balance: "<<balance;
            }
            void c_deposit()
            {
                float deposit;
                cout<<"Enter the amount to deposit: ";
                cin>>deposit;
                balance = balance + deposit;
            }
            void c_withdraw()
            {
                float withdraw;
                cout<<"Balance"<<balance;
                cout<<"Enter the amount to be withdrawn:";
                cin>>withdraw;
                if (balance > 1000)
                {
                    balance = balance - withdraw;
                    cout<<"balance after withdrawal: "<<balance;
                }
                else
                {
                    cout<<"Insufficient balance: ";
                }
            }
};

class saving_account : public account
{
    private:
        float sav_balance;
    public: 
        void s_display()
        {
            cout<<"Balance: "<<sav_balance;
        }
        void s_deposit()
        {
            float deposit, interest;
            cout<<"Balance:- " <<sav_balance;
            cout<<"Enter the amount to deposit: ";
            cin>>deposit;
            sav_balance = sav_balance + deposit;
            interest = (sav_balance*2)/100;
            sav_balance = sav_balance + interest;
        }
        void s_withdraw()
        {
            float withdraw;
            cout << "balance:- " << sav_balance;
            cout<<"Enter the amount to be withdrawn: ";
            cin>>withdraw;
            if (sav_balance > 500)
            {
                sav_balance = sav_balance + withdraw;
                cout << "Balance amount after withdraw: "<<sav_balance;
            }
            else
            {
                cout<<"Insufficient balance: ";

            }
        }
};

int main()
{
    current_account c1;
    saving_account s1;
    char type;
    cout<<"Enter S for saving customer and C for current a/c customer: ";
    cin>>type;
    int choice;
    if(type == 's' || type == 'S')
    {
        s1.getAccountdetails();
        while(1)
        {
            cout<<"Choose your choice"<<endl;
            cout<<"1) Deposit" << endl;
            cout <<"2) Withdraw" << endl;
            cout << "3) Display the balance: "<<endl;
            cout<<"4) Display with full details: "<<endl;
            cout << "5) Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice)
            {
                case 1: 
                    c1.c_deposit();
                    break;
                case 2:
                    c1.c_withdraw();
                    break;
                case 3:
                    c1.c_display();
                case 4:
                    c1.displayDetails();
                    c1.c_display();
                    break;
                case 5:
                    goto end;
                default:
                    cout<< "Entered choice is invalid, try again";
            }
        }
    }
    else
    {
        cout<<"Invalid account selection: ";
    }
    end:
    cout<<"Invalid account selection: ";
    return 0;
}