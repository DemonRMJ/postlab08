#include <stdio.h>

int capacity[100] = { 0 };
void reserve_boarding(int section)
{
	int seat = 0;
	if (section == 1)
	{
		for (int i = 0; i < 30; i++)
		{
			if (capacity[i] == 0)
			{
				capacity[i] = 1;
				seat = i + 1;
			}
			if (seat != 0)
				break;
		}
		if (seat != 0)
		{
			printf("**** 1. Boarding Pass ****\nYour section:%d\t\nYour seat:%d\t\n", section, seat);
		}
	}
	else
	{
		for (int j = 30; j < 100; j++)
		{
			if (capacity[j] == 0)
			{
				capacity[j] = 1;
				seat = j + 1;
			}
			if (seat != 0)
				break;
		}
		if (seat != 0)
		{
			printf("**** 2.Boarding Pass ****\nYour section:%d\t\nYour seat:%d\t\n", section, seat);
		}
	}

}


// display message about next flight
void next_flight(void)
{
	printf("/next flight eaves in 3 hours.\n");
}
int option_select()
{
	int class_option;

	printf("Please type 1 for \"First Class\"\nPlease type 2 for\"Economy\" \n");

	scanf("%d", &class_option);

	while (class_option != 1 && class_option != 2)
	{
		printf("Please enter correct option!\n");
		printf("Please type 1 for \"First Class\"\nPlease type 2 for \"Economy\"\n");

		scanf("%d", &class_option);


	}
	return class_option;
}




// seats availability 
int availability_cheacking(int opt)
{
	int counter_a = 0;
	int counter_b = 0;
	if (opt == 1)
	{
		for (int i = 0; i < 30; i++)
		{
			if (capacity[i] == 0)
				counter_a++;

		}
	}
	else
	{
		for (int j = 30; j < 100; j++)
		{
			if (capacity[j] == 0)
				counter_b++;
		}
	}
	if ((opt == 1 && counter_a > 0) || (opt == 2 && counter_b > 0))
	{
		printf("There is avaible place in section:\n");
		return 1;
	}
	else
	{
		printf("There is no available place in section:\n");
		return 0;
	}
}


int main()
{
	int option;
	int availability=0;
	int availability_other;

	for (int x = 0; x < 101; x++)
	{
		//option select
		option = option_select();

		// check seats availability in selected section
		availability = availability_checking(option);

		if (availability == 1)
		{
			// if there is available place print boarding pass
			reserve_boarding(option);
		}
		else
			// if there is no available place, check seats availability in other
		{
			if (option == 1)
				availability_other = availability_checking(2);
			else
				availability_other = availability_checking(1);
		}

		// ask client is it accetable to place in the section
		if (availability == 0 && availability_other == 1)
		{
			printf("There is available place in other section \n Do you want to buy it?([Y]es, [N]o)\n");

			char other_section;

			scanf("%c", &other_section);

			while (other_section != 'y' && other_section != 'n')
			{
				printf("Please enter correct answer option:\n");
				scanf("%c", &other_section);
			}
			if (other_section == 'n')
				next_flight();
			else
				if (option == 1)
					reserve_boarding(2);
				else
					reserve_boarding(1);



		}
		// if there is no available place in other section display message
		else if (availability == 0 && availability_other == 0)
			next_flight();



	}
}
