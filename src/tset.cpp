// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower=mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower=s.GetMaxPower();
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower=bf.GetLength();
	
	//TBitField temp (this->BitField);
	//return temp;
}

TSet::operator TBitField()
{
  return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
  return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (BitField.GetBit(Elem)==1)
		return 1;
	else
		return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	BitField=s.BitField;
	MaxPower=s.GetMaxPower();	
	  return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	
    return (BitField==s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
  return(BitField!=s.BitField);
}

TSet TSet::operator+(const TSet &s) // объединение
{ 
	if (MaxPower>=s.MaxPower)
{
	TSet Temp(MaxPower);
	Temp.BitField=BitField|s.BitField;
	return Temp;
	}
	else
	{
		TSet Temp(s.MaxPower);
		Temp.BitField=BitField|s.BitField;
		return Temp;
		
		//return TSet(0);
}
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet Temp (*this);
	if (Temp.BitField.GetBit(Elem)!=1)
		Temp.BitField.SetBit(Elem);
	return Temp;

 // return TSet(0);

}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet Temp(*this);
	if (Temp.BitField.GetBit(Elem)!=1)
			Temp.BitField.ClrBit(Elem);
		return Temp;
		//  return TSet(0);

}

TSet TSet::operator*(const TSet &s) // пересечение
{
	if (MaxPower>=s.MaxPower)
	{
		TSet Temp(s.MaxPower);
		Temp.BitField=BitField&s.BitField;
		return Temp;
	}
	else
	{
		TSet Temp(MaxPower);
		Temp.BitField=BitField&s.BitField;
			return Temp;
	}

  //return TSet(0);

}

TSet TSet::operator~(void) // дополнение
{
	TSet Temp(MaxPower);
	Temp.BitField=~this->BitField;
	return Temp;
	//  return TSet(0);

}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int i;
	cin >> i;
	for (int i=0; i>-1; cin >> i)
		s.BitField.SetBit(i);
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{//int i;
cout<<"{";
for (int i=0;i<s.MaxPower;i++)
	cout<<s.BitField.GetBit(i);
cout<<"}\n";
  return ostr;
}
