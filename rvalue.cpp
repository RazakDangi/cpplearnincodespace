#include <iostream>
#include <vector>

struct MyData
{
    int a;
    int b;
    int c;
};
int main(int argc, char const *argv[])
{
    /* code */

    std::vector<int> v;

    auto&& x= v[0];

    auto&& z = MyData{};
    auto&& w = z;

MyData d{};
auto&& y = d;

    return 0;
}

