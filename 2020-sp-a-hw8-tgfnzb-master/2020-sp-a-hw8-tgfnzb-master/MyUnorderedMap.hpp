using namespace std;
void get_identity(std::string& my_id)
{
	my_id = "tgfnzb";
	return;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::hash (const K &key) const
{
    int sum = 0;
    for(int x = 0; key[x] != '\0'; x++)
        sum+=(int)(key[x]);
    return sum%reserved_size;
}
template <typename K, typename V>
MyUnorderedMap<K,V>::MyUnorderedMap()
{
    data_size = 0;
    reserved_size = 0;
    m_data = nullptr;
}

template <typename K, typename V>
MyUnorderedMap<K,V>::~MyUnorderedMap()
{
    delete[] m_data;
}

template <typename K, typename V>
MyUnorderedMap<K,V>::MyUnorderedMap(const MyUnorderedMap<K, V> &source)
{
    data_size = source.data_size;
    reserved_size = source.reserved_size;
    if(data_size != 0)
    {
        m_data = new MyPair<K,V>[reserved_size];
        for(int x = 0; x < reserved_size; x++)
        {
            m_data[x].first = source.m_data[x].first;
            m_data[x].second = source.m_data[x].second;
        }
    }
}

template <typename K, typename V>
MyUnorderedMap<K, V> & MyUnorderedMap<K,V>::operator=(const MyUnorderedMap<K, V> &source)
{
    if(m_data != nullptr)
        delete[] m_data;

    data_size = source.data_size;
    reserved_size = source.reserved_size;
    if(data_size != 0)
    {
        m_data = new MyPair<K,V>[reserved_size];
        for(int x = 0; x < reserved_size; x++)
        {
            m_data[x].first = source.m_data[x].first;
            m_data[x].second = source.m_data[x].second;
        }
    }
    return *this;
}

template <typename K, typename V>
V & MyUnorderedMap<K,V>::at(const K &key)
{
    MyPair<K,V> *temp = find(key);

    if(temp!=nullptr)
        return temp->second;
    temp = new MyPair<K,V>(key);
    insert(*temp);
    delete temp;
    return find(key)->second;
}

template <typename K, typename V>
V & MyUnorderedMap<K,V>::operator[](const K &key)
{
    MyPair<K,V> *temp = find(key);

    if(temp!=nullptr)
        return temp->second;
    temp = new MyPair<K,V>(key);
    insert(*temp);
    delete temp;
    return find(key)->second;
}

template <typename K, typename V>
bool MyUnorderedMap<K,V>::empty() const
{
    if(data_size == 0)
        return true;
    else
        return false;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::size() const
{
    return data_size;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::clear()
{
    for(int i = 0; i < reserved_size; i++)
    {
        m_data[i].first= "EMPTY";
    }

    data_size = 0;
    return;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::insert(const MyPair<K, V> &init_pair)
{
    if(empty())
    {
        reserve(2);
    }
    else if(data_size+1 > reserved_size * .6)
        reserve(reserved_size *2);

    //inserting...
    int home;                     // Home position for e
    int pos = home = hash(init_pair.first);        // Init probe sequence

    for(int i = 1; "EMPTY" != m_data[pos].first && "TOMB" != m_data[pos].first; i++)
    {
        //Assert(k != HT[pos].key(), "Duplicates not allowed");
        if(init_pair.first == m_data[pos].first)
            return;
        // probe sequence
        pos = (home + i) % reserved_size;
    }

    MyPair<K,V> temp(init_pair.first, init_pair.second);
    m_data[pos] = temp;

    data_size++;
    return;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::erase(const K &key)
{
    if(data_size < reserved_size * .1)
        reserve(static_cast<int>(reserved_size * .3));

    int home;                   // Home position for e
    int pos = home = hash(key);      // Init probe sequence
    int i = 1;

    // while or for both work here
    // Leaves pos at the key or empty
    while(key != m_data[pos].first && m_data[pos].first != "TOMB")
    {
        pos = (home + i) % reserved_size; // probe
        i++;
    }

    // If pos indexes the key (it is not empty)
    if(m_data[pos].first != "EMPTY")
    {
        m_data[pos].first = "TOMB";
        data_size--;
    }
}

template <typename K, typename V>
MyPair<K, V> * MyUnorderedMap<K,V>::find(const K &key) const
{
    if(reserved_size == 0)
        return nullptr;

    int home;                   // Home position for k
    int pos = home = hash(key);      // Initial position is home slot

    // Leaves the pos index at the key location or empty location

    for(int i = 1; (key != m_data[pos].first) && ("EMPTY" != m_data[pos].first); i++)
    {
        pos = (home + i) % reserved_size; // Next on probe sequence
    }

    if(key == m_data[pos].first)      // Found it
    {
        // Returns the value stored under the searched key
        return &m_data[pos]; //Am i doing this right?
    }
    else
    {
        return nullptr;            // k not in hash table
        // this is why we are using a pointer type as the value in main
    }
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::print() const
{
    int data_printed = 1;
    cout<<"(";
    for(int x =0; x<reserved_size; x++)
    {
        if(m_data[x].first != "TOMB" && m_data[x].first != "EMPTY")
        {

            if(data_printed < data_size)
                cout<<"["<<m_data[x].first<<"]="<<m_data[x].second<<","<<endl;
            else if(data_printed == data_size)
                cout<<"["<<m_data[x].first<<"]="<<m_data[x].second;
            data_printed++;
        }
    }
    cout<<")"<<endl;
    return;
}

template <typename K, typename V>
int MyUnorderedMap<K,V>::count(const K &key) const
{
    if(find(key) != nullptr)
        return 1;
    else
        return 0;
}

template <typename K, typename V>
void MyUnorderedMap<K,V>::reserve(int new_cap)
{
    MyPair<K,V> *temp = new MyPair<K,V>[reserved_size];

    for(int i = 0; i < reserved_size; i++)
            temp[i]=m_data[i];
    delete[] m_data;
    m_data = new MyPair<K,V>[new_cap];

    for(int i = 0; i < new_cap; i++)
        m_data[i].first = "EMPTY";

    int old_cap = reserved_size;
    reserved_size = new_cap;

    for(int i= 0; i < old_cap; i++)
    {
        if(!(temp[i].first=="EMPTY" || temp[i].first == "TOMB"))
        {
            int home=hash(temp[i].first);
            int pos=home;
            for(int j=1; !(m_data[pos].first=="EMPTY"||m_data[pos].first=="TOMB"); j++)
            {
                pos = (home+j)%reserved_size;
            }
            m_data[pos] = temp[i];
        }
    }

    delete[] temp;
    temp = nullptr;
    return;
}

void get_virus_frequency(MyUnorderedMap<std::string, int> &in_tree)
{
    bool continue_search = true;
    string word, new_word;
    string lower_case;
    int start, end;
    while(cin>>word)
    {
        //to lower case
        do
        {
            for(unsigned int x = 0; x< word.length(); x++)
            {
                if(word[x] > 64 && word[x] < 91)
                    lower_case += word[x]+32;
                else
                    lower_case += word[x];
            }
            if(word.length() < 5)
                continue_search = false;
            else if(lower_case.find("virus") != std::string::npos)
            {
                //start and end of word
                for(int x = lower_case.find("virus"); x>=0; x--)
                {
                    if((word[x] > 64 && word[x] < 91)|| (word[x] > 96 && word[x] < 123)
                       || word[x] == '_' || (word[x]>47 && word[x]<58))
                    {
                           start = x;
                    }
                    else
                        x = -1;
                }
                for(unsigned int x = lower_case.find("virus"); x<word.length(); x++)
                {
                    if((word[x] > 64 && word[x] < 91)|| (word[x] > 96 && word[x] < 123)
                       || word[x] == '_' || (word[x]>47 && word[x]<58))
                       end = x;
                    else
                        x = word.length();
                }

                new_word = word.substr(start,end-start+1);
                unsigned int z = end+1;
                if(z < word.length())
                {
                    word = word.substr(end+1);
                    continue_search = true;
                }
                else
                    continue_search = false;
                //put word in hashtable
                if(in_tree.find(new_word)==nullptr)
                {
                    MyPair<string,int> temp(new_word,1);
                    in_tree.insert(temp);
                }
                else
                {
                    in_tree.at(new_word)=in_tree.at(new_word)+1;
                }
            }
            else
                continue_search = false;
            lower_case = "";
        }while(continue_search);
    }
    return;
}

