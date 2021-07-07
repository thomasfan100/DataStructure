//Header File Function Implementations

void get_identity(std::string& my_id)
{
	my_id = "tgfnzb";
	return;
}

template <typename K, typename V>
V& MyMap<K,V>::at_helper(TreeNode<MyPair<K,V>> *&rt, const K &key)
{
    if(rt == nullptr)
    {
        throw std::out_of_range ("MyMap::at\n");
    }
    else if(key < rt->data.first)
        return at_helper(rt->left, key);
    else if(key > rt->data.first)
        return at_helper(rt->right, key);
    else
        return rt->data.second;
}

template <typename K, typename V>
int MyMap<K,V>::size_helper(TreeNode<MyPair<K, V>> *rt) const
{
    if(rt == nullptr)
        return 0;
    return 1 + size_helper(rt->left) + size_helper(rt->right);
}

template <typename K, typename V>
void MyMap<K,V>::clear_helper(TreeNode<MyPair<K, V>> *&rt)
{
    if(rt == nullptr)
        return;

    clear_helper(rt->left);
    clear_helper(rt->right);

    delete rt;
}

template <typename K, typename V>
void MyMap<K,V>::insert_helper(TreeNode<MyPair<K, V>> *&rt, const MyPair<K, V> &init_pair)
{
    if(rt == nullptr)
    {
        rt = new TreeNode<MyPair<K, V>>(init_pair, nullptr, nullptr);
    }
    else if(init_pair.first < rt->data.first)
    {
        insert_helper(rt->left, init_pair);
    }
    else
    {
        insert_helper(rt->right, init_pair);
    }
    return;
}

template <typename K, typename V>
TreeNode<MyPair<K, V>> * MyMap<K,V>::get_min(TreeNode<MyPair<K, V>> *rt)
{
    if(rt->left == nullptr)
        return rt;
    else
        return get_min(rt->left);
}

template <typename K, typename V>
void MyMap<K,V>::erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key)
{
    if(rt == nullptr)
        return;
    else if(key < rt->data.first)
        erase_helper(rt->left, key);
    else if(key > rt->data.first)
        erase_helper(rt->right, key);
    else
    {
        // Found: pointer to save, to remove it
        TreeNode<MyPair<K,V>>*temp = rt;

        if(rt->left == nullptr) // Only a right child (at max) Also handles no children
        {
            rt = rt->right;         //  so point to right
            delete temp;
        }
        else if(rt->right == nullptr) // Only a left child (at max) Also handles no children
        {
            rt = rt->left;          //  so point to left
            delete temp;
        }
        else // Both children are present
        {
            TreeNode<MyPair<K,V>>* temp = get_min(rt->right);
            rt->data = temp->data;
            erase_helper(rt->right,temp->data.first);
        }
    }
}

template <typename K, typename V>
MyPair<K, V> * MyMap<K,V>::find_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const
{
    if(rt == nullptr)
        return nullptr;          // Empty tree

    if(key < rt->data.first)
        return find_helper(rt->left, key);   // Check left
    else if(key > rt->data.first)
        return find_helper(rt->right, key);  // Check right
    else
    {
        return &(rt->data);  // Found it (is this how i should do it?)
    }
}


template <typename K, typename V>
void MyMap<K,V>::print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const
{
    if(rt == nullptr)// Empty tree
    {
        cout << indent << "   [empty]" << endl;
        return;
    }

    print_helper(rt->right, indent += "  "); // Do right subtree
    cout << indent << " [" << rt->data.first << "]=" << rt->data.second<< endl;        // Print node value
    print_helper(rt->left, indent += ""); // Do left subtree
}

template <typename K, typename V>
int MyMap<K,V>::count_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const
{
    if(rt == nullptr)
    {
        return 0;
    }
    else if(rt->data.first == key)
    {
        return 1+ count_helper(rt->left,key) + count_helper(rt->right,key);
    }
    else
    {
        return count_helper(rt->left,key) + count_helper(rt->right,key);
    }

}

template <typename K, typename V>
TreeNode<MyPair<K, V>> * MyMap<K,V>::clone(const TreeNode<MyPair<K, V>> *rt)
{

    if(rt == nullptr)
    {
        return nullptr;
    }
    else
    {
        TreeNode<MyPair<K,V>> * newnode = new TreeNode<MyPair<K,V>>(rt->data,nullptr,nullptr);
        newnode->left = clone(rt->left);
        newnode->right = clone(rt->right);
        return newnode;
    }

}
//And finally the public functions
template <typename K, typename V>
MyMap<K,V>::MyMap()
{
    root = nullptr;
}

template <typename K, typename V>
MyMap<K,V>::~MyMap()
{
    clear_helper(root);
}

template <typename K, typename V>
MyMap<K,V>::MyMap(const MyMap<K, V> &source)
{
    root = clone(source.root);
}

template <typename K, typename V>
MyMap<K, V> & MyMap<K,V>::operator=(const MyMap<K, V> &source)
{
    clear();
    root = clone(source.root);
    return *this;
}

template <typename K, typename V>
V & MyMap<K,V>::at(const K &key)
{
    return at_helper(root,key);
}

template <typename K, typename V>
V & MyMap<K,V>::operator[](const K &key)
{
    if(find(key) == nullptr)
    {
        insert(MyPair<K,V>(key));
    }
    MyPair<K, V> * temp = find(key);
    return temp->second;
}

template <typename K, typename V>
bool MyMap<K,V>::empty() const
{
    if(size() == 0)
        return true;
    else
        return false;
}

template <typename K, typename V>
int MyMap<K,V>::size() const
{
    return size_helper(root);
}

template <typename K, typename V>
void MyMap<K,V>::clear()
{
    clear_helper(root);
    root = nullptr;
}

template <typename K, typename V>
void MyMap<K,V>::insert(const MyPair<K, V> &init_pair)
{
    if(find(init_pair.first) == nullptr)
        insert_helper(root,init_pair);
    else
        find(init_pair.first)->second = init_pair.second;
}

template <typename K, typename V>
void MyMap<K,V>::erase(const K &key)
{
    erase_helper(root,key);
    return;
}

template <typename K, typename V>
MyPair<K, V> * MyMap<K,V>::find(const K &key) const
{
    return find_helper(root,key);
}

template <typename K, typename V>
void MyMap<K,V>::print() const
{
    if(root == nullptr)
        print_helper(nullptr,"");
    else
        print_helper(root, "");
}

template <typename K, typename V>
int MyMap<K,V>::count(const K &key) const
{
    return count_helper(root,key);
}

void get_letter_frequency(MyMap<char, int> &in_tree)
{
    char choice;
    while(cin.get(choice))
    {
        if(in_tree.find(choice) == nullptr && choice != '\n' && (choice < 0 || choice > 31))
        {
            MyPair<char, int> temp(choice, 1);
            in_tree.insert(temp);
        }
        else if ( choice != '\n' && (choice < 0 || choice > 31))
        {
            in_tree.at(choice) = in_tree.at(choice) + 1;
        }
    }
}
