//Define all header files below...
void get_identity(string& my_id)
{
	my_id = "tgfnzb";
	return;
}

template <typename T>
MyList<T>::MyList()
{
    m_sentinel = new Node<T>(nullptr,nullptr);
    m_sentinel->m_prev = m_sentinel;
    m_sentinel->m_next = m_sentinel;
    m_size = 0;
}

template <typename T>
MyList<T>::~MyList()
{
    Node<T>* curr = m_sentinel;
    for(int x =0; x < m_size; x++)
    {
        curr = curr->m_next;
        delete curr;
    }
    delete m_sentinel;
    //do i need to set m_sentinel to nullptr?
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
    clear();
    m_size = 0; //gives error when I do .size()?

    Node<T> *source_node = source.m_sentinel;

    for(int x =0; x<source.m_size;x++)
    {
        source_node = source_node->m_next;
        push_back(source_node->m_element);
    }

    return *this;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
    m_sentinel =  new Node<T>(nullptr,nullptr);
    m_sentinel->m_prev = m_sentinel;
    m_sentinel->m_next = m_sentinel;
    m_size = 0;

    Node<T> *source_node = source.m_sentinel;

    for(int x =0; x<source.m_size;x++)
    {
        source_node = source_node->m_next;
        push_back(source_node->m_element);
    }
}

template <typename T>
T & MyList<T>::front()
{
    return m_sentinel->m_next->m_element;
}

template <typename T>
T & MyList<T>::back()
{
    return m_sentinel->m_prev->m_element;
}

template <typename T>
void MyList<T>::assign(int count, const T &value)
{
    clear();
    for(int x =0; x < count; x++)
    {
        push_back(value);
    }
}

template <typename T>
void MyList<T>::clear()
{
    Node<T>* curr = m_sentinel;
    for(int x = 0; x<m_size; x++)
    {
        curr = curr->m_next;
        delete curr;
    }
    m_size = 0;
    m_sentinel->m_next = m_sentinel;
    m_sentinel->m_prev = m_sentinel;
}

template <typename T>
void MyList<T>::push_front(const T &x)
{
    if(m_size != 0)
    {
        Node<T>* the_node = new Node<T>(x,m_sentinel,m_sentinel->m_next);
        m_sentinel->m_next->m_prev = the_node;
        m_sentinel->m_next = the_node;
    }
    else
    {
        Node<T>* the_node = new Node<T>(x,m_sentinel,m_sentinel);
        m_sentinel->m_next = the_node;
        m_sentinel->m_prev = the_node;
    }
    m_size++;
}

template <typename T>
void MyList<T>::push_back(const T &x)
{
    if(m_size != 0)
    {
        Node<T>* the_node = new Node<T>(x,m_sentinel->m_prev,m_sentinel);
        m_sentinel->m_prev->m_next = the_node;
        m_sentinel->m_prev = the_node;
    }
    else
    {
        Node<T>* the_node = new Node<T>(x,m_sentinel,m_sentinel);
        m_sentinel->m_next = the_node;
        m_sentinel->m_prev = the_node;
    }
    m_size++;
}

template <typename T>
void MyList<T>::pop_back()
{
    if(m_size != 0)
    {
        Node<T>* it = m_sentinel->m_prev;
        m_sentinel->m_prev->m_prev->m_next = m_sentinel;
        m_sentinel->m_prev = m_sentinel->m_prev->m_prev;
        delete it;
        m_size--;
    }
}

template <typename T>
void MyList<T>::pop_front()
{
    if(m_size != 0)
    {
        Node<T>* it = m_sentinel->m_next;
        m_sentinel->m_next->m_next->m_prev = m_sentinel;
        m_sentinel->m_next = m_sentinel->m_next->m_next;
        delete it;
        m_size--;
    }
}

template <typename T>
void MyList<T>::insert(int i, const T &x)
{
    if(i <= m_size)
    {
        Node<T>* curr = m_sentinel;
        for(int x =0; x <= i; x++)
        {
            curr = curr->m_next;
        }

        Node<T>* the_node = new Node<T>(x,curr->m_prev,curr);
        the_node->m_next->m_prev = the_node;
        the_node->m_prev->m_next = the_node;
        m_size++;
    }
}

template <typename T>
void MyList<T>::remove(T value)
{
    Node<T>* curr = m_sentinel;
    int removals = 0;
    for(int x =0; x<m_size;x++)
    {
        curr = curr->m_next;
        if(curr->m_element == value)
        {
            curr->m_next->m_prev = curr->m_prev;
            curr->m_prev->m_next = curr->m_next;
            removals++;
            delete curr;
        }
    }
    for(int x = 0; x < removals; x++)
    {
        m_size--;
    }
}

template <typename T>
void MyList<T>::erase(int i)
{
    if(i < m_size)
    {
        Node<T>* curr = m_sentinel;
        for(int x=0; x<=i ;x++)
        {
            curr = curr->m_next;
        }
        curr->m_next->m_prev = curr->m_prev;
        curr->m_prev->m_next = curr->m_next;
        m_size--;
        delete curr;
    }
}

template <typename T>
void MyList<T>::reverse()
{
    Node<T>* curr = m_sentinel;
    Node<T>* curr2 = m_sentinel->m_next;

    for(int x=0; x<= m_size;x++)
    {
        curr->m_next = curr->m_prev;
        curr->m_prev = curr2;
        curr = curr2;
        curr2 = curr2->m_next;
    }

    curr = nullptr;
    curr2 = nullptr;
    delete curr;
    delete curr2;
}

template <typename T>
bool MyList<T>::empty()
{
    if(m_size == 0)
        return true;
    else
        return false;

    return true;
}

template <typename T>
int MyList<T>::size()
{
    return m_size;
}

