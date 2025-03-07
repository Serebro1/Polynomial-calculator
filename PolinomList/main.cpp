/*
���������� ��������� �������� ��� ���������.
������: ���������� ������� �� ��� ����������
P(x,y,z) = 2x^5 * y^4 * z^3 + 10x^6 * y^7 * z^8 - 2 * x * y^3 - 3
��� �������� �������, ��� ������� ���������� ���������� 10
����� ���������� 10^3
������� ����������� ����� �������

1 ������� �����������
��������������� � ������ ������
������������ ��� 0 ������ ������ ���������� ���������� �����: -3
������� x, y, z ��� x ���������
-2*x*y^2 ��� ������ � ������� 120 � ������� �������� -2
10x^6 * y^7 * z^8 - ������ 678 ��� �������� 10

������: ������� ������ ������, ������ ������ �� ������������

2 ������� � �������������� �������
��� ������������ ������������� �������� �����������, ��� ������ � �������� �������� ������������ �� ������� ��������.
��� ������ � ������ ����� �������� �� �������� �� ��������.
����� ������ ����� ����������� ���������� ����:
[10, 678][]->[2, 543][]->[-2, 120][]->[-3, 000][0]
�������� � ����������:
����� ���� ������� Q(x, y, z) = 2*x*y^2
P + Q = Z
��� ���������� �������� � ���������� ��������� �������� ����� ����. ����� 0, �� ���� ������� �� ��� ����� �� ����� � ����� ����� �������.
P - P = 0
��� ����������� ������ �������?
���������������: nullptr ����� ������������ ������ ��� �� ��� ��� ������ ���.
�������:
1) ����� ������������ ��� nullptr ��� ������� �������. ����� ����� �������� ��������: ������ ������� � ������� �������.
2) � ������ ������� �������� ��������� �����, ������� ����� ��������������� �������� ��������. ������� ��� � ������. [0, -1][]->...
��� ������� �� ����� ������������ � �������� ��������� ������� ��������.

��� ������ ������ ���������:
1) ��������� ��������� ��������
2) ��������� �������� ��� ����������

1) ������ �� ��������� ������� � �����-�� ������� ������ �����, ������� ������������ ����. � ���������. ��������� ����� ����� �������� ������� �������� �����������.
2) ��������, ���������, ��������� �� ���������/�����, ������������ ���� ���������(*)

�������� �����:
1) �������
2) ����������� ����������

����� ������� ������ ���������, � ������� ������� ������������� ����������.
��� �����������:
1. P
2. Q
3. P+Q
4. P*2
����� ����� ����������� � ���������� ���������.

�� ���� ��������� ����� ����������� �����.
������ ����������� ��� ���. ������.
������ ���� ������
���������� ������
�������� ��������� � �������� ������.

������ ������ ������� � ������� (�� �����)

����������
1) ��������� �������� �������

���������� �����:
1) ����� �������� ������� � ��� ��������
2) ���� ��� ���������� ������ � ��� ���������� � �������� ������ + ��������� ������ ��� ���������� �������� � ������ ������
�����:
�����: ����� 2 ������, � ���������� ��.
������: ���������, ����������, ��������
��������� �������� ����� �������� ��� ������.
*/
#include "polinom.h"
int main() {
	// 1 ������,
	/*TList<int> l;
	for (l.reset(); !l.isEnd(); l.goNext()) {
		std::cout << l.getCurr();
	}*/
	// ������ ��������� ��� �������� ������.
	// ���� �-��� ������� ���������� ������� ������� ������

	// 2 ������(����� ���������). �������� ������������ ����� � ��������� �� ����������� ����������.
	Polinom pol1;
	pol1 += Monom(3.0, 0, 0, 0);
	pol1 += Monom(2.0, 1, 1, 1);
	pol1 += Monom(5.0, 2, 1, 0);
	Polinom pol2;
	pol2 += Monom(3.0, 0, 3, 0);
	pol2 += Monom(-2.0, 1, 1, 1);
	pol2 += Monom(5.0, 0, 1, 2);
	Polinom res;
	Monom m = pol1[0];
	m *= pol2[2];
	std::cout << m << std::endl;
	res = pol1 * pol2;
	Polinom::iterator q = res.begin();
	std::cout << "Monoms:" << std::endl;
	for (q = res.begin(); q != res.end() ; ++q)
	{
		std::cout << (*q) << " ";
	}
	std::cout << std::endl;
	std::cout << "Polinom:" << std::endl;
	std::cout << res;
	return 0;
}