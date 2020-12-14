#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int profit, weight;
    Item(int _x, int _y)
    {
        profit = _x;
        weight = _y;
    }
    Item() {}
};
void printList(list<Item *> &items)
{
    cout << "{ ";
    for (Item *it : items)
        cout << it->profit << " ,";
    cout << "}\n";
}
void zerOneKnapsack(Item *items, int size, int capacity, int expectation, list<Item *> &selected)
{
    int mat[size + 1][capacity + 1];
    for (int i = 0; i <= capacity; i++)
        mat[0][i] = 0;
    for (int i = 1; i <= size; i++)
    {
        mat[i][0] = 0;
        for (int j = 1; j <= capacity; j++)
        {
            mat[i][j] = mat[i - 1][j];
            if (items[i - 1].weight <= j)
                if (items[i - 1].profit + mat[i - 1][j - items[i - 1].weight] > mat[i][j])
                    mat[i][j] = items[i - 1].profit + mat[i - 1][j - items[i - 1].weight];
        }
    }
    int i = size, j = capacity;
    while (i > 0 && j > 0)
    {
        if (mat[i][j] != mat[i - 1][j])
        {
            selected.push_back(&items[i - 1]);
            j -= items[i - 1].weight;
        }
        i--;
    }
}

void sumOfsubSet(int arr[], int size, int sum)
{
    Item *items = new Item[size];
    for (int i = 0; i < size; i++)
        items[i].profit = items[i].weight = arr[i];
    list<Item *> answer;
    zerOneKnapsack(items, size, sum, sum, answer);
    printList(answer);
}

int main(int argc, char const *argv[])
{
    int arr1[] = {3, 4, 5, 2, 7, 9},
        arr2[] = {10, 2, 6, 8, 13, 21, 3, 5, 9};

    sumOfsubSet(arr1, sizeof(arr1) / sizeof(arr1[0]), 12);
    sumOfsubSet(arr2, sizeof(arr2) / sizeof(arr2[0]), 25);

    return 0;
}
