#include "Ex_2.h"

template <class T>
Settings<T>::Settings()
{
	size = 0;
	capacity = MIN_CAPACITY;
	pairs = new Pair<T>[capacity];
}

template <class T>
Settings<T>::Settings(const Settings & p)
{
	size = p.size;
	capacity = p.capacity;
	for (int i = 0; i < size; i++)
	{
		pairs[i] = p.pairs[i];
	}
}

template <class T>
Settings<T> Settings<T>::operator=(Settings<T> & p)
{
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
}

template <class T>
Settings<T>::~Settings()
{
	delete[] pairs;
}

template <class T>
int Settings<T>::count()
{
	return size;
}

template <class T>
void Settings<T>::set(const char* _key, T _value)
{
	if (size >= capacity) {
		resize();
	}
	for (int i = 0; i < size; i++)
	{
		if (pairs[i].getKey() == _key)
		{
			pairs[i].setValue(_value);
			break;
		}
	}
	pairs[size].setKey(_key);
	pairs[size].setValue(_value);
	size++;
}

template <class T>
bool Settings<T>::get(const char * _key, T & _value)
{
	for (int i = 0; i < size; i++)
	{
		if (pairs[i].getKey() == _key)
		{
			_value = pairs[i].getValue();
			return true;
		}
	}
	return false;
}

