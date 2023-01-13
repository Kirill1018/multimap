#include "multimap.h"
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    tree* _tree = 0;//указатель на объект класса
    tree wood;
    FILE* in = fopen("data.txt", "r");
    int t = 0, i = 0;//итератор и параметр цикла
    char* word = new char[maxline + 1];
    while (!feof(in))
    {
        fscanf(in, "%s", word);
        int tal = strlen(word);
        for (int i = 0; i < tal; i++)
        {
            wood.upp_lett(word, i);
            if (ispunct((unsigned char)word[i]) || word[i] == ' ' || word[i] == (char)(133) || word[i] == (char)(187) || word[i] == (char)(150) || word[i] == (char)(151) || word[i] == (char)(171)) for (int j = i; j < tal; j++) word[i] = word[j + 1];
        }
        if (strcmp(word, ""))
        {
            if (_tree == 0) _tree = wood.tree_insert(_tree, word);
            else wood.tree_insert(_tree, word);
        }
        strcpy(word, "");
    }
    fclose(in);
    t = wood.tree_amount(_tree);
    tree** arr = new tree * [t];
    wood.tree_point(_tree, arr, i);
    wood.point_sort(arr, t);
    wood.print_freq(arr, t);
}