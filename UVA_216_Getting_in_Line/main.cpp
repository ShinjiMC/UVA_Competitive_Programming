#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <sstream>
#include "code.hpp"
namespace
{
    void runTestCase(const std::string &input_data, const std::string &expected_output)
    {
        std::istringstream input_stream(input_data);                            // Crear stream de entrada con datos simulados
        std::streambuf *original_cin = std::cin.rdbuf(input_stream.rdbuf());    // Redirigir la entrada estándar a nuestro stream de entrada simulado
        std::stringstream output_stream;                                        // Capturar la salida estándar
        std::streambuf *original_cout = std::cout.rdbuf(output_stream.rdbuf()); // Redirigir la salida estándar a nuestro stream de salida capturado
        ASSERT_NO_FATAL_FAILURE(code());
        // Restaurar la entrada y salida estándar originales
        std::cin.rdbuf(original_cin);
        std::cout.rdbuf(original_cout);
        // Comparar la salida capturada con la salida esperada
        ASSERT_EQ(output_stream.str(), expected_output);
    }
    TEST(RunCodeTest, Tests)
    {
        ASSERT_NO_FATAL_FAILURE(runTestCase("6\n5 19\n55 28\n38 101\n 28 62\n 111 84\n 43 116\n 5\n 11 27\n 84 99\n 142 81\n 88 30\n 95 38\n 3\n 132 73\n 49 86\n 72 111\n 0\n", "**********************************************************\nNetwork #1\nCable requirement to connect (5,19) to (55,28) is 66.80 feet.\nCable requirement to connect (55,28) to (28,62) is 59.42 feet.\nCable requirement to connect (28,62) to (38,101) is 56.26 feet.\nCable requirement to connect (38,101) to (43,116) is 31.81 feet.\nCable requirement to connect (43,116) to (111,84) is 91.15 feet.\nNumber of feet of cable required is 305.45.\n**********************************************************\nNetwork #2\nCable requirement to connect (11,27) to (88,30) is 93.06 feet.\nCable requirement to connect (88,30) to (95,38) is 26.63 feet.\nCable requirement to connect (95,38) to (84,99) is 77.98 feet.\nCable requirement to connect (84,99) to (142,81) is 76.73 feet.\nNumber of feet of cable required is 274.40.\n**********************************************************\nNetwork #3\nCable requirement to connect (132,73) to (72,111) is 87.02 feet.\nCable requirement to connect (72,111) to (49,86) is 49.97 feet.\nNumber of feet of cable required is 136.99.\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
