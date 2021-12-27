#pragma once
#include "genericContainerSwap.h"
#include "intComparison.h"

template <template <class> class ST, class T>
void genericShaker(ST<T> *givenSequence, bool (*compf)(T*, T*) = &isFirstMore)
{
    int i, j, k, m = givenSequence->GetLength();
    for (i = 0; i < m;)
    {
        for (j = i + 1; j < m; ++j)
        {
            if ((*compf)(givenSequence->Get(j - 1), givenSequence->Get(j)))
            {
                genericSwap<T>(givenSequence->Get(j), givenSequence->Get(j - 1));
            }
        }
        --m;
        for (k = m - 1; k > i; --k)
        {
            if ((*compf)(givenSequence->Get(k - 1), givenSequence->Get(k)))
            {
                genericSwap<T>(givenSequence->Get(k), givenSequence->Get(k - 1));
            }
        }
        ++i;
    }
}