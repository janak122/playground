#include <bits/stdc++.h>
using namespace std;

class Set
{
public:
    int *myset;
    int size;
    Set(int *_set, int _size)
    {
        myset = _set;
        size = _size;
    }
    Set() {}
};
void printArr(int *arr, int size)
{
    cout << "\t{";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " , ";
    cout << "},\n";
}
void printAns(list<Set *> &ansSets)
{
    cout << "{\n";
    for (Set *curr : ansSets)
        printArr(curr->myset, curr->size);
    cout << "}\n";
}
bool isPresent(map<int, bool> &_Set, int key, bool defaultVal)
{
    map<int, bool>::iterator it = _Set.find(key);
    return (it == _Set.end()) ? defaultVal : it->second;
}
void findSetCover(Set &_superSet, list<Set *> &family, list<Set *> &ansSets)
{
    ansSets.clear();
    map<int, bool> superSet;
    for (int i = 0; i < _superSet.size; i++)
        superSet[_superSet.myset[i]] = true;
    while (!superSet.empty())
    {
        int match = 0;
        Set *matchedSet;
        for (Set *curr : family)
        {
            int currMatch = 0;
            for (int i = 0; i < curr->size; i++)
                if (isPresent(superSet, curr->myset[i], false))
                    currMatch++;
            if (match <= currMatch)
            {
                match = currMatch;
                matchedSet = curr;
            }
        }
        if (match > 0)
        {
            ansSets.push_back(matchedSet);
            for (int i = 0; i < matchedSet->size; i++)
                if (isPresent(superSet, matchedSet->myset[i], false))
                    superSet.erase(matchedSet->myset[i]);
            family.remove(matchedSet);
        }
        else
            break;
    }
}

int main(int argc, char const *argv[])
{
    int _superSet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        set1[] = {1, 2, 3, 4, 5, 6},
        set2[] = {1, 4, 7, 10},
        set3[] = {2, 5, 7, 8, 11},
        set4[] = {3, 6, 9, 12},
        set5[] = {10, 9, 4, 11, 8};

    list<Set *> family, answer;
    Set superSet(_superSet, sizeof(_superSet) / sizeof(_superSet[0]));
    family.push_back(new Set(set1, sizeof(set1) / sizeof(set1[0])));
    family.push_back(new Set(set2, sizeof(set2) / sizeof(set2[0])));
    family.push_back(new Set(set3, sizeof(set3) / sizeof(set3[0])));
    family.push_back(new Set(set4, sizeof(set4) / sizeof(set4[0])));
    family.push_back(new Set(set5, sizeof(set5) / sizeof(set5[0])));

    findSetCover(superSet, family, answer);
    printAns(answer);
    return 0;
}
