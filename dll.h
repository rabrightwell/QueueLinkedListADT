#ifndef __DLL_H__
#define __DLL_H__

#include "exceptions.h"

class DllNode {
public:
    int value;
    DllNode* prev;
    DllNode* next;

    DllNode(int v, DllNode* p, DllNode* n) {
        value = v;
        prev = p;
        next = n;
    }
};

class Dll {
private:
    DllNode *head;
    DllNode *tail;
    int sizeNum = 0;

public:
    Dll() // create an empty list
    {
        head = nullptr;
        tail = nullptr;

    }

    Dll(const Dll& src) // create a deep copy of the src list
    {
        DllNode* tmp = src.head;

        int i = 0;
        while (tmp != nullptr)
        {
            insert(i++, tmp->value);
            tmp = tmp->next;

        }
    }
    Dll(const int arr[], int size) // create a linked list containing the elements of the array
    {
        for (int i = size-1; i >= 0; i--) {
            insert(0, arr[i]);
        }
    }
    Dll &operator=(const Dll &src) // create a deep copy of the src list
    {
        clear();
        DllNode* tmp = src.head;

        int i = 0;
        while (tmp != nullptr)
        {
            insert(i++, tmp->value);
            tmp = tmp->next;

        }
    }
    ~Dll() // free all memory
    {
        clear();
    }

    DllNode* getHead() const { return head; }

    bool empty() const // return if the list is empty in O(1)
    {
        if (sizeNum == 0) return true;
        else return false;
    }
    int size() const // return how many items are in the list in O(1)
    {
        return sizeNum;
    }

    int &at(int rank) // return a reference to the value of the list at a rank/index
    {
            if ((rank < 0) || (rank >= sizeNum)) {
                throw IndexOutOfRangeException("at(): Index was outside the bounds of the linked list.", rank);
            }
            else {
                DllNode* q = head;

                for (int r = 0; r < rank; r++) {
                    q = q->next;
                }

                return q->value;
            }
       
    }

    DllNode* atNode(int rank) //return reference to the DllNode of the list at a rank/index
    {
        DllNode* q = head;

        for (int r = 0; r < rank; r++) {
            q = q->next;
        }

        return q;
    }
    void insert(int rank, int value) // insert a value at the rank/index
    {
            if ((rank < 0) || (rank > sizeNum)) {
                throw IndexOutOfRangeException("insert() : Index was outside the bounds of the linked list.", rank);
            }
            else {
                //Insert Front
                if (rank == 0) {
                    DllNode* q = new DllNode(value, nullptr, head);
                    head = q;
                    if (sizeNum == 0)
                        tail = q;
                    else
                        q->next->prev = q;
                    sizeNum++;
                }

                //Insert Back
                else if (rank == sizeNum) {
                    DllNode* q = new DllNode(value, tail, nullptr);
                    q->prev->next = q;
                    tail = q;
                    sizeNum++;
                }

                //Insert Rank
                else if (rank < sizeNum) {
                    DllNode* p = atNode(rank - 1);
                    DllNode* n = p->next;

                    DllNode* q = new DllNode(value, p, n);
                    q->prev->next = q;
                    q->next->prev = q;
                    sizeNum++;
                }
            }
    }

    int remove(int rank) // remove the node at the rank/index and return its value
    {
        int v = 0;
            if ((rank < 0) || (rank >= sizeNum)) {
                throw IndexOutOfRangeException("remove(): Index was outside the bounds of the linked list.", rank);
            }
            else {
                //Case Only Node
                if ((sizeNum == 1) && (rank == 0))
                {
                    v = head->value;
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                    sizeNum--;
                }

                //Case First Node
                else if (rank == 0) {
                    v = head->value;
                    head = head->next;
                    delete head->prev;
                    head->prev = nullptr;
                    sizeNum--;
                }

                //Case Last Node
                else if (rank == sizeNum - 1) {
                    v = tail->value;
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = nullptr;
                    sizeNum--;
                }

                //Case Middle Node
                else {
                    DllNode* q = atNode(rank);
                    v = q->value;
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                    delete q;
                    sizeNum--;
                }

                return v;
            }
        

        
    }

    void clear() // reset the list to an empty list
    {
        while (sizeNum > 0)
        {
            remove(sizeNum - 1);
        }
    }
    void display(ostream& os) const // write the contents of the list to the ostream
    {
        DllNode *q = head;
        os << "[ ";
        while (q != nullptr) {
            os << q->value << " ";
            q = q->next;
        }
        os << "]";

    }
};

ostream& operator<<(ostream& os, const Dll& list) // write the contents of the list to the ostream
{
    DllNode* q = list.getHead();
    os << "[ ";
    while (q != nullptr) {
        os << q->value << " ";
        q = q->next;
    }
    os << "]";

    return os;

}
#endif