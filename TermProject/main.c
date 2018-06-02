#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main()
{
    int i = 0;
    UserType *user = (UserType*)malloc(sizeof(UserType));
    init_userType(user);
    insert_user(user);
    add_friends(user);
    add_mentions(user);

    for (i = 0; i < user->count; i++)
    {
        printf("%d\t%s\n", user->user[i]->id_num, user->user[i]->name);
    }

    //확인용 출력
    for (i = 0; i < 10; i++)
    {
        int random = rand() % 7000;
        User *temp = user->user[random];
        printf("%s 친구 :", temp->name);
        for (temp = temp->friends; temp->friends != NULL; temp = temp->friends)
        {
            printf(" %s,", temp->name);
        }
        printf("\n");
        temp = user->user[random];
        Word *w = temp->mentions;

        for (; w != NULL; w = w->next)
        {
            printf(" %s,", w->mention);
        }
        printf("\n");

    }


    return 0;
}

