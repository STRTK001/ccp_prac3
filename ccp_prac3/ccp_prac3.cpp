// ccp_prac3.cpp : Defines the entry point for the application.
//

#include "ccp_prac3.h"

#include <set>
#include <stdio.h>
#include <map>
int main()
{

	int len = 0;
	printf("What is the total length of the set you want to make? ");
	scanf("%d", &len); 
	//while the length is invalid, loop until its valid
	while (len < 1)
	{
		printf("the specified length is less than 1!\nWhat is the total length of the set you want to make? ");
		scanf("%d", &len);
	}
	//create the set
	std::set<int> values;
	//create iterator so we can find values later on
	std::set<int>::iterator setIt;
	int input = 0;
	//insert the values
	for (int i = 0; i < len; i++)
	{
		//get the next unique int
		printf("please enter a unique number: ");
		scanf("%d", &input);
		//if the value if the iter != the end of the set then the input is not distinct
		setIt = values.find(input);
		
		while(setIt != values.end())
		{
			printf("%d is already in the set!\nplease enter a unique number: ",input);
			scanf("%d", &input);
			setIt = values.find(input);
		}
		//insert input into set
		values.insert(input);
	}
	//deleting values
	printf("Choose a number to remove from the set: ");
	scanf("%d", &input);
	setIt = values.find(input);
	//while our deleted val is distinct
	while (setIt == values.end())
	{
		printf("%d doesnt exist in the set!\nplease Choose a number to remove from the set: "
			,input);
		scanf("%d", &input);
		setIt = values.find(input);
	}
	values.erase(input);

	//mapping strings with the set values
	std::map<std::string, int> kvp;
	std::map<std::string, int>::iterator mapIt;
	std::string str = "";

	for(setIt = values.begin(); setIt != values.end(); setIt++)
	{
		printf("Assign a key for the value %d: ", *setIt);
		scanf("%128s", &str);
		
		//while our str is not distinct
		while(kvp.find(str) != kvp.end())
		{
			printf("the key, %s , is not distinct!\nplease enter a distinct key: ", str);
			scanf("%128s",&str);
			mapIt = kvp.find(str);
		}
		//map the kvps
		kvp[str] = *setIt;
	}
	
	//display columns 
	printf("    keys    |    values    \n");
	for (mapIt = kvp.begin(); mapIt != kvp.end(); mapIt++)
	{
		printf("%s | %d\n",mapIt->first,mapIt->second);
	}
	return 0;
}
