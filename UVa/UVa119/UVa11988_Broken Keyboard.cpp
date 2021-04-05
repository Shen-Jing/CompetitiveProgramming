#include <cstdio>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
const std::uint32_t maxn = 100;
int main(void)
{
    char s[maxn];
    while (std::scanf("%s", s + 1) != EOF)
    {
        std::uint32_t cur = 0, last = 0, next[maxn];
        next[0] = 0;
        std::size_t len{std::strlen(s + 1)};
        for (std::size_t i = 1; i <= len; ++i)
        {
            /* Home */
            if (s[i] == '[')
            {
                cur = 0;
            }
            /* End */
            else if (s[i] == ']')
            {
                cur = last;
            }
            else
            {
                next[i] = next[cur];
                next[cur] = i;
                if (cur == last)
                    last = i;
                cur = i;
            }
        }      
        /* Output */
        for (std::size_t i = next[0]; i != 0; i = next[i])
        {
            std::cout << s[i];
        }
        std::cout << "\n";
    }
    return 0;
}