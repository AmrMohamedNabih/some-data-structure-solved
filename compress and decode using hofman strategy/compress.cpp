#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class charl {
public:
    char l;
    charl* next;
};
class TreeNode {
public:
    char value;
    int sum;
    string binary;
    TreeNode* right;
    TreeNode* left;
};
class CNode {
public:
    int sum;
    char value;
    CNode* next;
    TreeNode* down;
};
class node {
public:
    char Latter;
    string binary;
    node* next;
};
class CSList {
public:
    CNode* pHead;
    CSList()
    {
        pHead = NULL;
    }
    void Insert(CNode* pnn)
    {
        if (pHead == NULL)
        {
            pHead = pnn;
        }
        else
        {
            CNode* pb = NULL;
            CNode* pTrav = pHead;
            while (pTrav != NULL && pTrav->sum < pnn->sum)
            {
                pb = pTrav;
                pTrav = pTrav->next;
            }
            if (pb != NULL)
            {
                pb->next = pnn;
                pnn->next = pTrav;
            }
            else
            {
                pnn->next = pTrav;
                pHead = pnn;
            }
        }
    }

    ~CSList()
    {
        CNode* pTrav = pHead;
        while (pHead != NULL)
        {
            pHead = pTrav->next;
            pTrav->next = NULL;

            delete pTrav;
            pTrav = pHead;
        }

    }
};
class List
{
public:
    node* pHead;
    node* pTail;
    List()
    {
        pHead = NULL;
        pTail = NULL;
    }
    void attach(node* pnn)
    {
        if (pHead == NULL)
        {
            pHead = pnn;
            pTail = pnn;
        }
        else
        {
            pTail->next = pnn;
            pTail = pnn;
        }
    }
    ~List()
    {
        node* pTrav = pHead;
        while (pHead != NULL)
        {
            pHead = pTrav->next;
            pTrav->next = NULL;
            delete pTrav;
            pTrav = pHead;
        }
    }
};
class Listchar
{
public:
    charl* pHead;
    charl* pTail;
    Listchar()
    {
        pHead = NULL;
        pTail = NULL;
    }
    void attach(charl* pnn)
    {
        if (pHead == NULL)
        {
            pHead = pnn;
            pTail = pnn;
        }
        else
        {
            pTail->next = pnn;
            pTail = pnn;
        }
    }
    ~Listchar()
    {
        charl* pTrav = pHead;
        while (pHead != NULL)
        {
            pHead = pTrav->next;
            pTrav->next = NULL;
            delete pTrav;
            pTrav = pHead;
        }
    }
};

void dispInOrder(TreeNode* r, string Binary, char l, List& myList)
{
    if (l != '8')
        Binary += l;
    node* pnn;
    if (r->right == NULL && r->left == NULL)
    {
        pnn = new node;
        pnn->Latter = r->value;
        pnn->binary = Binary;
        pnn->next = NULL;
        myList.attach(pnn);
        r->binary = Binary;
        return;
    }
    dispInOrder(r->left, Binary, '0', myList);
    dispInOrder(r->right, Binary, '1', myList);
}
void MakeCode(char* ch, List& myList, int h)
{
    //     char characters[] ={
    //     0, 1, 2, 3, 4, 5, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    //     16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    //     ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
    //     '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?',
    //     '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    //     'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_',
    //     '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    //     'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', 127,
    //     128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
    //     144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
    //     160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
    //     176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
    //     192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
    //     208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
    //     224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    //     240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
    // };
    char charArray[256];
    for (int i = 0; i < 256; ++i) {
        charArray[i] = static_cast<char>(i);
    }
    CSList list;
    CNode* pnn;
    TreeNode* root, * Right, * Left;
    string Binary;
    char l;
    int ct = 0;
    char v = 0;
    for (char c : charArray)
    {
        ct = 0;
        for (int i = 0; i < h; i++)
        {
            if (ch[i] == c)
            {
                ct++;
            }
        }
        if (ct != 0)
        {
            pnn = new CNode;
            pnn->value = c;
            pnn->sum = ct;
            pnn->next = NULL;
            pnn->down = NULL;
            list.Insert(pnn);
        }
    }
    CNode* pTrav = list.pHead;
    while (pTrav->next != NULL)
    {
        pnn = new CNode;
        pnn->value = '\0';
        pnn->sum = pTrav->sum + pTrav->next->sum;
        pnn->next = NULL;
        if (pTrav->down == NULL && pTrav->next->down == NULL)
        {
            Left = new TreeNode;
            Left->left = NULL;
            Left->right = NULL;
            Left->sum = pTrav->sum;
            Left->value = pTrav->value;

            Right = new TreeNode;
            Right->left = NULL;
            Right->right = NULL;
            Right->sum = pTrav->next->sum;
            Right->value = pTrav->next->value;

            root = new TreeNode;
            root->left = Left;
            root->right = Right;
            root->sum = Left->sum + Right->sum;
            root->value = '\0';
        }
        else if (pTrav->down == NULL && pTrav->next->down != NULL) {
            Left = new TreeNode;
            Left->left = NULL;
            Left->right = NULL;
            Left->sum = pTrav->sum;
            Left->value = pTrav->value;

            root = new TreeNode;
            root->left = Left;
            root->right = pTrav->next->down;
            root->sum = Left->sum + pTrav->next->sum;
            root->value = '\0';
        }
        else if (pTrav->down != NULL && pTrav->next->down == NULL) {
            Right = new TreeNode;
            Right->left = NULL;
            Right->right = NULL;
            Right->sum = pTrav->next->sum;
            Right->value = pTrav->next->value;

            root = new TreeNode;
            root->left = pTrav->down;
            root->right = Right;
            root->sum = pTrav->sum + Right->sum;
            root->value = '\0';
        }
        else {
            root = new TreeNode;
            root->left = pTrav->down;
            root->right = pTrav->next->down;
            root->sum = pTrav->sum + pTrav->next->sum;
            root->value += '\0';
        }
        pnn->down = root;
        list.Insert(pnn);
        list.pHead = list.pHead->next->next;
        pTrav = list.pHead;
    }
    dispInOrder(list.pHead->down, Binary, '8', myList);
}
void main()
{
    ifstream f1("C:/Users/amr nabih/Desktop/New folder (3)/photo.png", ifstream::binary);
    ofstream f2("C:/Users/amr nabih/Desktop/New folder (3)/photo1.png", ofstream::binary);
    f1.seekg(0, f1.end);
    int h = f1.tellg();
    f1.seekg(0, f1.beg);
    char ch;
    char* arrOfString = new char[h];
    for (int i = 0; i < h; i++)
    {
        f1.read(&ch, 1);
        arrOfString[i] = ch;
    }
    f1.seekg(0, f1.beg);
    List myList;
    MakeCode(arrOfString, myList, h);
    node* Trav;
    char compar;
    char temp = 0;
    char mask = 1;
    Trav = myList.pHead;
    for (int i = 0, iBit = 7;i < h;i++)
    {
        Trav = myList.pHead;
        f1.read(&ch, 1);
        while (Trav != NULL)
        {
            if (ch == Trav->Latter)
            {
                for (int iCode = 0;iCode < Trav->binary.length();iCode++)
                {
                    mask = 1;
                    if (iBit >= 0)
                    {
                        if (Trav->binary[iCode] == '1')
                        {
                            //cout << '1';
                            temp = temp | (mask << iBit);
                        }
                        else {
                            //cout << '0';
                        }
                        iBit--;
                    }
                    else {
                        f2.write(&temp, 1);
                        // //cout<<"am:"<<temp;
                        temp = 0;
                        iBit = 7;
                        //cout << '\t';
                        if (Trav->binary[iCode] == '1')
                        {
                            //cout << '1';
                            temp = temp | (mask << iBit);
                        }
                        else {
                            //cout << '0';
                        }
                        iBit--;
                    }
                }
                break;
            }
            Trav = Trav->next;
        }
    }
    cout << "done";
    f2.close();
}