#pragma once
#include "intComparison.h"

template <template <class> class ST, class T>
void genericInsertion(ST<T> *givenSequence, bool (*compf)(T*, T*) = &isFirstMore)
{
    int i, j;
    T *key;
    for (i = 1; i < givenSequence->GetLength(); ++i)
    {
        key = givenSequence->Get(i);
        j = i - 1;

        while (j >= 0 && (*compf)(givenSequence->Get(j), key))
        {
            givenSequence->Set(j + 1, givenSequence->Get(j));
            --j;
        }
        givenSequence->Set(j + 1, key);
    }
}