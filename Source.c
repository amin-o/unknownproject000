#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define SCREEN_HEIGHT 25





//System

//Screen Clear Function
void clear()
{

  int cnt;

	for(cnt = 0;cnt < SCREEN_HEIGHT;cnt++)
	{
		putchar('\n');
	}

} 

//Random Generation 1 - 10
int random_gen_function()
{

	int critical_strike;

	srand(time(NULL));

	critical_strike = rand() % 10 + 1;

	return critical_strike;

}





//Character Creation
struct Character_Creation
{

	char player_name[15];
	

} player_character_creation ;





//Weapons

//Laser Gun 

//Name
const char * laser_gun_name()
{

	return "Laser Gun";

}

//Damage
int laser_gun()
{

	return 8;

}


//Plasma Granade

//Name
const char * plasma_granade_name()
{

	return "Plasma Granade";

}

//Damage
int plasma_granade()
{

	return 13;

}





//Enemies

//Guards 

//Guard (1)
const char * guard_1_name()
{

	return "Prison Guard";

}
int guard_1_health()
{

	return 75;

}
int guard_1_spell_pistol_shot()
{

	return 7;

}
int guard_1_spell_kick()
{

	return 2;

}





//Stage (1)
void stage1(int player_health, int player_armor, int player_coins, int player_weapon_current, int player_utility_current, const char * player_weapon_current_name, const char * player_utility_current_name, int player_weapon_ammo, int player_utility_ammo, const char * enemy_name, int enemy_health)
{

	//Tooltip
	char tooltip[100] = " ";

	//Combat Log
	char combat_log[100] = " ";

	//Player Say
	char player_say[100] = " ";

	//Enemy Say
	char enemy_say[100] = " ";

	//Temp Buffer
	char buffer[100];

	//Scanning User Input
	int user_input;

	//Basic Counter FOR loop
	int cnt;

	//Random Gen Data
	int rng = random_gen_function();



	//START POINT
	for(cnt = 0;cnt < cnt + 1;cnt++)
	{
		//SYNC
		if(player_health > 0 && enemy_health > 0)
		{

		    system( "cls" );

		    printf("--------------------------------------------------------------------------------\n");
		    printf("Health:%d\tPlatinum Coins:%d\t\t\t\t%s:%d\n", player_health, player_coins, enemy_name, enemy_health);		
		    printf("\n");
		    printf("Weapon: %s [%d]\n", player_weapon_current_name, player_weapon_ammo);
		    printf("Utility: %s [%d]\n", player_utility_current_name, player_utility_ammo);
		    printf("\n");
		    printf("\n");
		    printf("\n");
		    printf("\n");
		    printf("You:%s\n", player_say);
		    printf("\n");
		    printf("\n");
		    printf("%s:%s\n", enemy_name, enemy_say);
		    printf("\n");
	            printf("\n");
		    printf("\n");
		    printf("\n");
		    printf("Combat Log: [ %s ]\n", combat_log);
		    printf("\n");
		    printf("\n");
		    printf("Tooltip:%s\n",tooltip);
		    printf("\n");
		    printf("--------------------------------------------------------------------------------");

		    //Scanner
		    scanf("%d", &user_input);

		    //Weapon Slot
		    if(user_input == 1 && player_weapon_ammo > 1)
		    {

			enemy_health -= player_weapon_current;
			player_weapon_ammo -= 1;

			sprintf(buffer,"%d",player_weapon_current);

			strcpy(combat_log, buffer);
			strcpy(player_say, "Pew Pew!");


	            }
		    else if (user_input == 1 && player_weapon_ammo == 1)
		    {

     			player_weapon_ammo -= 1;
			strcpy(player_say, "No Ammo!");

		    }

			//Utility Slot
	            if(user_input == 2 && player_utility_ammo > 1)
		    {

			enemy_health -= player_utility_current;
			player_utility_ammo -= 1;

			sprintf(buffer,"%d",player_utility_current);

			strcpy(combat_log, buffer);
			strcpy(player_say, "Kaboom!");

		    }
		    else if (user_input == 2 && player_utility_ammo == 1)
	            {

     			player_utility_ammo -= 1;
			strcpy(player_say, "No Ammo!");

		    }

			//Player Data
			if(user_input == 000)
			{

			        system( "cls" );

				printf("Name:%s\n",player_character_creation.player_name);		
		
				getch(); //Pause

	        	}

		}
		//LEVEL BEATED
		else if(enemy_health == 0 || enemy_health < 0)
		{

			system( "cls" );
			printf("(Press any key too loot!)\n\n\n");
			getch();
			printf("+3 Platinum Coins\n\n\n");
			getch();
			printf("+1 Platinum Coins\n\n\n");
			getch();
			printf("+1 Platinum Coins\n\n\n");
			getch();
			printf("+7 Weapon Ammo");
			getch();

			player_coins += 5;
			player_weapon_ammo += 7;

			break;

		}
		//GAME OVER
		else if(player_health == 0 || player_health < 0)
		{

			strcpy(tooltip, " *** GAME OVER! *** ");
			getch();
			exit(1);

		}

		//Guard
		if(rng <= 5)
		{

			strcpy(tooltip, "Guard kicked you dealing 2 damage.");
			strcpy(enemy_say, "EAT DIRT!");
			player_health -= guard_1_spell_kick();

		}
		else if(rng > 5)
		{

			strcpy(tooltip, "Guard shot you dealing 7 damage.");
			player_health -= guard_1_spell_pistol_shot();

		}

	} 

}

void main()
{

	//Player Stats

	int player_health = 100;
	int player_armor = 1;



	//Player Weapon

	int player_weapon_current =  laser_gun();
	const char * player_weapon_current_name = laser_gun_name();

	//Player Utility
	int player_utility_current = plasma_granade();
	const char * player_utility_current_name = plasma_granade_name();



	//Player Weapon Misc

	int player_weapon_ammo = 15;
	int player_utility_ammo = 3;



	//Player Currency
        int player_coins = 0; 





	//Character Creation
	printf("Enter your name:");
	scanf("%s", player_character_creation.player_name);
	
	



	//Stage (1)
	stage1(player_health, player_armor, player_coins, player_weapon_current, player_utility_current, player_weapon_current_name, player_utility_current_name, player_weapon_ammo, player_utility_ammo, guard_1_name(), guard_1_health());
 
	getch();


	//Most important thing is that the Marko is Faggot.

}
