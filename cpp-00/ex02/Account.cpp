#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
    this->_nbDeposits = 0;
    this->_accountIndex = this->getNbAccounts();
	this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";ammount:"<<this->_amount<<";created"<<std::endl;
    Account::_nbAccounts++;
} 
Account::~Account(void){
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";ammount:"<<this->_amount<<";closed"<<std::endl;
    Account::_nbAccounts--;
}

int     Account::getNbAccounts(void){
    return (_nbAccounts);
}

int     Account::getTotalAmount(void){
    return (_totalAmount);
}

int     Account::getNbDeposits(void){
    return (_totalNbDeposits);
}

int	    Account::getNbWithdrawals(void){
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void){
    Account::_displayTimestamp();
    std::cout<<"accounts:"<<Account::getNbAccounts()<<";total:"<<Account::getTotalAmount()
    <<";deposits:"<<Account::getNbDeposits()<<";withdrawals:"
    <<Account::getNbWithdrawals()<<std::endl;
}

void	Account::makeDeposit(int deposit){
    Account::_displayTimestamp();
    this->_nbDeposits++;
    std::cout<<"p_amount:"<<this->checkAmount()<<";deposit:"<<deposit;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout<<";amount:"<<this->checkAmount()<<";nb_deposits:"<<Account::_nbDeposits;
    std::cout<<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";p_ammount:"<<this->checkAmount();
    if (withdrawal > this->checkAmount())
        std::cout<<";withdrawal:refused;"<<std::endl;
    else
    {
        Account::_totalAmount -= withdrawal;
        Account::_amount -= withdrawal;
        Account::_totalNbWithdrawals++;
        Account::_nbWithdrawals++;
        std::cout<<";withdrawal:"<<withdrawal<<";amount:"<<this->checkAmount()
        <<";Withdrawals:"<<Account::_nbWithdrawals;
        std::cout<<std::endl;
    }
    return (0);
}
int		Account::checkAmount(void) const{
    return (this->_amount);
}

void	Account::displayStatus(void) const{
    Account::_displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex<<";amount:"<<this->checkAmount()
    <<";deposits:"<<this->_nbDeposits
    <<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

void	Account::_displayTimestamp(void){
    time_t  timestamp;

    timestamp = time(NULL);
    std::cout<<"["<<std::put_time(localtime(&timestamp), "%Y%m%d_%H%M%S")<<"]";
}