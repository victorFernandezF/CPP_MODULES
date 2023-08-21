/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:04:26 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 19:04:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "agenda.hpp"

int is_alpha(std::string str){
    for (size_t i = 0; i < str.length(); i++)
        if (std::isdigit(str[i]) == 0)
            return (1);
    return (0);
}

int checkSearchIndex(std::string str){
    int SearchIndex;

	if (str == "exit")
		return (-2);
	if (is_alpha(str) || str[0] == '\0')
        return (0);
    else
        SearchIndex = std::stoi(str);
    if (SearchIndex <= 0 || SearchIndex > 8)
        SearchIndex = -1;
    return (SearchIndex);
}