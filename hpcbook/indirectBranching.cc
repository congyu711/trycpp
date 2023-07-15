#include <bits/stdc++.h>
using namespace std;

void weather_in_russia(int season)
{
    // https://stackoverflow.com/questions/45380073/can-you-make-a-computed-goto-in-c
    // language extension. `&&` gets the address of labels. If followed by `*`, goto is computed!
    // gcc and clang support this.
    static const void *table[] = {&&winter, &&spring, &&summer, &&fall};
    goto *table[season];

winter:
    printf("Freezing\n");
    return;
spring:
    printf("Dirty\n");
    return;
summer:
    printf("Dry\n");
    return;
fall:
    printf("Windy\n");
    return;
}


int main()
{
    weather_in_russia(1);
}