#pragma once
#include <iostream>
#include <string.h>
using namespace std;
const unsigned MIN_CAPACITY = 32;

template <class T>
class Pair
{
private:
	char* key;
	T value;
public:
	Pair() {
		value = 0;
		key = NULL;
	};
	Pair(T value, const char* key) {
		this->value = value;
		this->key = new char[strlen(key) + 1];
		strcpy_s(this->key, strlen(key) + 1, key);
	};

	~Pair() {
		delete[] key;
	};

	Pair(const Pair& p) {
		value = p.value;
		key = new char[strlen(p.key) + 1];
			strcpy_s(key, strlen(p.key) + 1, p.key);
	};

	Pair operator=(Pair & p) {
		if (this != &p)
		{
			value = p.value;
			key = new char[strlen(p.key) + 1];
				strcpy_s(key, strlen(p.key) + 1, p.key);
		}
		return *this;
	};

	void setValue(T value) {
		this->value = value;
	};

	char* getKey() const {
		return key;
	};

	T getValue() const {
		return value;
	};
};

template <class T>
class Settings
{
private:
	Pair<T>* pairs;
	int capacity;
	int size;
	void resize() {
		Pair<T>* temp = pairs;
		capacity *= 2;
		pairs = new Pair<T>[capacity];

		for (int i = 0; i < size; i++) {
			pairs[i] = temp[i];
		}
		delete[] temp;
	}
public:
	Settings() {
		size = 0;
		capacity = MIN_CAPACITY;
		pairs = new Pair<T>[capacity];
	};
	Settings(const Settings & p){
		size = p.size;
		capacity = p.capacity;
		for (int i = 0; i < size; i++)
		{
			pairs[i] = p.pairs[i];
		}
	};
	Settings<T> operator=(Settings<T> &) {
		delete[] pairs;
		if (this != &p)
		{
			size = p.size;
			capacity = p.capacity;
			for (int i = 0; i < size; i++)
			{
				pairs[i] = p.pairs[i];
			}
		}
		return *this;
	};
	~Settings()
	{
		delete[] pairs;
	}

	int count() {
		return size;
	};
	void set(const char* _key, T _value) {
		bool flag = false;
		if (size >= capacity) {
			resize();
		}
		for (int i = 0; i < size; i++)
		{
			if (strcmp(pairs[i].getKey(), _key) == 0)
			{
				pairs[i].setValue(_value);
				flag=true;
			}
		}
		if (!flag)
		{
			Pair<T> a(_value, _key);
			pairs[size] = a;
			size++;
		}

	}
	;
	bool get(const char* _key, T & _value) {
		for (int i = 0; i < size; i++)
		{
			if (strcmp(pairs[i].getKey(), _key) == 0)
			{
				_value = pairs[i].getValue();
				return true;
			}
		}
		return false;
	};
	//void add(Pair<T> p) { //Its easier to make
	//	if (size >= capacity) {
	//		resize();
	//	}
	//	pairs[size] = p;
	//	size++;
	//};
	void print() {
		for (int i = 0; i < size; i++)
		{
			cout << "Key: " << pairs[i].getKey() << ", Value: " << pairs[i].getValue() << endl;
		}
	}
};

