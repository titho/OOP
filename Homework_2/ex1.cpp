#include "ex1.h"



ElectricDevice::ElectricDevice()
{
	name = nullptr;
	kw = 0;
}

ElectricDevice::ElectricDevice(const char * name, int kw)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->kw = kw;
}

ElectricDevice::~ElectricDevice()
{
	delete[] name;
}

ElectricDevice::ElectricDevice(ElectricDevice const & dev)
{
	kw = dev.getKw();
	name = new char[strlen(dev.name) + 1];
	strcpy_s(name, strlen(dev.name) + 1, dev.name);
}

ElectricDevice & ElectricDevice::operator=(ElectricDevice const & dev)
{
	if (this != &dev)
	{
		delete[] name;
		kw = dev.getKw();
		name = new char[strlen(dev.name) + 1];
		strcpy_s(name, strlen(dev.name) + 1, dev.name);
	}
	return *this;
}

void ElectricDevice::setName(char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void ElectricDevice::setKw(int kw)
{
	this->kw = kw;
}

char * ElectricDevice::getName() const
{
	return name;
}

int ElectricDevice::getKw() const
{
	return kw;
}

ElectricNet::ElectricNet(int maxKw)
{
	this->maxKw = maxKw;
	currKw = 0;
	size = 0;
	capacity = MIN_CAPACITY;
	devs = new ElectricDevice[capacity];
}

ElectricNet::~ElectricNet()
{
	delete[] devs;
}

ElectricNet& ElectricNet::operator+=(const ElectricDevice & dev)
{
	if (size >= capacity) {
		resize();
	}

	if ((currKw +  dev.getKw()) <= maxKw)
	{
		devs[size] = dev;
		size++;
		currKw += dev.getKw();
		return *this;
	}
	else
	{
		cout << "Max capacity has been reached!" << endl;
	}
	return *this;
}

ElectricNet & ElectricNet::operator+(const ElectricDevice & dev)
{
	if (size >= capacity) {
		resize();
	}

	if ((currKw + dev.getKw()) <= maxKw)
	{
		ElectricDevice device(dev.getName(), dev.getKw());
		devs[size] = device;
		currKw += dev.getKw();
		size++;
	}
	else
	{
		cout << "Max capacity has been reached!" << endl;
	}
	return *this;
}

ElectricNet & ElectricNet::operator-=(const char* name)
{
	for (int i = 0; i <= size; i++)
	{
		if (devs[i].getName() == name)
		{
			currKw -= devs[i].getKw();
			devs[i] = devs[size];
			size--;
		}
	}
	return *this;
}

ElectricNet & ElectricNet::operator-(const char* name)
{
	for (int i = 0; i <= size; i++)
	{
		if (devs[i].getName() == name)
		{
			currKw -= devs[i].getKw();
			devs[i] = devs[size];
			size--;
		}
	}
	return *this;
}

ElectricDevice & ElectricNet::operator[](const char * name)
{
	int num = 0;
	for (int i = 0; i <= size; i++)
	{
		if (devs[i].getName() == name)
		{
			num = i;
		}
	}
	return devs[num];
}

bool ElectricNet::operator!()
{
	if (size > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ElectricNet::operator++()
{
	maxKw *= 2;
}

void ElectricNet::operator--()
{
	if ((maxKw/2) >= currKw)
	{
		maxKw /= 2;
	}
	else
	{
		cout << "It will overload!" << endl;
	}
}

void ElectricNet::print()
{
	cout << "Max kw: " << maxKw << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Name: " << devs[i].getName() << ", Kw: " << devs[i].getKw() << endl;
	}
}