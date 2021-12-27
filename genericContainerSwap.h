#pragma once

template <class T>
void genericSwap(T *firstItem, T *secondItem){
    auto tempContainer = secondItem;
    secondItem = firstItem;
    firstItem = tempContainer;
}