#include <stdio.h>
#include <string.h>
struct TEAM
{
    char name[20];
    double score;
};

struct MATCH
{
    char team1[20];
    char team2[20];
    double  score1;
    double  score2;
};

int main()
{
    double money[100];
    int teams = 0, matchs = 0;
    scanf("%d",&teams);
    struct TEAM reslut[teams];

    for (int i = 0; i < teams; ++i) {
        for (int j = 0; j < 20; ++j) {
            reslut[i].name[j] = 0;
        }
    }

    for (int i = 0; i < teams; i++)
    {
        scanf("%s",reslut[i].name);
        scanf("%lf",&reslut[i].score);
    }

    scanf("%d",&matchs);
    struct MATCH fire[matchs];

    for (int i = 0; i < matchs; ++i) {
        for (int j = 0; j < 20; ++j) {
            fire[i].team1[j] = 0;
            fire[i].team2[j] = 0;
        }
    }

    for (int i = 0; i < matchs; i++)
    {
        scanf("%s",fire[i].team1);
        scanf("%s",fire[i].team2);

        for (int j = 0; j < teams; j++)
        {
            if (strcmp(fire[i].team1, reslut[j].name)==0)
                fire[i].score1 = reslut[j].score;

            if (strcmp(fire[i].team2, reslut[j].name)==0)
                fire[i].score2 = reslut[j].score;

        }

        if (fire[i].score1 > fire[i].score2)
            money[i] = fire[i].score1 / fire[i].score2;
        else
            money[i] = fire[i].score2 / fire[i].score1;
    }

    for (int i = 0; i < matchs; i++)
    {
        printf("%.20f\n",money[i]);
    }


    return 0;
}

