/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:15:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 14:19:23 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"
#include <unistd.h>

int main(void)
{
	CPUModule cpu;

	while (true)
	{
		std::cout << static_cast<float>(cpu.GetCPULoad()) << std::endl;
		getchar();
	}
}
