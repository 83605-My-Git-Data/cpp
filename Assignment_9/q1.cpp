
#include <iostream>
#include <vector>
using namespace std;
enum EAccountType
{
    Saving,
    Current,
    Dmat
};
class InSufficientFundsException
{
public:
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    InSufficientFundsException() : accno(0), currentBalance(0.0), withdrawAmount(0.0)
    {
    }

    InSufficientFundsException(int accno, double currentBalace, double withdrawAmount)
    {
        this->accno = accno;
        this->currentBalance = currentBalance;
        this->withdrawAmount = withdrawAmount;
    }

    void printStackTrace()
    {
        cout << "Insufficient Fund Exception :" << endl;
        cout << "Account Number :" << accno << endl;
        cout << "Current Balance  :" << currentBalance << endl;
        cout << "Withdraw Amount  :" << withdrawAmount << endl;
    }
};

class Account
{
private:
    int accno;
    EAccountType type;
    double balance;

public:
    Account()
    {
    }
    Account(int accno, EAccountType type, double balance = 0)
    {
        this->accno = accno;
        this->type = type;
        this->balance = balance;
    }

    void accept()
    {
        // cout << "Enter Account Number :" ;
        // cin>>accno;
        int choice;
        cout << "*********Enter Account Details*********" << endl;
        cout << "Enter Account Number :" << endl;
        cin >> accno;
        cout << "Enter Account Type :" << endl;
        cout << "Press 0 for Saving Account " << endl;
        cout << "Press 1 for Current Account" << endl;
        cout << "Press 2 for DMAT Account" << endl;
        cout << "Enter your choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            type = EAccountType::Saving;
            break;
        case 1:
            type = EAccountType::Current;
            break;
        case 2:
            type = EAccountType::Dmat;
            break;

        default:
            break;
        }
        cout << "Enter Balance : " << endl;
        cin >> balance;
    }
    int getAccno()
    {
        return accno;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    void display()
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

        cout << " *********Account Details Display********* " << endl;
        cout << "Account Number : " << accno << endl;
        if (type == 0)
        {
            cout << "Account Type : SAVING" << endl;
        }
        else if (type == 1)
        {
            cout << "Account Type : CURRENT" << endl;
        }
        else if (type == 2)
        {
            cout << "Account Type : DMAT" << endl;
        }

        cout << " Account Balance : " << balance << endl;
    }
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw InSufficientFundsException();
        }
        else
            balance = balance + amount;
    }
    void withdraw(double amount)

    {
        if (balance >= 0 || balance < amount)
        {
            throw InSufficientFundsException(accno, balance, amount);
        }
        else
            balance = balance - amount;
    }
};

int main()
{
    int choice;
    int uaccno;
    double amount;
    int index = 0;
    vector<Account *> accountList;

    do
    {
        cout << "----------------------------------------------" << endl;
        cout << "Welcome to the Bank" << endl;
        cout << "********************" << endl;
        cout << "Press 0 for Exit" << endl;
        cout << "Press 1 for Account Create " << endl;
        cout << "Press 2 for Display All Account" << endl;
        cout << "Press 3 for Deposit Money" << endl;
        cout << "press 4 for Withdraw Money " << endl;
        cout << "Enter your choice" << endl;
        cout << "----------------------------------------------" << endl;

        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << " Thank you.." << endl;
            break;
        case 1:
        {
            Account *aptr=new Account();
            aptr->Account::accept();
            accountList.push_back(aptr);
        }
        break;
        case 2:
            for (int i = 0; i < accountList.size(); i++)
            {
                accountList[i]->display();
            }
            break;
        case 3:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

            cout << "Enter the Account Number " << endl;
            cin >> uaccno;
            for (int i = 0; i < accountList.size(); i++)
            {
                if (uaccno == accountList[i]->getAccno())
                {
                    cout << "Enter the Amount you want to deposit" << endl;
                    cin >> amount;
                    cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
                    try
                    {
                        accountList[i]->deposit(amount);
                        cout << amount << "Credited to Account Number " << uaccno << endl;
                    }
                    catch (InSufficientFundsException e)
                    {
                        e.printStackTrace();
                    }
                }
            }
            break;

        case 4:
            cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;

            cout << "Enter the Account Number " << endl;
            cin >> uaccno;
            for (int i = 0; i < accountList.size(); i++)
            {
                if (uaccno == accountList[i]->getAccno())
                {
                    cout << "Enter the Amount you want to withdraw" << endl;
                    cin >> amount;
                    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                    try
                    {
                        accountList[i]->withdraw(amount);
                        cout << "Rs. " << amount << " Debited to Account Number " << uaccno << endl;
                    }
                    catch (InSufficientFundsException e)
                    {
                        cout << "your current Balance is : " << e.currentBalance << "your enter amount is : " << e.withdrawAmount << endl;
                        cout << "Insufficient balance OR wrong amount entered!!" << endl;
                    }
                }
            }
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}
