/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:16:10 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 10:16:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char const **argv)
{
    int j;

    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            j = -1;
            while (argv[i][++j])
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout<<(char)std::toupper(argv[i][j]);
				else
					std::cout<<argv[i][j];
			}
			std::cout<<" ";
		}
        std::cout<<std::endl;
        return (0);
    }
    std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return (0);
}
