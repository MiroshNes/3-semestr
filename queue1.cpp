// ConsoleApplication7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

//������� 9

#include "stdafx.h"
#include <iostream>
#include <new>
#include <queue>
using namespace std;

// ������������ ��������� ������ "�������"
template <typename T>
class Queue
{
private:
  T* p; // ������������ ������
  int count; // ���������� ��������� � �������

public:
  // ����������� �� ���������
  Queue()
  {
    count = 0; // ������� ������
  }

  // ����������� �����������
  Queue(const Queue& obj)
  {
    // ����������� obj � ������� ������
    count = obj.count;

    try {
      // ������� �������� ������ ��� p
      p = new T[count];
      // ��������� ����������
      for (int i = 0; i < count; i++)
        p[i] = obj.p[i];
    }
    catch (bad_alloc e)
    {
      // ���� ������ �� ��������, �� ������� ����� ������
      cout << e.what() << endl;
      count = 0; // ������� ������ �������
    }
  }

  // �������� ������� � �������
  void push(T item)
  {
    T* p2; // �������� �������������� ���������
    p2 = p; // ������������� �������������� ��������� �� p

    try {
      // ������� �������� ����� �������� ������ ��� p, �� �� 1 ������
      p = new T[count + 1];

      // ����������� ������ �� ������� �� ������� ��������� p2 (������ ������)
      // � �������, �� ������� ��������� p
      for (int i = 0; i < count; i++)
        p[i] = p2[i];

      // ����������� ��������� �������
      p[count] = item;

      // ��������� ���������� ��������� �� 1
      count++;

      // ���������� �������������� ���������� ������
      if (count > 1)
        delete[] p2;
    }
    catch (bad_alloc e)
    {
      // ���� ������ �� ��������
      cout << e.what() << endl; // ������� ��������� �� ������

      // ������� ������ ��������� �� p
      p = p2;
    }
  }

  // �������� ������ ������� �� �������
  T pop()
  {
    if (count == 0)
      return 0;

    // ��������� �������, ������� ������������ �� �������
    T item;

    item = p[0];

    // ������������ ����� ������� ������, ������� �� 1 ������
    try {
      T* p2;

      // ������� �������� ���'���
      p2 = new T[count - 1];

      count--; // ��������� ���������� ��������� � �������

      // p=>p2
      for (int i = 0; i < count; i++)
        p2[i] = p[i + 1]; // ���������� ��� ����� ������� ��������

      // ���������� �������, �� ������� ��������� p
      if (count > 0)
        delete[] p;

      // ������������� p �� p2
      p = p2;

      // ������� item
      return item;
    }
    catch (bad_alloc e)
    {
      // ���� ������ �� ����������, �� ������� 0
      cout << e.what() << endl;
      return 0;
    }
  }

  // ����������� ������� operator=(),
  // ��������� ������������ �������� ���� Queue
  Queue& operator=(const Queue& obj)
  {
    T* p2; // ��������� �� �������������� ������

    try {
      // ������� �������� ����� ������� ������ ��� p2
      p2 = new T[obj.count];

      // ���� ������ �������� �������,
      // ����� ����������� �������������� ���������� ������ ��� p
      if (count > 0)
        delete[] p;

      // ����������� obj � ������� ������
      p = p2; // ������������� p �� p2
      count = obj.count;

      // ��������� ����������
      for (int i = 0; i < count; i++)
        p[i] = obj.p[i];
    }
    catch (bad_alloc e)
    {
      // ���� ������ �� ����������, �� ������� ��������������� ���������
      cout << e.what() << endl;
    }
    return *this; // ������� ������� ������
  }

  // ����������
  ~Queue()
  {
    if (count > 0)
      delete[] p;
  }

  // ����� ������ ������� �� ������� �� ��������� ���
  T GetItem()
  {
    if (count > 0)
      return p[0];
    else
      return 0;
  }

  // ������� �������
  void clear()
  {
    if (count > 0)
    {
      delete[] p;
      count = 0;
    }
  }

  // �������� ������������� ��������� � �������
  bool IsEmpty()
  {
    return count == 0;
  }

  // ���������� ��������� � �������
  int GetN()
  {
    return count;
  }

  // �����, ��������� �������
  void print(const char* objName)
  {
    cout << "Object: " << objName << endl;
    for (int i = 0; i < count; i++)
      cout << p[i] << "\t";
    cout << endl;
    
  }
};

int _tmain(int argc, _TCHAR* argv[])
{
  Queue<int> Q1;
  Q1.print("Q1");

  Q1.push(5);
  Q1.print("Q1");

  Q1.push(8);
  Q1.push(11);
  Q1.push(17); // Q1 = {5,8,11,17}
  Q1.print("Q1");

  int d;
  d = Q1.GetItem();
  cout << "d = " << d << endl;

  Q1.print("Q1");

  Queue<int> Q2 = Q1;
  Q2.print("Q2");

  Queue<int> Q3;
  Q3 = Q1 = Q2;
  Q1.push(333);
  Q2.push(555);

  Q1.print("Q1");
  Q2.print("Q2");
  Q3.print("Q3");

  Q2.clear();
  if (Q2.IsEmpty())
    cout << "OK" << endl;
  else
    cout << "NO" << endl;

  cout << "n = " << Q3.GetN() << endl;
  setlocale (LC_ALL, "rus");
 //����
  //1-�������� �������, 2-�������, 3-������� ������ �������, 4-������� �������,5-�������� �������, 0-����� �� ���������
  while(true)
  {
      cout << "1-�������� �������" << endl;
      cout << "2-�������" << endl;
      cout << "3-������� ������ �������" << endl;
      cout << "4-������� �������" << endl;
      cout << "5-�������� �������" << endl;
      cout << "0-����� �� ���������" << endl;
      int a, b;
      cin >> a;
      switch (a)
      {
          case 0: 
				return 0;
				break;
          case 1: 
                cout << "������� �����: " ;
                cin >> b;
                //cout << b;
				return 0;
                break;
          case 2:
                Q1.pop();
          case 3: 
                cout << "n = " << Q3.GetN() << endl;
                return 0;
                break;
          case 4: 
                Q1.print("Q1");
                Q2.print("Q2");
                Q3.print("Q3");
				return 0;
                break;
          case 5: 
                 Q2.clear();
                 return 0;
                 break;
		 cin >> b;

        default:
            cout << "�������� �����" << endl;
      }

  }
  
 
  return 0;
}

