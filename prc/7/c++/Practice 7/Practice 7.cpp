

#include <iostream>
#include <math.h>


using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int a, b, c;
	
	cout << "Задача по нахождению площади треугольника через формулу Герона"<<endl;
	cout << "Введите сторону a";
	cin >> a;
	cout << "Введите сторону b";
	cin >> b;
	cout << "Введите сторону с";
	cin >> c;
	
	
		
		int n = (a + b + c) / 2;
		int s = (n * (n - a) * (n - b) * (n - c));
		double param = s;
       cout <<"Площадь треугольника равна"<< "sqrt(" << param << ") = "<< sqrt(param)<<endl;
        

}
	

	
    
	


  
