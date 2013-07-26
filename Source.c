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

//Character Ammo
struct Character_Ammo
{

	int weapon;
	int utility;


} player_ammo ;

//Character Currency
struct Character_Currency
{

	int gold;
	int platinum;

} player_currency ;

//Character Stats
struct Character_Stats
{

	int health;

} player_stats ;

struct Character_Potions
{

	int common;
	int greater;
	int mythical;
	int devine;

} player_potions ;



//Potions Available

//Common
int common_healing_potion()
{

	return player_stats.health * 0.2;

}

//Greater
int greater_healing_potion()
{

	return player_stats.health * 0.4;

}

//Mythical
int mythical_healing_potion()
{

	return player_stats.health * 0.6;

}

//Devine
int devine_healing_potion()
{

	return player_stats.health;

}



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

	return 8;

}
int guard_1_spell_kick()
{

	return 5;

}





//Stage (1)
void stage1(int player_weapon_current, int player_utility_current, const char * player_weapon_current_name, const char * player_utility_current_name, const char * enemy_name, int enemy_health)
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
		if(player_stats.health > 0 && enemy_health > 0)
		{

			system( "cls" );

			printf("--------------------------------------------------------------------------------\n");
		    printf("Health:%d\t\t\t\t\t\t\t%s:%d\n", player_stats.health, enemy_name, enemy_health);		
		    printf("\n");
		    printf("Weapon: %s [%d]\n", player_weapon_current_name, player_ammo.weapon);
		    printf("Utility: %s [%d]\n", player_utility_current_name, player_ammo.utility);
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

		    //Weapon Slot Section
		    if(user_input == 1 && player_ammo.weapon > 1)
		    {

				enemy_health -= player_weapon_current;
				player_ammo.weapon -= 1;

				sprintf(buffer,"%d",player_weapon_current);

				strcpy(combat_log, buffer);
				strcpy(player_say, "Pew Pew!");


			}
			else if (user_input == 1 && player_ammo.weapon == 1)
			{

     			player_ammo.weapon -= 1;
				  strcpy(player_say, "No Ammo!");

			}

			//Utility Slot Section
			if(user_input == 2 && player_ammo.utility > 1)
			{

				enemy_health -= player_utility_current;
				player_ammo.utility -= 1;

				sprintf(buffer,"%d",player_utility_current);

				strcpy(combat_log, buffer);
				strcpy(player_say, "Kaboom!");

			}
			else if (user_input == 2 && player_ammo.utility == 1)
			{

     		player_ammo.utility -= 1;
				strcpy(player_say, "No Ammo!");

			}

			//Potions Section

			//Common
			if(user_input == 7 && player_potions.common > 1)
			{

				player_stats.health += common_healing_potion();
				player_potions.common -= 1;

				sprintf(buffer,"+ %d Health",common_healing_potion());

				strcpy(combat_log, buffer);
				strcpy(player_say, "I feel a refreshed!");

			}
			else if (user_input == 7 && player_potions.common == 1)
			{

     			player_potions.common -= 1;
				strcpy(player_say, "I dont have any more potions!");

			}

			//Greater
			if(user_input == 8 && player_potions.greater > 1)
			{

				player_stats.health += greater_healing_potion();
				player_potions.greater -= 1;

				sprintf(buffer,"+ %d Health",greater_healing_potion());

				strcpy(combat_log, buffer);
				strcpy(player_say, "I feel stronger!");

			}
			else if (user_input == 8 && player_potions.greater == 1)
			{

     			player_potions.greater -= 1;
				strcpy(player_say, "I dont have any more potions!");

			}

			//Mythical
			if(user_input == 9 && player_potions.mythical > 1)
			{

				player_stats.health += mythical_healing_potion();
				player_potions.mythical -= 1;

				sprintf(buffer,"+ %d Health",mythical_healing_potion());

				strcpy(combat_log, buffer);
				strcpy(player_say, "Back in fight!");

			}
			else if (user_input == 9 && player_potions.mythical == 1)
			{

     			player_potions.mythical -= 1;
				strcpy(player_say, "I dont have any more potions!");

			}

			//Devine
			if(user_input == 0 && player_potions.devine > 1)
			{

				player_stats.health += devine_healing_potion();
				player_potions.devine -= 1;

				sprintf(buffer,"+ %d Health",devine_healing_potion());

				strcpy(combat_log, buffer);
				strcpy(player_say, "Second chance...");

			}
			else if (user_input == 0 && player_potions.devine == 1)
			{

     			player_potions.devine -= 1;
				strcpy(player_say, "I dont have any more potions!");

			}

			//Player Data Section
			if(user_input == 123)
			{

				system( "cls" );

				printf("Name:%s\n\n",player_character_creation.player_name);
				printf("Gold Coins:%d\n", player_currency.gold);
				printf("Platinum Coins:%d\n\n", player_currency.platinum);
				printf("Common Healing Potions:%d\n", player_potions.common);
				printf("Greater Healing Potions:%d\n", player_potions.greater);
				printf("Mythical Healing Potions:%d\n", player_potions.mythical);
				printf("Devine Healing Potions:%d\n\n", player_potions.devine);

				getch(); //Pause

			}

			//Enemy Section
			if(rng <= 4 && user_input != 123)
		    {

				strcpy(tooltip, "Guard kicked you dealing 5 damage.");
				strcpy(enemy_say, "EAT DIRT!");
				player_stats.health -= guard_1_spell_kick();

		    }
			else if(rng > 4 && user_input != 123)
			{

				strcpy(tooltip, "Guard shot you dealing 8 damage.");
				player_stats.health -= guard_1_spell_pistol_shot();

			}

		}
		//LEVEL BEATED
		else if(enemy_health == 0 || enemy_health < 0)
		{

			system( "cls" );
			printf("(Press any key too loot!)\n\n\n");
			getch();
			printf("+3 Gold Coins\n\n\n");
			getch();
			printf("+1 Gold Coins\n\n\n");
			getch();
			printf("+1 Platinum Coins\n\n\n");
			getch();
			printf("+7 Weapon Ammo\n\n\n");
			getch();
			printf("+1 Common Healing Potion\n\n\n");
			getch();

			player_currency.gold += 4;
			player_currency.platinum += 1;
			player_ammo.weapon += 7;
			player_potions.common += 1;

			break;

		}
		//GAME OVER
		else if(player_stats.health == 0 || player_stats.health < 0)
		{

			strcpy(tooltip, " *** GAME OVER! *** ");
			getch();
			exit(1);

		}

	} 

}



void main()
{

	//Player Weapon
	int player_weapon_current =  laser_gun();
	const char * player_weapon_current_name = laser_gun_name();

	//Player Utility
	int player_utility_current = plasma_granade();
	const char * player_utility_current_name = plasma_granade_name();



	//Starting Stats
	player_stats.health = 100;

	//Starting Ammo
	player_ammo.weapon = 15;
	player_ammo.utility = 3;

	//Starting Currency
	player_currency.gold = 0;
	player_currency.platinum = 0;

	//Starting Potions
	player_potions.common = 1;
	player_potions.greater = 0;
	player_potions.mythical = 0;
	player_potions.devine = 0;


	//Character Creation
	printf("Enter your name:");
	scanf("%s", player_character_creation.player_name);


	//Stage (1)
	stage1(player_weapon_current, player_utility_current, player_weapon_current_name, player_utility_current_name , guard_1_name(), guard_1_health());



	getch();

}
