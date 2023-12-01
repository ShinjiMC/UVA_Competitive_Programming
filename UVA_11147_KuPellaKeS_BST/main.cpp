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
        ASSERT_NO_FATAL_FAILURE(runTestCase("3\n10\n1 2 3 4 5 6 7 8 9 10\n5\n1 0 1 0 1\n4\n-1 -2 -3 -4\n",
                                            "Case #1: 7(5(3(2(1),4),6),9(8,10))\nCase #2: 1(1(1(0(0))))\nCase #3: -3(-4,-2(-1))\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}