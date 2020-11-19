#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main()

{
    "userId": 1,
        "id" : 1,
        "title" : "задача",
        "completed" : false
}
{
    setlocale(LC_ALL, "ru")
    json j_object = { {"one", 1}, {"two", 2} };
    json j_array = { 1,2,3,4,5,6,7, 8,9,10 };
    for (auto& a : j_object.items())
    {
        std::cout << "key: " << a.key() << ", value: " << a.value() << '\n';
    }
    for (auto& a : j_array.items())
    {
        std::cout << "key: " << a.key() << ", value: " << a.value() << '\n';
    }
}
