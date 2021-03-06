#pragma once
#include <vector>
#include <assert.h>

template<typename T>
class Aggregator
{
public:

    void add(unsigned int index, T item);
    void clear(unsigned int index);
    void clear();

    unsigned int size() const;
    unsigned int size(unsigned int index) const;

    const std::vector<T>* get(unsigned int index) const;

private:

    void checkCapacity(unsigned int index);

    std::vector<std::vector<T>> itemLists = {{}};
};

template<typename T>
void Aggregator<T>::add(unsigned int index, T item)
{
    checkCapacity(index);
    itemLists[index].push_back(item);
}

template<typename T>
void Aggregator<T>::clear(unsigned int index)
{
    itemLists[index].clear();
}

template<typename T>
void Aggregator<T>::clear()
{
    for (auto &list : itemLists) {
        list.clear();
    }
}

template<typename T>
unsigned int Aggregator<T>::size() const
{
    return unsigned(itemLists.size());
}

template<typename T>
unsigned int Aggregator<T>::size(unsigned int index) const
{
    assert(index < itemLists.size() && "index out of bounds");
    return unsigned(itemLists[index].size());
}

template<typename T>
const std::vector<T>* Aggregator<T>::get(unsigned int index) const
{
    assert(index < itemLists.size() && "index out of bounds");
    return &itemLists.at(index);
}

template<typename T>
void Aggregator<T>::checkCapacity(unsigned int index)
{
    if (index >= itemLists.size()) {
        itemLists.resize(index + 1);
    }
}
