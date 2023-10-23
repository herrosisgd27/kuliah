#include <iostream>

template <class T>
class List; // Forward declaration

template <class T>
class Node
{
    template <class U>
    friend class List;
    template <class U>
    friend std::ostream &operator<<(std::ostream &, const List<U> &);

public:
    Node(T t, Node<T> *p) : info(t), berikut(p) {}

protected:
    T info;
    Node<T> *berikut;
};

template <class T>
class List
{  
    template <class U>
    friend std::ostream &operator<<(std::ostream &, const List<U> &);

public:
    List() : kepala(0) {}
    ~List();
    void sisip(T t);
    int hapus(T &t);
    int kosong() { return (kepala == 0); }
    void cetak();

protected:
    Node<T> *kepala;
    Node<T> *nodeBaru(T t, Node<T> *p)
    {
        Node<T> *q = new Node<T>(t, p);
        return q;
    }
};

template <class T>
std::ostream &operator<<(std::ostream &out, const List<T> &k)
{
    for (Node<T> *p = k.kepala; p; p = p->berikut)
        out << p->info << " -> ";
    out << "*\n";
    return out;
}

template <class T>
List<T>::~List()
{
    Node<T> *temp;
    for (Node<T> *p = kepala; p;)
    {
        temp = p;
        p = p->berikut;
        delete temp;
    }
}

template <class T>
void List<T>::sisip(T t)
{
    std::cout << t << " masuk list : ";
    Node<T> *p = nodeBaru(t, kepala);
    kepala = p;
}

template <class T>
int List<T>::hapus(T &t)
{
    if (kosong())
        return 0; // penghapusan gagal
    t = kepala->info;
    Node<T> *p = kepala;
    kepala = kepala->berikut;
    delete p;
    return 1; // penghapusan sukses
}

template <class T>
void List<T>::cetak()
{
    for (Node<T> *p = kepala; p; p = p->berikut)
        std::cout << p->info << " -> ";
    std::cout << "*\n";
}

int main()
{
    List<char> x;
    char data;
    x.sisip('a');
    std::cout << x;
    x.sisip('b');
    std::cout << x;
    x.sisip('c');
    std::cout << x;
    x.sisip('d');
    std::cout << x;
    for (int i = 0; i < 5; i++)
    {
        x.hapus(data);
        std::cout << data << " dihapus dari list : ";
        std::cout << x;
    }
    return 0;
}
