//Heap Implementation File
void get_identity(std::string& my_id)
{
	my_id = "tgfnzb";
	return;
}

template <typename T>
MyHeap<T>::MyHeap()
{
    heap = nullptr;
    maxsize = 0;
    num = 0;
}

template <typename T>
MyHeap<T>::MyHeap(const T array[],const int size)
{
    //should we consider size = 0
    //are we considering negative numbers in the data set

    //find new size
    int newsize = 1;
    int temp_multiplier = 2;
    while(newsize < size)
    {
      newsize += temp_multiplier;
      temp_multiplier *= 2;
    }
    //copy data
    heap = new T[newsize];
    for(int x = 0; x < size; x++)
        heap[x] = array[x];

    num = size;
    maxsize = newsize;

    //sift down
    for(int i = parent(num - 1); i >= 0; i--)
    {
        siftdown(i);
    }
}

template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &the_heap)
{
    maxsize = the_heap.maxsize;
    num = the_heap.num;
    heap = new T[maxsize];

    for(int x = 0; x < num; x++)
        heap[x] = the_heap.heap[x];
}

template <typename T>
MyHeap<T> & MyHeap<T>::operator =(MyHeap<T> &the_heap)
{
    if(heap != nullptr)
        delete[] heap;

    maxsize = the_heap.maxsize;
    num = the_heap.num;
    heap = new T[maxsize];

    for(int x = 0; x < num; x++)
        heap[x] = the_heap.heap[x];

    return *this;
}

template <typename T>
MyHeap<T>::~MyHeap()
{
    if(heap != nullptr)
        delete[] heap;
}

template <typename T>
T MyHeap<T>::top() const
{
    return heap[0];
}

template <typename T>
void MyHeap<T>::pop()
{
    T temp = heap[0];
    heap[0] = heap[num-1];
    heap[num-1] = temp;

    num--;
    if(num-1 != 0)
        siftdown(0);
    //implement a shrink to fit function
    if(num < maxsize/4)
    {
        shrink_to_fit();
    }

}

template <typename T>
void MyHeap<T>::push(const int elem)
{
    if(num+1 > maxsize)
    {
       reserve();
    }
    heap[num] = elem;

    //Sift up
    int curr = num;
    int temp;
    while((curr != 0) && (heap[curr] > heap[parent(curr)]))
    {
        temp = heap[curr];
        heap[curr] = heap[parent(curr)];
        heap[parent(curr)] = temp;

        curr = parent(curr);
    }
    num++;
    return;
}

template <typename T>
void MyHeap<T>::reserve()
{
    int newsize = maxsize;
    int level = 1;
    while(maxsize > 0)
    {
        maxsize -= level;
        level *= 2;
    }
    newsize += level;

    //destroy current array and copy contents
    T* datacopy = new T[num];
    for(int x = 0; x < num; x++)
        datacopy[x] = heap[x];
    delete[] heap;
    heap = new T[newsize];
    for(int x = 0; x < num; x++)
        heap[x] = datacopy[x];
    delete[] datacopy;
    maxsize = newsize;
    return;
}

template <typename T>
void MyHeap<T>::shrink_to_fit()
{
    int newsize = 1;
    int level = 2;
    while(newsize < num)
    {
        newsize += level;
        level *= 2;
    }

    //destroy current array and copy contents
    T* datacopy = new T[num];
    for(int x = 0; x < num; x++)
        datacopy[x] = heap[x];
    delete[] heap;
    heap = new T[newsize];
    for(int x = 0; x < num; x++)
        heap[x] = datacopy[x];
    delete[] datacopy;
    maxsize = newsize;
    return;
}

template <typename T>
bool MyHeap<T>::empty() const
{
    if(num == 0)
        return true;
    else
        return false;
}

template <typename T>
int MyHeap<T>::size() const
{
    //remove when done
    cout<<"__________"<<endl;
    for(int x = 0; x < num; x++)
        cout<<heap[x]<<":";
    cout<<endl;
    cout<<"__________"<<endl;
    cout<<"Num:"<<num<<"  Max Size:"<< maxsize<<endl;
    return num;
}

template <typename T>
void MyHeap<T>::siftdown(const int pos)
{
    int l = leftchild(pos);
    int r = rightchild(pos);
    int largest = pos;

    if(l < num && heap[l] > heap[pos])
        largest = l;

    if(r < num && heap[r] > heap[largest])
        largest = r;

    int temp = heap[pos];
    if(largest != pos)
    {
        heap[pos] = heap[largest];
        heap[largest] = temp;

        siftdown(largest);
    }

    return;
}

template <typename T>
int MyHeap<T>::leftchild(const int pos) const
{
    return ((2 * pos) + 1);
}

template <typename T>
int MyHeap<T>::rightchild(const int pos) const
{
    return ((2 * pos) + 2);
}

template <typename T>
int MyHeap<T>::parent(const int pos) const  // Return parent position
{
    return ((pos - 1) / 2);
}

