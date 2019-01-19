/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:15:56 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/19 17:58:55 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include <unistd.h>

int main(void)
{
	CPUModule cpu;
	RAMModule ram;

	while (true)
	{
	/* std::cout << cpu.GetCPULoad() << std::endl; */

		std::cout << "CPU: " << static_cast<float>(cpu.GetCPULoad()) << std::endl;
		std::cout << "RAM: " << static_cast<float>(ram.GetSystemMemoryUsagePercentage()) << std::endl;
		getchar();
	}
}
