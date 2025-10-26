class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= balance.size() && account1 > 0 &&
            account2 <= balance.size() && account2 > 0) {
            if (balance[account1 - 1] >= money) {
                balance[account1 - 1] -= money;
                balance[account2 - 1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
         if (account <= balance.size() && account > 0) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= balance.size() && account > 0) {
            if (balance[account - 1] >= money) {
                balance[account - 1] -= money;
                return true;
            }
        }
        return false;
    }
};

