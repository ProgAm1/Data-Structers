#include <iostream>
using namespace std;
int main()
{

   int size = 5;
   int elemnt = 0;
   int index = 0;
   int arr[size] = {10, 20, 30, 40, 50};

   cout << "Array before editing : ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }

   cout << endl;

   cout << "\nenter the elemnt to insert : ";
   cin >> elemnt;

   cout << "index : ";
   cin >> index;

   if (index > size)
   {
      cout << "the index you have entered is out of range." << endl;
   }
   else
   {
      for (int i = size; i < index; i--)
      {
         arr[i] = arr[i - 1];
      }
      arr[index] = elemnt;
      size++;
   }
   cout << endl;

   cout << "Array after editing : ";
   for (int i = 0; i < size - 1; i++)
   {
      cout << arr[i] << " ";
   }
}
