#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
   int p;
   float w;
   float d;
} Item;
void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<
   endl;
   for(int i = 0; i < sizeOfItems; i++) {
      cout << "Enter weight of item number:"<< i+1 << " :- ";
      cin >> items[i].w;
      cout << "Enter proift of item number "<< i+1 << " :-";
      cin >> items[i].p;
   }
}
void display(Item items[], int sizeOfItems) {
   int i;
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << "\nProfit: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].p << "\t";
   }
   cout << "\nDensity: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout <<items[i].p/ items[i].w << "\t";
   }
   cout << endl;
}
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++) {
      items[i].d = items[i].p / items[i].w;
   }
   sort(items, items+sizeOfItems, compare);
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalValue += items[i].p ;
         totalWeight += items[i].w;
      } else {
         int wt = W-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}
int main() {
   int W,N;
   Item items[N];
   cout<<"Enter the Value of n:";
   cin>>N;
   input(items, N);
   cout << "Entered data \n";
   display(items,N);
   cout<< "Enter Knapsack weight:";
   cin >> W;
   float mxVal = knapsack(items, N, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}
