#include <map>
#include <string>
#include <iostream>
using namespace std;

int Bitmap_search(string pattern, string text)
{
   
   long A = ~1;
   long p_mask[300];
   int var1 = pattern.length();
   
   if (var1 == 0)
   {
      return -1;
   }
   if (var1 >= 64) 
   {
      cout<<"Pattern is too long!";
      return -1;
   }

   for (int i = 0; i <= 299; ++i)
   {
      p_mask[i] = ~0;
   }

   for (int i = 0; i < var1; ++i)
   {
      p_mask[pattern[i]] &= ~(1L << i);
   }
     
   for (int i = 0; i < text.length(); ++i) 
   {
      A |= p_mask[text[i]];
      A <<= 1;
      if ((A & (1L << var1)) == 0)
      {
         return i - var1 + 1;
      }
   }
   return -1;
}

void FindPattern(string pattern, string text) {

   int position = Bitmap_search( pattern, text);     

   if (position == -1)
   {
      cout << "No match found!" << endl;
   }
   else
   {
      cout << "Pattern found at position: " << position << endl;
   }
}

int main(int argc, char **argv)
{
   string text;
   cout << "Please enter Text: ";
   cin >>text;

   string pattern;
   cout << "Please enter Pattern: ";
   cin >>pattern;

   FindPattern( pattern, text);
   return 0;
}
