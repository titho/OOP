#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Vehicle
{
private:
	char* make;
	char* model;
	char* color;
	int   year;
	int   mileage;
public:
	void setMake(const char* make) {
		this->make = new char[strlen(make) + 1];
		strcpy_s(this->make, strlen(make) + 1, make);
	};
	void setModel(const char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	};
	void setColor(const char* color) {
		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	};
	void setYear(int year) {
		this->year = year;
	};
	void setMileage(int mileage) {
		this->mileage = mileage;
	};

	char* getMake() const {
		return make;
	};
	char*   getModel() const {
		return model;
	};
	char*   getColor() const {
		return color;
	};
	int      getYear() const {
		return year;
	};
	int   getMileage() const {
		return mileage;
	};

	Vehicle() {
		make = NULL;
		model = NULL;
		color = NULL;
		year = 0;
		mileage = 0;
	}

	Vehicle(const char * make, const  char * model, const  char * color, int year, int mileage) {
		this->make = new char[strlen(make) + 1];
		this->model = new char[strlen(model) + 1];
		this->color = new char[strlen(color) + 1];
		strcpy_s(this->make, strlen(make) + 1, make);
		strcpy_s(this->model, strlen(model) + 1, model);
		strcpy_s(this->color, strlen(color) + 1, color);

		this->year = year;
		this->mileage = mileage;
	}
	Vehicle(const Vehicle & v) {
		make = new char[strlen(v.make) + 1];
		strcpy_s(make, strlen(v.make) + 1, v.make);
		model = new char[strlen(v.model) + 1];
		strcpy_s(model, strlen(v.model) + 1, v.model);
		color = new char[strlen(v.color) + 1];
		strcpy_s(color, strlen(v.color) + 1, v.color);
		year = v.year;
		mileage = v.mileage;
	}
	Vehicle operator=(Vehicle& v) {
		if (this != &v)
		{
			delete[] make;
			delete[] model;
			delete[] color;

			make = new char[strlen(v.make) + 1];
			strcpy_s(make, strlen(v.make) + 1, v.make);
			model = new char[strlen(v.model) + 1];
			strcpy_s(model, strlen(v.model) + 1, v.model);
			color = new char[strlen(v.color) + 1];
			strcpy_s(color, strlen(v.color) + 1, v.color);
			year = v.year;
			mileage = v.mileage;
		}
		return *this;
	}
	~Vehicle() {
		delete[] make;
		delete[] model;
		delete[] color;
	}
	virtual void details() { };
		
};

class Car : Vehicle {
public:
	Car(const char * make, const  char * model, const  char * color, int year, int mileage)
	: Vehicle(make, model, color, year, mileage)
	{}
	void details() {
		cout << "Make: " << getMake() << ", Model: " << getModel() << ", Color: "
			<< getColor() << endl << ", Year: " << getYear() << ", Mileage: " << getMileage() << endl;
	}
};

class Truck : Vehicle {
private:
	int size;
public:
	Truck(const char * make, const  char * model, const  char * color, int year, int mileage, int size) :
		Vehicle(make, model, color, year, mileage)
	{
		this->size = size;
	}
	int getSize() const
	{
		return size;
	}
	void setSize(int size)
	{
		this->size = size;
	}

	void details() {
		cout << "Make: " << getMake() << ", Model: " << getModel() << ", Color: "
			<< getColor() << endl << ", Year: " << getYear() << ", Mileage: " << getMileage() << ", Size: "<< getSize()<< endl;
	}

};

class Motorcycle : Vehicle {
private:
	char * type;
public:
	char * getType() const {
		return type;
	}
	void setType(const char * type) {
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	Motorcycle(const char * make, const  char * model, const  char * color, int year, int mileage, const char * type) :
		Vehicle(make, model, color, year, mileage)
	{
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	
	~Motorcycle() {
		delete[] type;
	}
	void details() {
		cout << "Make: " << getMake() << ", Model: " << getModel() << ", Color: "
			<< getColor() << endl << ", Year: " << getYear() << ", Mileage: " << getMileage() << ", Type: " << getType() << endl;
	}
};