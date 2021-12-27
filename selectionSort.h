#pragma once
#include "genericContainerSwap.h"
#include "intComparison.h"

template <template <class> class ST, class T>
void genericSelection(ST<T> *givenSequence, bool (*compf)(T*, T*) = &isFirstMore)
{
    int i, j, k, m = givenSequence->GetLength();
    for (i = 0; i < m - 1; ++i)
    {
        k = i;
        for (j = i + 1; j < m; ++j)
        {
            if (compf(givenSequence->Get(k), givenSequence->Get(j)))
            {
                k = j;
            }
        }
        genericSwap<T>(givenSequence->Get(i), givenSequence->Get(k));
    }
}