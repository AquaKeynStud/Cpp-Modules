#include <iostream>
#include "Type_utils.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED "🈲 Usage: ./convert <literal> 🈲" RESET;
        return (1);
    }

    ScalarConverter::convert(argv[1]);
    return (0);
}
