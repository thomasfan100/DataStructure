/* Define all your MyVector-related functions here.
 * Also, define the swap function here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */

 void get_identity(string& my_id)
{
	my_id = "tgfnzb";
	return;
}

template <typename T>
void MySwap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

//Constructors and Destructors
template <typename T>
MyVector<T>::MyVector()
{
    m_data = nullptr;
    reserved_size = 0;
    data_size = 0;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
  m_data = new T[source.reserved_size];
  reserved_size = source.reserved_size;
  data_size = source.data_size;
  for(int i = 0; i < data_size; i++)
    m_data[i] = source.m_data[i];
}

template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

template <typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
  if(reserved_size != source.reserved_size)
  {
      delete[] m_data;
      m_data = new T[source.reserved_size];
      reserved_size = source.reserved_size;
  }
  for(int i = 0; i < source.data_size; i++)
    m_data[i] = source.m_data[i];

  data_size = source.data_size;
  return *this;
}

template <typename T>
T & MyVector<T>::operator[](int i)
{
    return *(m_data+i);
}

template <typename T>
T & MyVector<T>::at(int index)
{
    if(!(index<size()))
    {
        throw std::out_of_range("what(): array index out of range");
    }
    return m_data[index];
}

template <typename T>
T & MyVector<T>::front()
{
    return m_data[0];
}

template <typename T>
T & MyVector<T>::back()
{
    return m_data[data_size-1];
}

template <typename T>
int MyVector<T>::capacity()
{
    return reserved_size;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
    //Creates copy of data, deletes current data
    //Creates new array and copies copied data
    T data_copy[data_size];
    int length = data_size;
    for(int x = 0; x < data_size; x++)
        data_copy[x] = m_data[x];
    clear();
    m_data = new T[new_cap];
    for(int x = 0; x < length; x++)
        m_data[x] = data_copy[x];
    reserved_size = new_cap;
    data_size = length;
}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    int new_reserved_size = 2 * data_size; //temp var
    T data_copy[data_size];
    int length = data_size;
    for(int x = 0; x < data_size; x++)
        data_copy[x] = m_data[x];
    clear();
    m_data = new T[new_reserved_size];
    for(int x = 0; x < length; x++)
        m_data[x] = data_copy[x];
    reserved_size = new_reserved_size;
    data_size = length;
}

template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
    reserve(count);
    data_size = 0;
    for(int i = 0; i < count; i++)
    {
        m_data[i]= value;
        data_size++;
    }
}

template <typename T>
void MyVector<T>::clear()
{
    reserved_size = 0;
    data_size = 0;
    delete []m_data;
    m_data = nullptr;
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
    if(data_size >= reserved_size)
        reserve(data_size+1);
    m_data[data_size] = x;
    data_size++;
}

template <typename T>
void MyVector<T>::pop_back()
{
    if(data_size > 0)
      data_size--;
}

template <typename T>
void MyVector<T>::insert(int i, const T &x)
{
    if(i <= data_size)
    {
       if(data_size >= reserved_size)
          reserve(data_size+1);
       data_size++;
       for(int a = data_size-1; a > i; a--)
       {
          m_data[a] = m_data[a-1];
       }
       m_data[i] = x;
    }
}

template <typename T>
void MyVector<T>::erase(int i)
{
    if(i < data_size)
    {
        for(int x = i; x < data_size-1; x++)
        {
            m_data[x] = m_data[x+1];
        }
        data_size--;
        if(data_size < reserved_size / 4.0 )
        {
            shrink_to_fit();
        }
    }
}

template <typename T>
int MyVector<T>::size()
{
    return data_size;
}
