#include <bits/stdc++.h> 
using namespace std;  
#define d 256 

void Search(int num, char pattern[], char str[]) 
{

    int i, j; 
	int var4 = 1; 
	int hash1 = 0; 
	int hash2 = 0;

	int var1 = strlen(pattern); 
	int var2 = strlen(str); 

	for (i = 0; i < var1 - 1; i++) {
		var4 = (var4 * d) % num;
	} 
		 
	for (i = 0; i < var1; i++) 
	{ 
		hash1 = (d * hash1 + pattern[i]) % num; 
		hash2 = (d * hash2 + str[i]) % num; 
	} 

	for (i = 0; i <= var2 - var1; i++) 
	{ 
		
		if ( hash1 == hash2 ) 
		{ 
		
			for (j = 0; j < var1; j++) 
			{ 
				if (str[i+j] != pattern[j]) 
				{
					break;
				}
			} 

			if (j == var1) 
			{
				cout<<"Pattern: "<< i << endl; 
			}
		} 
        
		
		if ( i < (var2-var1) ) 
		{ 
			hash2 = ( d * (hash2 - str[i]*var4) + str[i+var1]) % num; 

			if (hash2 < 0) 
			{
				hash2 = (hash2 + num ); 
			}
		} 
	} 
} 

int main() 
{ 
	char str[] = "Common people in the world are not common"; 
	char pattern[] = "common"; 
	int num = 117; 

	Search(num, pattern, str);  
} 


