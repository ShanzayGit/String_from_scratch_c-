#include<iostream>
#include"String.h"
using namespace std;
String& String::operator=(String&& s)
{
	if (this == &s)
		return *this;
	else
	{
		this->~String();
		data = s.data;
		size = s.size;
		s.data = nullptr;
		s.size = 0;
		return *this;
	}

}
String::String(String&& s)
{

	data = s.data;
	size = s.size;
	s.data = nullptr;
	s.size = 0;
}

String String::operator()(const String& delim)
{
	String token;
	int l = delim.getLength();
	int i = -1, f = -1;
	for (int k = 0; k < getLength(); k++)
	{
		for (int j = 0; j < l; j++)
		{
			if (data[k] == delim[j])
				i = k, k = getLength(), f = j, j = l;
		}

	}
	if (i == -1)
	{

		token = *this;
		this->~String();
		return token;
	}
	else
	{
		if (i == 0)
		{
			token = left(i);
			left(1);
			return token;
		}
		else
		{
			token = left(i);
			left(1);
			return token;
		}
	}

}
istream& operator>>(istream& y, String& x)
{
	x.input();
	return cin;
}
ostream& operator<<(ostream& y, const  String& x)
{
	x.display();
	return cout;
}
String& String::operator=(const double num)
{
	this->~String();

	long long int integral = num;
	String x;
	x = integral;
	if (num < 0)
		x.insert(0, '-');
	x += {'.'};
	double rem = num - integral;
	rem = rem * 10;
	long long int integ = rem;
	int i = 0;
	while (i < 8)
	{
		String y;
		y = integ;
		x += y;
		rem = rem - integ;
		rem = rem * 10;
		integ = rem;
		i++;
	}
	String y;
	y = integ;
	x += y;
	*this = x;
	return *this;
}

String& String::operator=(const long long int num)
{
	this->~String();
	if (num < 0)
	{
		long long int num1 = -num;
		data = new char[numLength(num) + 2];
		int i;
		for (i = numLength(num); i > 0; i--)
		{
			data[i] = (num1 % 10) + 48;
			num1 = num1 / 10;
		}
		data[i] = '-';
		data[numLength(num) + 1] = '\0';
		size = numLength(num) + 2;
	}
	else if (num > 0 && num <= 9)
	{
		data = new char[numLength(num) + 1];
		int i = 0;
		data[i] = num + 48;
		i++;
		data[i] = '\0';
		size = numLength(num) + 1;
	}
	else if (num > 9)
	{
		long long int num1 = num;
		data = new char[numLength(num) + 1];
		int i;
		for (i = numLength(num) - 1; i >= 0; i--)
		{
			data[i] = (num1 % 10) + 48;
			num1 = num1 / 10;
		}
		data[numLength(num)] = '\0';
		size = numLength(num) + 1;
	}
	else
	{
		data = new char[3];
		int i = 0;
		data[i] = '0';
		data[i + 1] = '0';
		data[i + 2] = '\0';
		size = 3;
	}
	return*this;
}

String:: operator bool()const
{
	return data != nullptr && data[0] != '\0';
}

String::operator long long int()const
{
	long long int integer = 0;
	int i = 0;
	if (!this)
		exit(0);
	else
	{
		int count = 0;
		while (data[i] != '\0' && data[i] != '.')
		{
			if (data[i] >= '0' && data[i] <= '9')
				count++;
			i++;
		}
		int div = 1;

		for (int j = 1; j < count; j++)
			div = div * 10;
		i = 0;
		while (data[i] != '\0' && data[i] != '.')
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				integer = integer + (div * ((int)data[i] - 48));
				div = div / 10;
			}
			i++;
		}
	}
	if (find('-', 0) != -1)
		return (integer = -integer);
	return integer;

}
String::operator double()const
{
	double number = 0.00;
	if (!this)
	{
		return number;
	}
	number = (long long int)(*this);
	int i = this->find('.', 0);
	i = i + 1;
	int decimalZero = 0;
	if (data[i] == '0')
		decimalZero = 1;
	int j = 0;
	long long int fract = 0;
	while (data[i] >= '0' && data[i] <= '9')
	{
		fract = (fract * 10) + data[i] - 48;;
		i++;
	}
	int div = numLength(fract);
	double divisor = 10;
	for (int i = 0; i < div - 1; i++)
	{
		divisor = divisor * 10;
	}
	if (decimalZero == 1)
		divisor = divisor * 10;
	double fractionalPart = fract / divisor;
	if (number < 0)
		number = number - fractionalPart;
	else
		number = number + fractionalPart;
	return number;
}


char& String::operator [](const int index)
{
	if (!this)
	{
		exit(0);
	}
	if (index < getSize() - 1 && index >= 0)
		return data[index];
	exit(0);

}
const char& String::operator [](const int index)const
{
	if (this)
	{
		if (index < getSize() && index >= 0)
			return data[index];

	}
	exit(0);

}
bool String::operator !()const
{
	if (data == nullptr || data[0] == '\0')
	{
		return true;
	}
	return false;
}
int String::operator ==(const String& s2)const
{
	if ((data == nullptr || size == 0) || (s2.data == nullptr || s2.size == 0))
	{
		cout << "\nAtleast one String is empty!";
		return 0;
	}

	int i = 0, count = 0;
	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		if (data[i] == s2.data[i])
		{
			count++;
		}
		else if (data[i] > s2.data[i])
			return 1;
		else if (data[i] < s2.data[i])
			return -1;
		i++;
	}
	if (count == getLength() && count == s2.getLength())
		return 0;
	else if (getLength() > s2.getLength())
		return 1;
	else
		return -1;


}

String& String::  operator =(const String& s)
{
	if ((this == &s))
	{
		return *this;

	}
	else
	{
		this->~String();
		size = s.size;
		data = new char[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = s.data[i];
		}
		return *this;

	}
}
String String:: operator +(const String& s)const
{
	if (s.data == nullptr || s.size == 0)
	{
		String x{ data };
		return x;
	}
	else if (data == nullptr || size == 0)
	{
		String x{ s.data };
		return x;
	}
	else
	{
		String x{ data };
		x += s.data;
		return x;
	}
}

void String::operator +=(const String& s2)
{
	if (s2.data == nullptr || s2.size == 0)
	{
		return;
	}
	else if (data == nullptr || size == 0)
	{
		data = s2.data;
		size = s2.size;
	}
	else
	{
		insert(getLength(), s2);
	}
}

int String::numLength(const long long int num)const
{
	int count = 0;
	long long int num1 = num;
	while (num1 != 0)
	{
		count++;
		num1 = num1 / 10;
	}
	return count;
}
String String::left(const int count)
{
	if (count <= 0 || data == nullptr || size == 0)
	{
		String x;
		return x;
	}
	if (count >= getLength())
	{
		String x{ data };
		this->~String();
		return x;
	}
	int count1 = count;
	char* temp = new char[count + 1];
	int j = 0;
	int k = 0;
	while (count1 > 0)
	{
		temp[k] = data[j];
		remove(j, 1);
		k++;
		count1--;
	}
	temp[count] = '\0';
	String x{ temp };
	return x;
}
String String::right(const int count)
{
	if (count <= 0 || data == nullptr || size == 0)
	{
		exit(0);
	}
	if (count >= getLength())
	{
		String x{ data };
		this->~String();
		return x;
	}
	else
	{
		char* temp = new char[count + 1];
		int i = getLength() - count, j = count, k = 0;
		while (j > 0)
		{
			temp[k] = data[i];
			k++;
			remove(i, 1);
			j--;
		}
		temp[k] = '\0';
		String x{ temp };
		return x;
	}
}


String::String(const String& x) :String()
{
	if (x.data == nullptr)
	{
		return;
	}
	size = x.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
		data[i] = x.data[i];
}

int String::find(const String& subString, const int start)const
{
	if (data != nullptr && size > 0 && subString.data != nullptr && subString.size > 0 && start >= 0 && start <= getLength())
	{
		int subStrLength = subString.getLength();
		int oldStringLength = getLength() - 1;
		int i = start, j = 0, count = 0, ocurrence = -1;
		while (i <= oldStringLength)
		{
			if (data[i] == subString.data[j])
			{
				while (subString.data[j] != '\0')
				{
					if (data[i] != subString.data[j])
						j = subString.getLength();
					else
					{
						j++;
						i++;
						count++;
					}
				}
				if (count == subStrLength)
				{
					return i - subStrLength;
				}
				count = 0;
				j = 0;
				i--;
			}
			i++;
		}
		return ocurrence;
	}
	else
	{
		return -1;
	}
}
int String::replace(const String& old, const String& newSubStr)
{

	int subStrLength = old.getLength();
	int oldStringLength = getLength();
	int i = 0, j = 0, count = 0, ocurrence = 0;
	if (old.size == 0 || old.data == nullptr || size == 0 || data == nullptr)
	{
		//cout << "empty";
		return 0;
	}
	else
	{
		while (i < getLength())
		{
			if (data[i] == old.data[j])
			{
				while (old.data[j] != '\0')
				{
					if (data[i] != old.data[j])
						j = old.getLength();
					else
					{
						j++;
						i++;
						count++;
					}
				}
				if (count == subStrLength)
				{
					int k = i - count;
					remove(k, subStrLength);
					if (newSubStr.data != nullptr)
					{
						insert(k, newSubStr);
					}
					ocurrence++;
					i--;
				}
				count = 0;
				j = 0;
				i--;
			}
			i++;
		}
	}
	return ocurrence;
}
void String::insert(const int index, const String& subStr)
{
	if (data == nullptr || size == 0)
		return;
	else if (subStr.data == nullptr || subStr.size == 0)
	{
		return;
	}
	int i = 0, j = 0;
	if (index <= getLength())
	{
		int n = getLength() + (subStr).getLength() + 1;

		char* temp = new char[n];
		while (i < n)
		{
			if (i == index)
			{
				strCopy((subStr).data, &temp[i]);
				j = i;
				i = i + subStr.getLength();
			}
			else
			{


				temp[i] = data[j];
				i++;
				j++;

			}
		}
		i--;
		temp[i] = '\0';
		this->~String();
		data = temp;
		size = n;
	}
	else
	{
		cout << "Index out of range!!!";
		return;
	}

}
void String::remove(int index, int count)
{
	if (count <= 0 || index < 0 || count >= getLength() || data == nullptr || size == 0)
	{
		return;

	}
	else
	{
		char* temp = new char[getLength() + 2];
		int i = 0, j = 0;
		while (i < getLength() + 1)
		{
			if (i >= index && i <= index + count - 1)
			{
				i++;
			}
			else
			{
				temp[j] = data[i];
				i++;
				j++;
			}
		}
		temp[j] = '\0';
		this->~String();
		data = temp;
		size = getLength() + 1;
	}

}
int String::Length(const char* c)const
{
	int i = 0, count = 0;
	while (c[i] != '\0')
	{
		count++;
		i++;
	}
	return count;
}
void String::strCopy(const char* src, char* desti)const
{
	int i = 0;
	while (src[i] != '\0')
	{
		desti[i] = src[i];
		i++;
	}
	desti[i] = '\0';
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c) :String()
{
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
	size = 2;
}
String::String(const char* c) :String()
{
	data = new char[Length(c) + 2];
	size = Length(c) + 1;
	strCopy(c, data);
}
String::~String()
{
	delete[]data;
	data = nullptr;
	size = 0;
}
void String::input()
{

	data = new char[1];
	size = 1;
	char ch;
	int count = 0;
	while ((ch = cin.get()) != '\n')
	{
		if ((count + 1) == size)
		{
			data[count] = ch;
			resize(size + 1);
		}
		count++;
	}
	data[count] = '\0';
}
void String::resize(int newCapacity)
{
	if (newCapacity <= 0)
		this->~String();
	else
	{
		char* temp = new char[newCapacity];
		temp[0] = '\0';
		int i = 0;
		while (i < newCapacity - 1 && i < size)
		{
			temp[i] = data[i];
			i++;
		}
		temp[i] = '\0';
		//cout << i;
		this->~String();
		size = newCapacity;
		data = temp;
	}
}

void String::display()const
{
	if (data == nullptr || size == 0)
		return;
	cout << data;
}
int String::getLength()const
{
	return Length(data);
}
int String::getSize()const
{
	return size;
}
void String::makeUpper()
{
	if (data == nullptr || size == 0)
		return;
	int i = 0;
	char* temp = new char[getSize() + 1];
	while (i < getSize())
	{
		if ((data[i] >= 97) && (data[i] <= 123))
		{
			char ch = data[i] - 32;
			temp[i] = ch;
		}
		else
		{
			temp[i] = data[i];
		}
		i++;
	}
	i--;
	temp[i] = '\0';
	this->~String();
	data = temp;
	size = getLength() + 1;
}
void String::makeLower()
{
	if (data == nullptr || size == 0)
		return;
	int i = 0;
	char* temp = new char[getSize() + 1];
	while (i < getSize())
	{
		if ((data[i] >= 65) && (data[i] <= 91))
		{
			char ch = data[i] + 32;
			temp[i] = ch;
		}
		else
		{
			temp[i] = data[i];
		}
		i++;
	}
	i--;
	temp[i] = '\0';
	this->~String();
	data = temp;
	size = getLength() + 1;
}
void String::shrink()
{
	if (data == nullptr || size == 0)
		return;
	if (getSize() > getLength())
		resize(getLength() + 1);
	else
		return;
}
void String::trimLeft()
{
	if (data == nullptr || size == 0)
		return;
	int i = 0, j = 0, n = getSize() + 1;
	char* temp = new char[n];
	while (data[i] == '\n' || data[i] == '\t' || data[i] == ' ')
	{
		i++;
	}
	strCopy(&data[i], temp);
	this->~String();
	data = temp;
	size = n - i - 1;
}

void String::trim()
{
	trimLeft();
	trimRight();
}
void String::trimRight()
{
	if (data == nullptr || size == 0)
		return;
	int i = 0, j = 0, n = getLength() - 1;
	while (data[n] == '\n' || data[n] == '\t' || data[n] == ' ')
	{
		remove(n);
		n--;
	}
}
void String::reverse()
{
	if (data == nullptr || size == 0)
		return;
	int i = getLength() - 1;
	char* temp = new char[i + 2];
	int j = 0;
	while (i >= 0)
	{
		temp[j] = data[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	this->~String();
	data = temp;
	size = j + 1;
}