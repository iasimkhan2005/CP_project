#include <iostream>
#include <string>
#include <ctime>
using namespace std;
static int score = 0;
int flag = 0;
static int gold = 50;
//---------------------------------------------------------------------------------------------------
//                                     Structures
struct USER {
    string name;
    string Class;
    int health;
    int exp;
    int level;
};
struct QUEST
{
    int serialno;
    string name;
    string difficulty;
};
struct Creature {
    string name[3];
    int health;
    int difficulty;
};
USER character() {
    USER player;
    cout << "Enter your character Name: ";
    getline( cin,player.name);
    cout << "Enter your character class (1.Warrior,2.Mage,3.Rogue): ";
    cin >> player.Class;
    player.health = 100;
    player.exp = 0;
    player.level = 0;
    return player;
}
QUEST mission_1()
{
    QUEST mis1_info;
    mis1_info.name = "1.Investigate the haunted forest";
    mis1_info.difficulty = "\tDifficulty: EASY";
    return mis1_info;
}
QUEST mission_2()
{
    QUEST mis2_info;
    mis2_info.name = "2. Find the Ancient Treasure";
    mis2_info.difficulty = "\tDifficulty: HARD";
    return mis2_info;
}
//-----------------------------------------------------------------------------------------------------
//                                     Functions Declarations
void game();
void showmission_1();
void showmission_2();
void show_characterinfo(USER& player);
void displayCreatureInfo(char choice);
int damageofleafshadow(int currentHealth);
int userdamage(int currentHealth);
void inventory(int& healthuser, int& healthcreature, USER& player);
int damageofrockscale(int currentHealth);
int damageoffrostclaw(int currentHealth);
//------------------------------------------------------------------------------------------------------
//                                     MAIN Body

int main()
{
    cout << "\tWelcome to the Kingdom of Mystria!" << endl;
    cout << "\tA land where mythical creatures roam freely, endangering our peace." << endl;
    cout << "\tThe kingdom is in turmoil, and brave adventurers are needed to save us all!" << endl;
    cout << "\tThere is also a treasure in this kingdom you will have to defeat the creature to win the treasure gold." << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    game(); // This function handles the game mechanics.
    cout << "Thank you for playing! Until next time, brave adventurer." << endl;
    system("pause");
    return 0;
}
//----------------------------------------------------------------------------------------------------------
//                                       Functions
void game()
{
    USER player = character();
    char choiceUp;
    do
    {

        if (player.exp == 100)
        {
            player.level++;
            player.exp = 0;
        }
        if (player.exp == -100)
        {
            player.level--;
            player.exp = 0;
        }

        show_characterinfo(player);

        showmission_1();
        showmission_2();
        cout << "Select (1 or 2): ";
        cin >> choiceUp;
        cout << "-----------------------------------------------------------" << endl;

        switch (choiceUp)
        {
        case '1':
        {
            char choice1;

            cout << "L. Leaf Shadow \t\t\t\tDifficulty level 1" << endl;
            cout << "F. Frost Claw \t\t\t\tDifficulty level 2" << endl;
            cout << "R. Rock Scale \t\t\t\tDifficulty level 3" << endl;
            cout << "Select   'l' to fight with leafshadow " << endl;
            cout << "\t 'f' to fight with frostclaw" << endl;
            cout << "\t 'r' to fight with rockscale" << endl;
            cin >> choice1;
            cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            if (choice1 == 'l' || choice1 == 'L' || choice1 == '1')
            {


                displayCreatureInfo(choice1);
                cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                int character_Health = player.health;
                int creature_Health = 100;

                do {
                    if (flag != 0)
                    {
                        break;
                    }
                    int choice;
                    cout << "1. Fight" << endl;
                    cout << "2. Inventory" << endl;
                    cout << "Enter choice: ";
                    cin >> choice;

                    if (choice == 1) {
                        character_Health= damageofleafshadow(character_Health);
                        creature_Health = userdamage(creature_Health);

                        cout << "Your Health: " << character_Health << endl;
                        cout << "Creature Health: " << creature_Health << endl;
                        cout << "-----------------------------------------------------------" << endl;
                        if (character_Health <= 0 || creature_Health <= 0)
                        {
                            if (character_Health <= 0) {
                                score -= 10;
                                cout << "You lost" << endl;
                                player.exp -= 50;
                            }
                            else {
                                score += 10;
                                cout << "You won" << endl;
                                player.exp += 50;
                            }
                            char continueChoice;
                            cout << "Do you want to continue fighting? (y/n): ";
                            cin >> continueChoice;

                            if (continueChoice != 'y' && continueChoice != 'Y') {

                                break;
                                // Break out of the inner loop to go back to the main menu
                            }
                            else {
                                // Reset health for the next fight

                                character_Health = player.health;
                                creature_Health = 100;
                            }
                        }
                    }
                    if (choice == 2)
                    {
                        inventory(character_Health, creature_Health, player);
                    }
                } while (true);
            }

            else if (choice1 == 's' || choice1 == 'S' || choice1 == '2')
            {


                displayCreatureInfo(choice1);
                cout << "-----------------------------------------------------------" << endl;
                int userHealth = player.health;
                int creatureHealth = 100;

                do {
                    int choice;
                    cout << "1. Fight" << endl;
                    cout << "2. Inventory" << endl;
                    cout << "Enter choice: ";
                    cin >> choice;
                    cout << "-----------------------------------------------------------" << endl;
                    if (choice == 1) {
                        userHealth = damageoffrostclaw(userHealth);
                        creatureHealth = userdamage(creatureHealth);

                        cout << "Your Health: " << userHealth << endl;
                        cout << "Creature Health: " << creatureHealth << endl;

                        if (userHealth <= 0 || creatureHealth <= 0)
                        {
                            if (userHealth <= 0) {
                                score -= 10;
                                cout << "You lost" << endl;
                                player.exp -= 50;
                            }
                            else {
                                score += 10;
                                cout << "You won" << endl;
                                player.exp += 50;
                            }
                            char continueChoice;
                            cout << "Do you want to continue fighting? (y/n): ";
                            cin >> continueChoice;

                            if (continueChoice != 'f' && continueChoice != 'F') {
                                break;
                                // Break out of the inner loop to go back to the main menu
                            }
                            else {
                                // Reset health for the next fight
                                userHealth = player.health;
                                creatureHealth = 100;
                            }
                        }
                    }
                    if (choice == 2)
                    {
                        inventory(userHealth, creatureHealth, player);
                    }
                } while (true);
            }

            else if (choice1 == 'r' || choice1 == 'R' || choice1 == '3')
            {

                displayCreatureInfo(choice1);
                cout << "-----------------------------------------------------------" << endl;
                int userHealth = player.health;
                int creatureHealth = 100;

                do {
                    int choice;
                    cout << "1. Fight" << endl;
                    cout << "2. Inventory" << endl;
                    cout << "Enter choice: ";
                    cin >> choice;
                    cout << "-----------------------------------------------------------" << endl;
                    if (choice == 1) {
                        userHealth = damageofrockscale(userHealth);
                        creatureHealth = userdamage(creatureHealth);

                        cout << "Your Health: " << userHealth << endl;
                        cout << "Creature Health: " << creatureHealth << endl;

                        if (userHealth <= 0 || creatureHealth <= 0)
                        {
                            if (userHealth <= 0) {
                                score -= 10;
                                cout << "You lost" << endl;
                                player.exp -= 50;
                            }
                            else {
                                score += 10;
                                cout << "You won" << endl;
                                player.exp += 50;
                            }
                            char continueChoice;
                            cout << "Do you want to continue fighting? (y/n): ";
                            cin >> continueChoice;

                            if (continueChoice != 'y' && continueChoice != 'Y') {
                                break;
                                // Break out of the inner loop to go back to the main menu
                            }
                            else {
                                // Reset health for the next fight
                                userHealth = player.health;
                                creatureHealth = 100;
                            }
                        }
                    }
                    if (choice == 2)
                    {
                        inventory(userHealth, creatureHealth, player);
                    }
                } while (true);

            }
            break;
        }
        case '2':
        {
            cout << "------------------------A Dice Game------------------------" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "To get the treasure, You have to play a dice game with the " << endl
                << "guardian of the treasure.If you win or lose the game, You will gain or" << endl
                << "lose the golds respectively" << endl;
            cout << "-----------------------------------------------------------" << endl;
            char choice;
            do {
                srand(time(0));
                string any;
                cout << "Enter any key to roll the dice" << endl;
                cin >> any;
                int computer = rand() % 7;
                int player = rand() % 7;
                cout << "Guardian  : " << computer << endl;
                cout << "You : " << player << endl;
                if (computer > player)
                {
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "You lost the dice game and 20 Golds." << endl;
                    cout << "You have " << gold << " Golds" << endl;
                    cout << "-----------------------------------------------------------" << endl;

                }
                else if (player == computer)
                {
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "Do Again" << endl;
                    cout << "-----------------------------------------------------------" << endl;

                }
                else
                {
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "Treasure is saved. You won 20 Golds" << endl;
                    cout << "You have " << gold << " Golds" << endl;
                    cout << "-----------------------------------------------------------" << endl;
                    gold += 20;

                }
                cout << "Do you want to roll again? (y/n)" << endl;
                cin >> choice;
                cout << "-----------------------------------------------------------" << endl;
            } while (choice != 'n');

            break;
        }
        case '9':
        {
            cout << "Thank you!" << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }
         default: {
            cout << "Invalid Data";
          }
      }

    } while (choiceUp != 9);
}
void showmission_1()
{
    QUEST mis1_info = mission_1();
    cout << "-----------------------------------------------------------" << endl;
    cout << "Select quest to embark" << endl;
    cout << mis1_info.name << mis1_info.difficulty << endl;

}
void showmission_2()
{
    QUEST mis2_info = mission_2();
    cout << mis2_info.name << mis2_info.difficulty << endl;
    cout << "00. Exit" << endl;
}
void show_characterinfo(USER& player) {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Player Information" << endl;
    cout << "Name: " << player.name << endl;
    cout << "Class: " << player.Class << endl;
    cout << "Health: " << player.health << endl;
    cout << "Level: " << player.level << endl;
    cout << "Score: " << score << endl;
    cout << "Experience point: " << player.exp << endl;
}
void displayCreatureInfo(char choice) {
    Creature info;
    info.health = 100;

    if (choice == 'l' || choice == 'L' || choice == '1') {
        info.name[0] = "Leaf Shadow";
        info.difficulty = 1;
        cout << "Name: " << info.name[0] << endl;
        cout << "Health: " << info.health << endl;
        cout << "Difficulty Level: " << info.difficulty << endl;
    }
    else if (choice == 'f' || choice == 'F' || choice == '2') {
        info.name[1] = "Frost Claw";
        info.difficulty = 2;
        cout << "Name: " << info.name[1] << endl;
        cout << "Health: " << info.health << endl;
        cout << "Difficulty Level: " << info.difficulty << endl;
    }
    else if (choice == 'r' || choice == 'R' || choice == '3') {
        info.name[2] = "Rock Scale";
        info.difficulty = 3;
        cout << "Name: " << info.name[2] << endl;
        cout << "Health: " << info.health << endl;
        cout << "Difficulty Level: " << info.difficulty << endl;
    }

}
int damageofleafshadow(int current_Health)
{
    srand(time(0));
    //Damage user character got from creature.
    int damage = rand() % 21;
    return current_Health - damage;
}

int userdamage(int current_Health)
{
    srand(time(0));
    //Damage creature got from the user
    int damage = rand() % 31;
    return current_Health - damage;
}
void inventory(int& healthuser, int& healthcreature, USER& player)
{

    cout << "-----------------------------------------------------------" << endl;
    cout << "You have " << gold << " Golds" << endl;
    cout << "1.Poison \t  Price: 20G \t Damage: +20" << endl;
    cout << "2.Health Portion  Price: 30G \t Health: +20" << endl;
    int inventory;
    cout << "Enter (1 or 2) to select " << endl;
    cin >> inventory;
    if (inventory == 1)
    {
        if (gold >= 20)
        {
            gold = gold - 20;
            healthcreature -= 20;
            cout << "Enemy have dealt with 20 damage" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Your health: " << healthuser << endl;
            cout << "Creature health: " << healthcreature << endl;
            cout << "-----------------------------------------------------------" << endl;

            if (healthuser <= 0) {
                score -= 10;
                cout << "You lost" << endl;
                player.exp -= 50;
                flag++;

            }
            else if (healthcreature <= 0)
            {
                score += 10;
                cout << "You won" << endl;
                player.exp += 50;
                //using flag to avoid fight and invetory option after winning battle in the end by using inventoty 
                // , if it is not doing , after winning last with inventory ,
                //  again fight option is coming let alone quest selection option.
                flag++;

            }

        }
        else if (gold < 11)
        {
            cout << "--!!!!Insufficient Gold to purchase!!!!--" << endl;
            cout << "--Save the treasure to get 30 Gold--" << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }
    else if (inventory == 2)
    {
        if (gold >= 30)
        {
            gold -= 30;
            healthuser = healthuser + 20;
            cout << "You have gained 20 health" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Your health: " << healthuser << endl;
            cout << "Creature health: " << healthcreature << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
        else if (gold < 11)
        {
            cout << "--!!!!Insufficient Gold to purchase!!!!--" << endl;
            cout << "--Save the treasure to get 20 Gold--" << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }
}
int damageofrockscale(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 41;
    return currentHealth - damage;
}
int damageoffrostclaw(int currentHealth)
{
    srand(time(0));
    //user damage given to the creature
    int damage = rand() % 33;
    return currentHealth - damage;
}