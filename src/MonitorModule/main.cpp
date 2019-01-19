#include </usr/include/sys/sysctl.h>
#include <iostream>

int main(void)
{

	int mib[4];
	int numCPU;
	std::size_t len = sizeof(numCPU); 

	/* set the mib for hw.ncpu */
	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;  // alternatively, try HW_NCPU;

	/* get the number of CPUs from the system */
	sysctl(mib, 2, &numCPU, &len, NULL, 0);

	std::cout << numCPU <<std::endl;
	if (numCPU < 1) 
	{
		mib[1] = HW_NCPU;
		sysctl(mib, 2, &numCPU, &len, NULL, 0);
		if (numCPU < 1)
			numCPU = 1;
	}
}
