/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:11:17 by igor              #+#    #+#             */
/*   Updated: 2023/04/25 12:46:19 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"


#include <bitset>
#include <iomanip>

int main(void)
{
	Object a;
	Object const b(10);
	Object const c(42.42f);
	Object const d(b);

	a = Object(1234.4321f);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}