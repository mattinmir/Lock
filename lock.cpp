#include "lock.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

lock::lock()
{
	std::ifstream infile(".lockdb");
	if (infile.is_open()) // If open, then lock exists, therefore resource is busy
	{
		locked = false;
		std::cout << "Resource is busy" << std::endl;
	}
	else // If not open, no lock exists, resource is free
	{
		std::ofstream outfile(".lockdb");
		if (!outfile.is_open()) // There was some unknown problem making the lock file
		{
			locked = false;
			throw std::runtime_error("Couldn't lock resource");
		}
		else
		{
			locked = true;
			std::cout << "Resource Locked" << std::endl;
		}
	}
}

lock::~lock()
{
	if (locked)
	{
		remove(".lockdb");
		std::cout << "Resource unlocked" << std::endl;
	}
}

bool lock::lock_successful() const
{
	return locked;
}
