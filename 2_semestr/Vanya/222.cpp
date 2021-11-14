 #include <iostream>
 #include <cmath>
 int main()
 {
	 float X, Y, R;
	 std::cout << "Введите R: ";
	 std::cin >> R;
	 std::cout << "Введите ординату точки P: ";
	 std::cin >> X;
	 std::cout << "Введите абциссу точки P: ";
	 std::cin >> Y;
	 if(X * X + Y * Y <= R * R && (X <= 0 && Y <= 0 || Y >= (X - 1) * (X - 1)))
		 std::cout << "Точка попадает в заштрихованную область. ";
	 else 
		 std::cout << "Точка не попадает в заштрихованную область. ";
	 return 0;




 }
