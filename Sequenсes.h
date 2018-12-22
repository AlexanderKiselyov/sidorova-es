#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace BNum;

namespace Sqs
{
	/*
	 * ����������� �����, ����������� ������������������.
	 */
	class Sequenses {

		/*
		 * �������� ������������������.
		 */
		string name;

	public:
		/*
		 * �������� ���������� ������, ������ �������� ������������������.
		 */
		Sequenses(string name) : name(name) {}

		/*
		 * ���������� ���� ����������������� � ������� n.
		 */
		virtual BigInt GetSqNum(size_t n) = 0;

	};
	
	/*
	 * �����, ����������� ������������������ ���������.
	 */
	class FibonacciSeq : public Sequenses{
		
		/*
		 * ������, � ������� ����� ��������� ����� ���������.
		 */
		vector <BigInt> FibSq;

	public :

		/*
		 * �����������, �������� ��� �����������������.
		 */
		FibonacciSeq() : Sequenses("Fibonacci sequense") {}

		/*
		 * ���������� ���� ������������������ � ������� n.
		 *
		 * @param num ����� ����� ������������������.
		 * @returns ���� ������������������.
		 */
		BigInt GetSqNum(size_t num) {
			size_t Size = FibSq.size();
			if (Size == 0){
				BigInt f1;
				BigInt f2("1");
				FibSq.push_back(f1);
				FibSq.push_back(f2);
				Size = FibSq.size();
			}
			if (Size - 1 >= num) {
				return FibSq.at(num);
			}
			else { 
				BigInt f1(FibSq.at(Size - 2));
				BigInt f2(FibSq.at(Size - 1));
				BigInt fn;
				for (size_t i = Size - 1; i < num; i++) {
					fn = f1 + f2;
					FibSq.push_back(fn);
					f1 = f2;
					f2 = fn;
				}
				return FibSq.at(num);
			}
		}
		
		/*
		 * ������� ������ n ������ �����������������.
		 *
		 * @param num ����� ����� ������������������.
		 */
		void FibDisplay(size_t n) {
			if (n > FibSq.size()) {
				GetSqNum(n);
			}
			for (size_t i = 0; i < n+1; i++) { 
				cout << FibSq.at(i) << endl;
			}
		}
	};
}
