
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tree
{
    vector<int> tree;
public:
    Tree() { }

    void add(int data)
    {
        tree.push_back(data);
        int i = tree.size() - 1;
        for (int j = tree.size() - 2; j >= 0; j--)
        {
            if (tree[i] < tree[j])
            {
                int temp = tree[i];
                tree[i] = tree[j];
                tree[j] = temp;
                i--;
            }
        }
    }

    int get()
    {
        return tree[0];
    }

    void del()
    {
        tree.erase(tree.begin());
    }

    ~Tree() { }
};

int main()
{
    Tree tree;
    int n, num;
    string command;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "add")
        {
            cin >> num;
            tree.add(num);
        }
        if (command == "get")
        {
            cout << tree.get() << endl;
        }
        if (command == "del")
        {
            tree.del();
        }
    }
    return 0;
}