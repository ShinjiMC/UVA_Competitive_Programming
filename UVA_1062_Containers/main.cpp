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
        ASSERT_NO_FATAL_FAILURE(runTestCase("A\nCBACBACBACBACBA\nCCCCBBBBAAAA\nACMICPC\nend\n", "Case 1: 1\nCase 2: 3\nCase 3: 1\nCase 4: 4\n"));
        // ASSERT_NO_FATAL_FAILURE(runTestCase("3\n0 0\n10000 10000\n20000 20000\n5\n0 2\n6 67\n43 71\n39 107\n189 140\n0", "INFINITY\n36.2215\n"));
        // ASSERT_NO_FATAL_FAILURE(runTestCase("4\n0 0\n1 1\n2 2\n3 3\n4\n0 0\n1 1\n2 2\n3 3\n5\n0 0\n1 1\n2 2\n3 3\n4 4\n6\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n8\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n9\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n10\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n11\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n10 10\n12\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n10 10\n11 11\n0", "1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}