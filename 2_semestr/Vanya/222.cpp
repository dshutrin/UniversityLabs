 #include <iostream>
 #include <cmath>
 int main()
 {
	 float X, Y, R;
	 std::cout << "������� R: ";
	 std::cin >> R;
	 std::cout << "������� �������� ����� P: ";
	 std::cin >> X;
	 std::cout << "������� ������� ����� P: ";
	 std::cin >> Y;
	 if(X * X + Y * Y <= R * R && (X <= 0 && Y <= 0 || Y >= (X - 1) * (X - 1)))
		 std::cout << "����� �������� � �������������� �������. ";
	 else 
		 std::cout << "����� �� �������� � �������������� �������. ";
	 return 0;




 }
