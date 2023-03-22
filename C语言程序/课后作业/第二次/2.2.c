#include <stdio.h>
#include <ctype.h>
int count(char *a);

int main()
{
    char cards[26] = {0};
    char cards_small[26] = {0};
    printf("Please enter your cards:");
    scanf("%s",cards);
    for (int i = 0; i < 26; i++)
    {
        cards_small[i] = tolower(cards[i]);
    }
    
    printf("Scrabble value: %d", count(cards_small));

    return 0;   
}

int count(char *a)
{
    int total = 0;
    char *p = a;
    for (; p < a + 26; p++)
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'l' || *p == 'n' || *p == 'o' || *p == 'r' || *p == 's' || *p == 't' || *p == 'u')
        {
            total += 1;
        }
        if (*p == 'd' || *p == 'g')
        {
            total += 2;
        }
        if (*p == 'b' || *p == 'c' || *p == 'm' || *p == 'p')
        {
            total += 3;
        }
        if (*p == 'f' || *p == 'h' || *p == 'v' || *p == 'w' || *p == 'y')
        {
            total += 4;
        }
        if (*p == 'k')
        {
            total += 5;
        }
        if (*p == 'j' || *p == 'x')
        {
            total += 8;
        }
        if (*p == 'q' || *p == 'z')
        {
            total += 10;
        }
    }
    return total;  
}
