#include "Harl.hpp"

int main(void)
{
	{
		Harl harl;

		std::cout<<BM<<"-->{TEST 1}"<<std::endl
		<<"calling: debug / info / warning / error / invented_lavel "
		<<W<<std::endl;
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
		harl.complain("doesntexist");
	}
	{
		Harl harl2;

		std::cout<<std::endl
		<<BM<<"----------------------"<<std::endl
		<<"--> {TEST 2}"<<std::endl
		<<"calling: error / debug / [nothing] / warning "
		<<W<<std::endl;
		harl2.complain("error");
		harl2.complain("debug");
		harl2.complain("");
		harl2.complain("warning");
	}
	return 0;
}
