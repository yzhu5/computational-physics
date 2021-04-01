#include <iostream>

using namespace std;

class Account
{
public:
    Account(string AccName, string AccNum, unsigned Balance);
    void showName(void);
    void showAccNum(void);
    void showBalance(void);
    void Deposit(unsigned money);
    void Withdraw(unsigned money);
private:
    string name;
    string num;
    unsigned balance;

};

Account::Account(string AccName, string AccNum, unsigned Balance)
{
    name = AccName;
    num  = AccNum;
    balance = Balance;
}

void Account::showName(void)
{
    cout << name << endl;
}
void Account::showAccNum(void)
{
    cout << num << endl;
}
void Account::showBalance(void)
{
    cout << balance << endl;
}
void Account::Deposit(unsigned money)
{
    balance +=money;
}
void Account::Withdraw(unsigned money)
{
    if(money > balance)
    {
        cout <<"Money is not enough." << endl;
    }
    else{
        balance -=money;
    }
}


int main()
{
    Account zhuyu("zhuyu", "666", 1000);
    zhuyu.showName();
    zhuyu.showAccNum();
    zhuyu.showBalance();
    zhuyu.Deposit(500);
    zhuyu.Withdraw(1500);
    zhuyu.showBalance();
    return 0;
}
