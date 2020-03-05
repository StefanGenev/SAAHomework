#include<iostream>
#include <map>
using namespace std;
//GRAPH DOMASHNO
const int n = 15;
struct link
{
    char key;
    link* next;
}
*gr[n];
void init(link* gr[n]);
int search_node(link* gr[n], char c);
int search_arc(link* gr[n], char c1, char c2);
void add_node(link* gr[n], char c);
void add_arc(link* gr[n], char c1, char c2);
void del_node(link* gr[n], char c);
void del_arc(link* gr[n], char c1, char c2);
void find_node_with_most_entry_arcs(link* gr[n]);
void list_node(link* gr[n]);
void main()
{
    char c, k;
    int m;
    do
    {
        cout << "Menu\n";
        cout << "1.Init\n";
        cout << "2.Add node\n";
        cout << "3.Add arc\n";
        cout << "4.Del node\n";
        cout << "5.Del arc\n";
        cout << "6.Search node\n";
        cout << "7.Search arc\n";
        cout << "8.Print All\n";
        cout << "9.Find node with most entry arcs and delete it\n";
        cout << "10.Exit\n";
        cin >> m;
        switch (m)
        {
        case 1:
            init(gr);
            break;
        case 2:
            cout << "Enter node: ";
            cin >> c;
            add_node(gr, c);
            break;
        case 3:
            cout << "Enter first node: ";
            cin >> c;
            cout << "Enter second node: ";
            cin >> k;
            add_arc(gr, c, k);
            break;
        case 4:
            cout << "Enter node: ";
            cin >> c;
            del_node(gr, c);
            break;
        case 5:
            cout << "Enter first node: ";
            cin >> c;
            cout << "Enter second node: ";
            cin >> k;
            del_arc(gr, c, k);
            break;
        case 6:
            cout << "Enter node: ";
            cin >> k;
            if (search_node(gr, k))
                cout << "Search result : OK \n";
            else
                cout << "Search result: NO \n";
            break;
        case 7:
            cout << "Enter first node: ";
            cin >> c;
            cout << "Enter second node: ";
            cin >> k;
            if (search_arc(gr, c, k))
                cout << "Search result : OK\n";
            else
                cout << "Search result : NO\n";
            break;
        case 8:
            list_node(gr);
            break;
        case 9:
            find_node_with_most_entry_arcs(gr);
        }
    } while (m != 10);
    cout << endl;
    system("pause");
}
int search_node(link* gr[n], char c)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (gr[i])
            if (gr[i]->key == c)
                flag = 1;
    return flag;
}
int search_arc(link* gr[n], char c1, char c2)
{
    int flag = 0;
    if (search_node(gr, c1) && search_node(gr, c2))
    {
        int i = 0;
        while (gr[i] == NULL || gr[i]->key != c1)
        {
            i++;
            
            
        }
            
        link* p = gr[i];
        while (p->key != c2 && p->next != NULL)
            p = p->next;
        if (p->key == c2)
            flag = 1;
    }
    return flag;
}
void add_node(link* gr[n], char c)
{
    if (search_node(gr, c))
        cout << "\n Existing node \n";
    else
    {
        int j = 0;
        while (gr[j] && j < n)
            j++;
        if (gr[j] == NULL)
        {
            gr[j] = new link;
            gr[j]->key = c;
            gr[j]->next = NULL;
        }
        else
            cout << "\n Overflow \n";
    }
}
void add_arc(link* gr[n], char c1, char c2)
{
    if (search_arc(gr, c1, c2))
        cout << "\n Existing arc \n";
    else
    {
        if (!search_node(gr, c1))
            add_node(gr, c1);
        if (!search_node(gr, c2))
            add_node(gr, c2);
        int i = 0;
        link* p;
        while (gr[i]->key != c1)
            i++;
        p = new link; p->key = c2;
        p->next = gr[i]->next; gr[i]->next = p;
    }
}
void list_node(link* gr[n])
{
    for (int i = 0; i < n; i++)
        if (gr[i])
            cout << gr[i]->key;
    cout << endl;
}
void init(link* gr[n])
{
    for (int i = 0; i < n; i++)
        gr[i] = NULL;
}
void del_node(link* gr[n], char c)
{
    if (search_node(gr, c))
    {
        int i = 0; link* p = NULL, * q = NULL;
        while (gr[i] == NULL || gr[i]->key != c)
            i++;
        while (gr[i] != NULL)
        {
            p = gr[i];
            gr[i] = gr[i]->next;
            delete p;
        }
        for (i = 0; i < n; i++)
            if (gr[i])
            {
                p = gr[i];
                while (p->key != c && p->next != NULL)
                {
                    q = p;
                    p = p->next;
                }
                if (p->key == c)
                {
                    q->next = p->next;
                    delete p;
                }
            }
    }
    else
        cout << "The mode is not in the graph";
    cout << endl;
}
void del_arc(link* gr[n], char c1, char c2)
{
    int i = 0; link* p = NULL, * q = NULL;
    if (search_arc(gr, c1, c2))
    {
        while (gr[i]->key != c1)
            i++;
        p = gr[i];
        while (p->key != c2)
        {
            q = p; p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    else
        cout << "The arc is not in the graph";
    cout << endl;
}

void find_node_with_most_entry_arcs(link* graph[n])
{
    int arr[n];
    bool hasNodes = false;
    for (int i = 0; i < n; i++)
    {
        if (graph[i]!= NULL)
        {
            hasNodes = true;
            int curr_counter = 0;
            for (int j = 0; j < n; j++)
            {
                if (graph[j] != NULL && i!=j)
                {
                    if (search_arc(graph, graph[j]->key, graph[i]->key) == 1) {
                        curr_counter++;
                    }
                }        
            }
            arr[i] = curr_counter;
        }
       
       
    }
    if (!hasNodes)
    {
        cout << "No nodes in graph" << endl;
        return;
    }

    int max = -1;
    int max_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }

    cout << "The nodes with most entry arcs is: ";
    cout << graph[max_index]->key << endl;
    del_node(graph, graph[max_index]->key);
    cout << "The node has been deleted" << endl;       
}
