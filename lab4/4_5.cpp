#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
struct animal {
    int color;
    int count;
};
int bin_search(const animal* arr, int size, int key)
{
    int first = 0;
    int last = size;
    while (last >= first)
    {
        int mid = first + ((last - first) / 2);
            if (arr[mid].color == key) return mid;
                if (arr[mid].color <= key) first = mid + 1;
        else last = mid - 1;
    }
    return -1;
}
int main(){
     animal *animals;
     int count, qcount, total, query, last, i;
     cin >> count;
     animals = new animal[count];
     last = -1;
     i = -1;
     total = 0;
     while(total < count)
    {
        int p;
        cin >> p;
            if (p != last) i++,animals[i].color = p,animals[i].count = 1,last = p;
            else animals[i].count += 1;
        total++;
    }
    int a_size = i + 1;
    cin >> qcount;
    while (qcount --> 0)
    {
        int color, idx;
        cin >> color;
        idx = bin_search(animals, a_size, color);
            if (idx != -1) cout << animals[idx].count << endl;
            else cout << 0 << endl;
    }
    return 0;
}
