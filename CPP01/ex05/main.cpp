#include "Harl.hpp"

int main(void)
{
	{
		Harl harl;

		std::cout<<std::endl<<BM<<"◉ -- [TEST 1] -- ◉"<<std::endl
		<<BB<<" *Calling: debug / info / warning / error / invented_lavel."
		<<W<<std::endl<<std::endl;
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
		harl.complain("doesntexist");
	}
	std::cout<<std::endl
	<<W<<"___________________________________"<<std::endl
	<<std::endl
	<<BM<<"\n◉ -- [TEST 2] -- ◉"<<std::endl
	<<BB<<" *Calling: error / debug / [nothing] / warning"
	<<W<<std::endl;
	{
		Harl harl2;

		harl2.complain("error");
		harl2.complain("debug");
		harl2.complain("");
		harl2.complain("warning");
	}
	return 0;
}
