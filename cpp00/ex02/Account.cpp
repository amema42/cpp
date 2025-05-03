#include "Account.hpp"

// Static var init
int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

// PRINT: fixed timestamp to simulate the provided log
void Account::_displayTimestamp() {
    std::cout << "[19920104_091532] ";
}

// Constructor: init account and updates static var
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount << ";created\n";
    ++_nbAccounts;
    _totalAmount += _amount;
}

// Destructor: displays account closure prints
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount << ";closed\n";
}

// GETTERS for static variables
int Account::getNbAccounts()    { return _nbAccounts; }
int Account::getTotalAmount()   { return _totalAmount; }
int Account::getNbDeposits()    { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

// display global info
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:"   << getNbAccounts()
              << ";total:"     << getTotalAmount()
              << ";deposits:"  << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << '\n';
}

// print: deposit: updates: account & static variables
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:"     << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:"  << deposit;
    _amount += deposit;
    ++_nbDeposits;
    _totalAmount      += deposit;
    ++_totalNbDeposits;
    std::cout << ";amount:"      << _amount
              << ";nb_deposits:" << _nbDeposits
              << '\n';
}

// "Withdrawal": updates account & static variables
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:"      << _accountIndex
              << ";p_amount:"  << _amount
              << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused\n";  // checks for insufficient funds:
        return false;
    }
    _amount -= withdrawal;
    ++_nbWithdrawals;
    _totalAmount         -= withdrawal;
    ++_totalNbWithdrawals;
    std::cout << withdrawal
              << ";amount:"        << _amount
              << ";nb_withdrawals:"<< _nbWithdrawals
              << '\n';
    return true;
}


int Account::checkAmount() const {
    return _amount;
}

// Print account status
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex
              << ";amount:"      << _amount
              << ";deposits:"    << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << '\n';
}
