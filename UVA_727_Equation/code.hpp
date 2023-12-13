#include <iostream>
#include <stack>

int oper(char c)
{
    return (c == '*' || c == '/') ? 2 : 1;
}

int code()
{
    int t;
    std::cin >> t;
    std::cin.ignore(2);
    while (t--)
    {
        std::stack<char> expression;
        std::string ans;
        std::string cad;
        while (std::getline(std::cin, cad) && !cad.empty())
        {
            char ch = cad[0];
            if (std::isdigit(ch))
                ans.push_back(ch);
            else if (ch == '(')
                expression.push(ch);
            else if (ch == ')')
            {
                while (expression.top() != '(')
                {
                    ans.push_back(expression.top());
                    expression.pop();
                }
                expression.pop();
            }
            else
            {
                while (!expression.empty() && expression.top() != '(' && oper(ch) <= oper(expression.top()))
                {
                    ans.push_back(expression.top());
                    expression.pop();
                }
                expression.push(ch);
            }
        }
        while (!expression.empty())
        {
            ans.push_back(expression.top());
            expression.pop();
        }
        std::cout << ans << "\n";
        if (t)
            std::cout << "\n";
    }
    return 0;
}