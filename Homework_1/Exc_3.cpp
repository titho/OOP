#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Store;
class Product // Cars
{
private:
	long int sku; // Stock keeping unit - uniq num
	char* brand; 
	char* model;
	char* category; // SUV, sports, etc.
	double price;
	int count; // Num. of cars in the store
	char* typeOfEngine; // Diesel, Gasoline
	int year; // Year of production

public:
	Product();
	Product(int, const char*, const char*, const char*, double, int, const char*, int);
	~Product();
	Product& operator=(const Product&);
	Product(const Product&);
	
	void setSKU(int);
	void setBrand(char*);
	void setModel(char*);
	void setCategory(char*);
	void setPrice(double);
	void setCount(int);
	void setType(char*);
	void setYear(int);

	long getSKU() const;
	char* getBrand() const;
	char* getModel() const;
	char* getCategory() const;
	double getPrice() const;
	int getCount() const;
	char* getType() const;
	int getYear() const;

	//void addCar(Product car);
	void modCar(); 

	friend istream & operator>>(istream&, Product&);
	friend ostream & operator<<(ostream&, Product&);
};

Product::Product()
{
	sku = 0;
	brand = NULL;
	model = NULL;
	category = NULL;
	price = 0;
	count = 0;
	typeOfEngine = NULL;
	year = 0;
}

Product::Product(int _sku, const char * _brand, const char * _model, const char * _category, double _price, int _count, const char * _typeOfEngine, int _year)
{
	brand = new char[strlen(_brand)+1];
	strcpy_s(brand, strlen(_brand) + 1, _brand);
	
	model = new char[strlen(_model)+1];
	strcpy_s(model, strlen(_model) + 1, _model);
	
	category = new char[strlen(_category)+1];
	strcpy_s(category, strlen(_category) + 1, _category);

	sku = _sku;
	price = _price;
	count = _count;
	year = _year;

	typeOfEngine = new char[strlen(_typeOfEngine) + 1];
	strcpy_s(typeOfEngine, strlen(_typeOfEngine) + 1, _typeOfEngine);
}


Product::~Product()
{
	delete brand;
	delete model;
	delete category;
	delete typeOfEngine;
}

Product & Product::operator=(const Product& car)
{
	if (this != &car) 
	{
		delete[] brand;
		delete[] model;
		delete[] category;
		delete[] typeOfEngine;

		sku = car.sku;
		
		brand = new char[strlen(car.brand) + 1];
		strcpy_s(brand, strlen(car.brand) + 1, car.brand);
		
		model = new char[strlen(car.model) + 1];
		strcpy_s(model, strlen(car.model) + 1, car.model);

		category = new char[strlen(car.category) + 1];
		strcpy_s(category, strlen(car.category) + 1, car.category);

		price = car.getPrice();
		count = car.getCount();
		year = car.getYear();

		typeOfEngine = new char[strlen(car.typeOfEngine) + 1];
		strcpy_s(typeOfEngine, strlen(car.typeOfEngine) + 1, car.typeOfEngine);
	}

	return *this;
}

Product::Product(const Product & car)
{
	sku = car.sku;
	brand = new char[strlen(car.brand)+1];
	strcpy_s(brand, strlen(car.brand) + 1, car.brand);
	model = new char[strlen(car.model)+1];
	strcpy_s(model, strlen(car.model) + 1,  car.model);
	category = new char[strlen(car.category)+1];
	strcpy_s(category, strlen(car.category) + 1, car.category);
	price = car.price;
	count = car.count;
	year = car.year;
	typeOfEngine = new char[strlen(car.typeOfEngine)+1];
	strcpy_s(typeOfEngine, strlen(car.typeOfEngine) + 1, car.typeOfEngine);
}

void Product::modCar()
{
	Product a;
	
	cout << "What do you want to modify on the car? \n S SKU \n B Brand \n M Model \n C Category \n P Price \n O Count \n T Type Of Engine \n Y Year \n";
	char n;
	cin >> n;
	switch (n)
	{
	case 'S': int _sku; cin >> _sku; a.setSKU(_sku); break;
	case 'B': char * _brand; _brand = new char[100]; cin.getline(_brand, 100); a.setBrand(_brand); a.getBrand(); break;
	case 'M': char * _model; _model = new char[100];  cin.getline(_model, 100); a.setModel(_model); break;
	case 'C': char * _cat; _cat = new char[100];  cin.getline(_cat, 100); a.setCategory(_cat); break;
	case 'P': int _price; cin >> _price; a.setPrice(_price); break;
	case 'O': int _count; cin >> _count; a.setCount(_count); break;
	case 'T': char * _type; _type = new char[100];  cin.getline(_type, 100); a.setType(_type); break;
	case 'Y': int _year; cin >> _year; a.setYear(_year); break;
	default:
		break;
	}

}


void Product::setSKU(int _sku)
{
	sku = _sku;
}

void Product::setBrand(char * _brand)
{
	brand = new char[strlen(_brand)+1];
	strcpy_s(brand, strlen(_brand) + 1, _brand);
}

void Product::setModel(char * _model)
{
	model = new char[strlen(_model)+1];
	strcpy_s(model, strlen(_model) + 1, _model);
}

void Product::setCategory(char * _category)
{
	category = new char[strlen(_category)+1];
	strcpy_s(category, strlen(_category) + 1, _category);
}

void Product::setPrice(double _price)
{
	price = _price;
}

void Product::setCount(int _count)
{
	count = _count;
}

void Product::setType(char * _typeOfEngine)
{
	typeOfEngine = new char[strlen(_typeOfEngine)+1];
	strcpy_s(typeOfEngine, strlen(_typeOfEngine) + 1, _typeOfEngine);
}

void Product::setYear(int _year)
{
	year = _year;
}

long Product::getSKU() const
{
	return sku;
}

char * Product::getBrand() const
{
	return brand;
}

char * Product::getModel() const
{
	return model;
}

char * Product::getCategory() const
{
	return category;
}

double Product::getPrice() const
{
	return price;
}

int Product::getCount() const
{
	return count;
}

char * Product::getType() const
{
	return typeOfEngine;
}

int Product::getYear() const
{
	return year;
}

istream& operator>>(istream& in, Product& car)
{
	cout << "Enter SKU: "; in >> car.sku;
	cout << "Enter Brand: "; in >> car.brand;
	cout << "Enter Model: "; in >> car.model;
	cout << "Enter Category: "; in >> car.category;
	cout << "Enter Price: "; in >> car.price;
	cout << "Enter Count: "; in >> car.count;
	cout << "Enter Type of Engine: "; in >> car.typeOfEngine;
	cout << "Enter Year: "; in >> car.year;
	return in;
}

ostream& operator<<(ostream& out, Product& car)
{
	cout << "SKU: " << car.getSKU() << endl << ", Brand: " << car.getBrand()
		<< endl << ", Model: " << car.getModel() << endl << ", Category: " << car.getCategory() << endl << ", Price: " << car.getPrice()
		<< endl << ", Count: " << car.getCount() << endl << ", Type of Engine: " << car.getType() << ", Year: " << car.getYear() << endl;
	return out;
}

class Store
{
private:
	Product* cars;
	unsigned carsCount;
	unsigned capacity;

	void resize() {
		Product* temp = cars;
		capacity *= 2;
		cars = new Product[capacity];

		for (unsigned i = 0; i < carsCount; i++) {
			cars[i] = temp[i];
		}
		delete[] temp;
	}

public:
	Store();
	~Store();
	Store(Product *, int);
	Store(Store const &);
	Store& operator=(Store);
	void addProduct(Product);
	void addProduct();
	void remProduct();
	//void remProduct(Product&);
	void modProduct();

	void print();

	void menu();

	void setCars(Product*);
	void setCarsCount(int);
	Product& getCars() const;
	int getCarsCount() const;


};

int main()
{
	Store S;
	Product c1(2133, "Tesla", "Model X", "Coupe", 62000.00, 15, "Electric", 2011);
	Product c2(2000, "VW", "Golf", "Coupe", 10000.00, 25, "Diesel", 2008);
	Product c3(2001, "Mercedes", "Trucky", "Truck", 120000.00, 5, "Diesel", 2017);
	S.addProduct(c1);
	S.addProduct(c2);
	S.addProduct(c3);

	S.menu();

	c2.getCategory();

	system("pause");
	return 0;
}
