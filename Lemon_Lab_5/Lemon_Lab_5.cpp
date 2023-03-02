#include <iostream>
#include <string>

bool is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool is_char(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
#include <vector>

std::string cypher(const std::string& str)
{
    std::string res = str;

    std::vector<char> v = { 'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E' };

    for (int i = 0; i < str.size(); i++)
    {
        if (is_char(str[i]))
        {
            if (is_upper(str[i]))
            {
                res[i] = v[str[i] - 'A'];
            }
            else //Must be lower
            {
                res[i] = v[str[i] - 'a'] + 32;
            }
        }

        //Else we just pass
    }

    return res;
}


int main()
{
    std::string in;
    std::getline(std::cin, in);

    if (in.size() > 128)
    {
        in = in.substr(0, 128); // Keep only the first 128 characters
    }

    std::cout << cypher(in) << '\n';
    return 0;
}