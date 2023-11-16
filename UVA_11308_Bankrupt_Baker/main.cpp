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
        ASSERT_NO_FATAL_FAILURE(runTestCase("2\nMy Favourite Cheesecake\n8 3 100\nsugar 4\nwater 0\nlemonjuice 3\ncreamcheese 20\nvanilla 5\negg 5\ncream 10\nstrawberry 5\nStrawberry Whipped Cream\n2\ncream 5\nstrawberry 3\nScrumptious Caramel Topping\n3\nsugar 6\nwater 3\nlemonjuice 1\nSecret Cheesecake Base\n5\ncreamcheese 3\nsugar 5\nvanilla 1\negg 6\ncream 1\nMillion Dollar Cakes\n3 1 999999\ncostlyflour 500\ngold 4500\ndiamond 5000\nDisplay Cake - Do Not Eat!\n3\ncostlyflour 100\ngold 100\ndiamond 100\n",
                                            "MY FAVOURITE CHEESECAKE\nScrumptious Caramel Topping\nStrawberry Whipped Cream\n\nMILLION DOLLAR CAKES\nToo expensive!\n\n"));
        // ASSERT_NO_FATAL_FAILURE(runTestCase("3\n0 0\n10000 10000\n20000 20000\n5\n0 2\n6 67\n43 71\n39 107\n189 140\n0", "INFINITY\n36.2215\n"));
        // ASSERT_NO_FATAL_FAILURE(runTestCase("4\n0 0\n1 1\n2 2\n3 3\n4\n0 0\n1 1\n2 2\n3 3\n5\n0 0\n1 1\n2 2\n3 3\n4 4\n6\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n8\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n9\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n10\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n11\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n10 10\n12\n0 0\n1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n7 7\n8 8\n9 9\n10 10\n11 11\n0", "1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n1.4142\n"));
    }
} // namespace
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}