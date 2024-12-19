#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

Node *ChenTangDan(Node *head, int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr || head->value >= value)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->value < value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}
Node *Nhap()
{
    Node *head, *tail;
    head = nullptr;
    tail = nullptr;
    int value;

    cout << "Nhap 0 de dung nha!!!\n";

    while (true)
    {
        // cout << "Nhap gia tri di ban: ";
        cin >> value;

        if (value == 0)
            break;

        Node *temp = new Node;
        temp->value = value;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}

Node *NhapSuDungChen()
{
    Node *head = nullptr;
    int value;

    cout << "Nhap 0 de dung nha!!!\n";
    while (true)
    {
        // cout << "Nhap gia tri di ban: ";
        cin >> value;

        if (value == 0)
            break;

        head = ChenTangDan(head, value);
    }

    return head;
}

void Xuat(Node *head)
{
    Node *temp = head;
    cout << "Danh sach lien ket: ";
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void GiaiPhong(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void TachChanLe(Node *head, Node *&chanHead, Node *&leHead)
{
    chanHead = nullptr;
    leHead = nullptr;

    Node *chanTail = nullptr;
    Node *leTail = nullptr;

    while (head != nullptr)
    {
        Node *newNode = new Node;
        newNode->value = head->value;
        newNode->next = nullptr;

        if (head->value % 2 == 0)
        {
            if (chanHead == nullptr)
            {
                chanHead = newNode;
                chanTail = newNode;
            }
            else
            {
                chanTail->next = newNode;
                chanTail = newNode;
            }
        }
        else
        {
            if (leHead == nullptr)
            {
                leHead = newNode;
                leTail = newNode;
            }
            else
            {
                leTail->next = newNode;
                leTail = newNode;
            }
        }

        head = head->next;
    }
}

void TachChanLeChenTangDan(Node *head, Node *&chanHead, Node *&leHead)
{
    // Neu head khong phai mang tang dan
    // head nay duoc tao ra tung Nhap()
    chanHead = nullptr;
    leHead = nullptr;

    while (head != nullptr)
    {
        if (head->value % 2 == 0)
        {
            chanHead = ChenTangDan(chanHead, head->value);
        }
        else
        {
            leHead = ChenTangDan(leHead, head->value);
        }
        head = head->next;
    }
}

int main()
{

    Node *chanHead;
    Node *leHead;
    Node *head;
    chanHead = nullptr;
    leHead = nullptr;
    // Neu dau vao khong tang dan ma muon 2 mang tang dan
    // head = Nhap();
    // TachChanLeChenTangDan(head, chanHead, leHead);
    // Neu dau vao tang dan va dau ra la 2 mang tang dan
    head = NhapSuDungChen();
    // TachChanLeChenTangDan(head, chanHead, leHead); // Cai nay co hoi du thua
    // Cai nay do du thua
    TachChanLe(head, chanHead, leHead);
    cout << "\nDanh sach chan:\n";
    Xuat(chanHead);

    cout << "\nDanh sach le:\n";
    Xuat(leHead);

    GiaiPhong(head);
    GiaiPhong(chanHead);
    GiaiPhong(leHead);

    return 0;
}
