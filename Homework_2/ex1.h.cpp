#pragma once
#include <iostream>
#include <string.h>
using namespace std;
const unsigned MIN_CAPACITY = 32;

class ElectricDevice
{
private:
	char* name;
	int kw;
public:
	ElectricDevice();
	ElectricDevice(const char*, int);
	~ElectricDevice();
	ElectricDevice(ElectricDevice const &);
	ElectricDevice& operator=(ElectricDevice const &);

	void setName(char*);
	void setKw(int);
	char* getName() const;
	int getKw() const;
	
};

class ElectricNet
{
private:
	int maxKw;
	int currKw = 0;
	ElectricDevice* devs;
	int capacity;
	int size;

	void resize() {
		ElectricDevice* temp = devs;
		capacity *= 2;
		devs = new ElectricDevice[capacity];

		for (int i = 0; i < size; i++) {
			devs[i] = temp[i];
		}
		delete[] temp;
	}

public:
	ElectricNet(int);
	~ElectricNet();

	ElectricNet & operator+=(const ElectricDevice & dev);
	ElectricNet & operator+(const ElectricDevice&);
	ElectricNet & operator-=(const char*);
	ElectricNet & operator-(const char*);
	ElectricDevice & operator[](const char*);
	bool operator!();
	void operator++();
	void operator--();
	
	void print();
};
