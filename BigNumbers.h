#pragma once
#include <vector>
#include <string>
using namespace std;

namespace BNum
{
	/*
	 * ����������� �����, ����������� ������� �����.
	 */
	class BigNumbers {
	public:

		/*
		 * ���������� ���������� ������ � ������� �����.
		 */
		virtual int Count() = 0;
	};

	/*
	 * �����, ����������� ������� ����� �����.
	 */
	class BigInt : public BigNumbers {
		/*
		 * ��������� �������
		 */
		static const int base = 1000000;

		/*
		 * ���������� ����, ������� ����� ��������� � ����� ������.
		 */
		static const int num = 6;

		/*
		 * ������, � ������� ����� ��������� ������� �����.
		 */
		vector<int> value;

		/*
		 * ������� �������������� ���� �� ������� ��������.
		 */
		void RemZeros();

	public:
		/*
		 * ����������� �� ���������. ������� ������� �����.
		 */
		BigInt();

		/*
		 * �����������, ��������� ������� �����, ���������� �� ������.
		 *
		 * @param str ������, �� ������� ���������� ������� �����
		 */
		BigInt(string str);

		/*
		 * �������� ������������.
		 *
		 * ����������� �������� ����� �������� �� ������� �������� �����.
		 *
		 * @param bi ������ �������. ������� �����, �� �������� ������� �����
		 * �������� ��� �������� �������� �����.
		 * @returns ������ �� ������� ��������� ������.
		 */
		BigInt& operator = (const BigInt &bi);

		/*
		 * ���������� ���������� ������ � ������� �����.
		 */
		int Count();

		/*
		 * ���������� ��� ������� �����.
		 *
		 * @param right ������ �������.
		 * @returns ����� ���� ������� �����.
		 */
		BigInt operator +(const BigInt& right) const;
		
		/*
		 * �������� ��� ������� �����.
		 *
		 * @param right ������ �������.
		 * @returns ����� ���� ������� �����.
		 */
		BigInt operator -(const BigInt& right) const;

		/*
		 * �������� ��� ������� �����.
		 *
		 * @param right ������ �������.
		 * @returns ������������ ���� ������� �����.
		 */
		BigInt operator *(const BigInt& right) const;

		/*
		 * ���������, ������ �� ����� �����.
		 *
		 * @param right ������ �������.
		 * @returns frue ��� false.
		 */
		bool operator > (const BigInt& right);

		/*
	   	 * ���������, ����� �� ���������.
		 *
		 * @param right ������ �������.
		 * @returns frue ��� false.
		 */
		bool operator == (const BigInt& right);

		friend ostream& operator <<(std::ostream& os, const BigInt& bi);
	};


	/*
	 * ������� ������� ����� �� �����.
	 *
	 * @param os �������� �����.
	 * @param bi �����, ������� ������� ������� �� �����.
	 * @returns �������� �����.
	 */
	ostream& operator <<(std::ostream& os, const BigInt& bi);


	/*
	 * �����, ����������� ������� ����� � ������� ������.
	 */
	class BigDecimal : public BigNumbers{

		/*
		 * ����������, � ������� ����� ��������� ����� ����� �����.
		 */
		BigInt IntPart;

		/*
		 * ����������, � ������� ����� ��������� ������� ����� �����.
		 * �������� - 9 ������ ����� �������.
		 */
		unsigned long fract; 

	public:
		/*
		 * ����������� �� ���������. ������� ������� �����.
		 */
		BigDecimal();

		/*
		 * �����������, ��������� ������� �����, ���������� �� ������.
		 *
		 * @param str ������, �� ������� ���������� ������� �����
		 */
		BigDecimal(string str);

		/*
		 * �������� ������������.
		 *
		 * ����������� �������� ����� �������� �� ������� �������� �����.
		 *
		 * @param bd ������ �������. ������� �����, �� �������� ������� �����
		 * �������� ��� �������� �������� �����.
		 * @returns ������ �� ������� ��������� ������.
		 */
		BigDecimal& operator = (const BigDecimal &bd);

		/*
		 * ���������� ���������� ������ � ����� ����� �������� �����.
		 */
		int Count();

		/*
		 * ���������� ��� ������� �����.
		 *
		 * @param right ������ �������.
		 * @returns ����� ���� ������� �����.
		 */
		BigDecimal operator +(const BigDecimal& right) const;

		/*
		 * �������� ��� ������� �����.
		 *
		 * @param right ������ �������.
		 * @returns �������� ���� ������� �����.
		 */
		BigDecimal operator -(const BigDecimal& right) const;

		friend ostream& operator <<(std::ostream& os, const BigDecimal& bd);
	};

	/*
	 * ������� ������� ����� �� �����.
	 *
	 * @param os �������� �����.
	 * @param bd �����, ������� ������� ������� �� �����.
	 * @returns �������� �����.
	 */
	ostream& operator <<(std::ostream& os, const BigDecimal& bd);
}