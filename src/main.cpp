#include "bytecode/Instruction.hpp"
#include "machine/Machine.hpp"
#include "sample/fibonacci.hpp"
#include <array>
#include <cstring>
#include <iostream>


size_t parse_cl_args(int const argc, char** const argv)
{
    if (argc < 2) {
        return -1;
    }

    size_t const n = std::atoi(argv[1]);

    if (n == 0 && std::strcmp(argv[1], "0")) {
        std::cout << "warning, n = 0\n\n";
    }

    return n;
}



int main(int const argc, char** const argv)
{
    Nat n = parse_cl_args(argc, argv);
    n = (n != Nat(-1)) ? n : 0;

    Machine machine {4};

    machine.load(fibonacci_program, n);

    auto const value = machine.run();

    if (value == Nat(-1)) {
        std::cout << "error\n";
    }
    else {
        std::cout << value << "\n";
    }
}
