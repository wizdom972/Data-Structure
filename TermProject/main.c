#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "friend.h"
#include "word.h"

int main()
{
    UserType *user = (UserType*)malloc(sizeof(UserType));
	init(user);
    Heap *h = (Heap*)malloc(sizeof(Heap));
    init_Heap(h);
    
    Word *word_sorted_words = (Word*)malloc(sizeof(Word));  //단어 사전 순으로 정렬
    Word *num_sorted_words = (Word*)malloc(sizeof(Word));   //단어 횟수 순으로 정렬
    init_Word(word_sorted_words);
    init_Word(num_sorted_words);

    insert_word(h, user, word_sorted_words);
    num_sorted_words = num_sort(word_sorted_words);

	int friend_num[MAX_USER] = { 0 };
	memcpy(friend_num, get_friend_num(user), sizeof(friend_num));
    
    
    for (int i = 0; i < user->count; i++)
    {
        printf("%10d %20s \t친구수: %5d\n", user->user[i]->id_num, user->user[i]->name, friend_num[i]);
    }

    for (int i = 0; i < 1000; i++)
    {
        printf("%s : %d\n", num_sorted_words->node[i]->tweet, num_sorted_words->node[i]->count);
    }

    system("pause");
    return 0;
}

