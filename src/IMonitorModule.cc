/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 2019/01/19 23:39:38 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"

#include <stdexcept>

IMonitorModule::IMonitorModule(const std::string name)
	: _name(name) { }

	IMonitorModule::~IMonitorModule() { }

	const std::string IMonitorModule::getName() const {
		return _name;
	}

int IMonitorModule::init() const
{
	throw std::logic_error("Function not yet implemented");
}

int IMonitorModule::exit() const
{
	throw std::logic_error("Function not yet implemented");
}

int IMonitorModule::pump(IMonitorDisplay &display) {
	(void)display;
	throw std::logic_error("Function not yet implemented");
}

std::string		IMonitorModule::getTopInfo(void) 
{
	int filedes[2];
	char foo[4096];

	if (pipe(filedes) == -1) {
		perror("pipe");
		exit();
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		exit();
	} else if (pid == 0) {
		while ((dup2(filedes[1], STDOUT_FILENO) == -1) && (errno == EINTR)) {}
		close(filedes[1]);
		close(filedes[0]);
		execl("/usr/bin/top", "top", "-n 0", 0);
		perror("execl");
		exit();
	}else{
		close(filedes[1]);
		int nbytes = read(filedes[0], foo, sizeof(foo));
		return foo;
	}
	return NULL;
}
