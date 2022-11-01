#include <stdio.h>




int capacity[100] = { 0 };

int main()
{
	int option;
	int availability;
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
