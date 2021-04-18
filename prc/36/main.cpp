#include <iostream>
#include <string>
#include <fstream>
#include <vector>
void  Cartesian (double a1 = 0, double a2 = 0);//по умолчанию а1 и а2 равно нулю
#include <algorithm>


const auto PI = 3.141592653589793;




class Point



{
    Point()
    {
        double a1, a2;
        enum coord_system
        {




            Cartesian,
            Polar
        };;

    }
public:
    int GetX()
    {





        return a1;
    }

    void SetX(int valueX)
    {
        a1 = valueX;
    }
    int GetY()
    {
        return a2;

    }

    void SetY(int valueY)
    {



        a2=valueY;
    }

};

int main() {
    std::vector<Point> original;
    std::ifstream fin("data.txt");//считываем данные с файла
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }
    else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180 * PI / 180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
