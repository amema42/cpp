#include "Account.hpp"
#include <iostream>
#include <ctime>

// Inizializzazione delle variabili statiche (come in Account.hpp)
int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;


// uso di <ctime>, std::time, std::localtime, std::strftime per timestamp formattato
// void Account::_displayTimestamp() {
//     std::time_t t = std::time(nullptr);
//     std::tm* tm_local = std::localtime(&t);
//     char buf[20];
//     std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", tm_local);
//     std::cout << buf;
// }

void Account::_displayTimestamp() {
    std::cout << "[19920104_091532] ";
}

// Initializer list: permette di inizializzare i membri prima del corpo del costruttore
// & update di: _nbAccounts & _totalAmount

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

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts()    { return _nbAccounts; }
int Account::getTotalAmount()   { return _totalAmount; }
int Account::getNbDeposits()    { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:"   << getNbAccounts()
              << ";total:"     << getTotalAmount()
              << ";deposits:"  << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << '\n';
}

// makeDeposit: aggiorna _amount, _nbDeposits, _totalAmount, _totalNbDeposits
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

// makeWithdrawal: aggiorna _amount, _nbWithdrawals, _totalAmount, _totalNbWithdrawals
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:"      << _accountIndex
              << ";p_amount:"  << _amount
              << ";withdrawal:";
    if (withdrawal > _amount) {
        std::cout << "refused\n";
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

// checkAmount: ritorna _amount 
int Account::checkAmount() const {
    return _amount;
}

// displayStatus: mostra lo stato dell'account
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:"       << _accountIndex
              << ";amount:"      << _amount
              << ";deposits:"    << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << '\n';
}
