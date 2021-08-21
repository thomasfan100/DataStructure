// Mimic the std:: version
#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

template <typename T>
bool my_is_sorted(const T array[], int size)
{
    bool max_first = true;
    for(int x = 0; x < size; x++)
    {
        if(x+1 < size)
        {
            if(array[x] < array[x+1])
                max_first = false;
        }
    }
    return max_first;
}
#endif
