 
 #include <iostream>
using namespace std;

class Player
{
  private:
  int health;
  int damage;
  int extraDamage;
  int healing;


  public:
  Player()
  {
    int health, damage,extraDamage, healing;
    this->health = health;
    this->damage = damage;
    this->extraDamage = extraDamage;
    this->healing = healing;
    
  }

  int const GetHealth()
  {
    return health;
  }

  void SetHealth(int value)
  {
    health = value;
  }

  int const GetDamage()
  {
    return damage;
  }

  void SetDamage(int value)
  {
    damage = value;
  }

  int const GetExtraDamage()
  {
    return extraDamage;
  }

  void setExtraDamage(int value)
  {
    extraDamage = value;
  }

  int const GetHealing()
  {
    return healing;
  }

  void SetHealing(int value)
  {
    healing =  value;
  }


  void TakeDamage(int dmg) 
  {
    health -= dmg;
  }

  int const GetTotalDamage() 
  {
    return damage + extraDamage;
  }

  int Attack()
	{
		return GetTotalDamage();
	}

	void Heal()
	{
		SetHealing((5 + (rand() % 5)));
		health += GetHealing();
	}
  
};

class Tom : public Player
{
  public:
  Tom()
  {
   //High Health
  //low Damage
  //Low healing
    SetHealth(150);
    SetDamage(10);
    setExtraDamage(0);
    SetHealing(0);
    cout<<"Player Tom is Ready To Fight \n";
  }
  

};

class Jerry : public Player
{
  public:
   Jerry ()
  {
  //Avg Health
  //Avg Damage
  //Avg healing
    SetHealth(100);
    SetDamage(20);
    setExtraDamage(0);
    SetHealing(10);
    cout<<"Player Jerry is Ready To Fight \n";
  }
 
  
};

class Spike : public Player
{
  public:
   Spike ()
  {
  //low Health
  //High Damage
  //Avg healing
    SetHealth(80);
    SetDamage(30);
    setExtraDamage(10);
    SetHealing(0);
    cout<<"Player Spike is Ready To Fight \n";
  }
 
};

void PlayGame(Player *p1 ,  Player *p2)
{
  int turnPlayer =1;
  char option1, option2;

  while(true)
  {

    if(p1->GetHealth() <= 0)
    {
      cout << "!! Player 2 won !!\n";
      break;
    }
    else if(p2->GetHealth() <= 0)
    {
      cout << "!! Player 1 won !!\n";
      break;
    }

    if(turnPlayer == 1)
    {
     cout << "Player " << turnPlayer << " : Enter 'A' To Fire or 'M' To Medical Aid\n";
     cout << "Player " << turnPlayer << " : ";
		cin >> option1;

		if (option1 == 'A' || option1 == 'a')
		{
			p2->TakeDamage(p1->Attack());
	    cout << "Player 2 updated health - " << p2->GetHealth() << "\n";
			}
		
		else if (option1 == 'M' || option1 == 'm')
		{
			p1->Heal();
			cout << "Player 1 updated health - " << p1->GetHealth() << "\n";
		}
      
      turnPlayer++;
    }

    else
    {  
      cout << "Player " << turnPlayer << " : Enter 'A' To Fire or 'M' To Medical Aid\n";
      cout << "Player " << turnPlayer << " : ";
		  cin >> option2;

		if (option2 == 'A' || option2 == 'a')
		{
			p1->TakeDamage(p2->Attack());
		
			cout << "Player 1 updated health - " << p1->GetHealth() << "\n";
			
		}
		else if (option2 == 'M' || option2 == 'm')
		{
			p2->Heal();
			cout << "Player 2 updated health - " << p2->GetHealth() << "\n";
		} 
      
      turnPlayer--;
    }    
  }
}

int main() {

  cout << "Player Characteristics\n";

  cout << "- Tom - High Health, Low Damage, Low Healing\n\n";
  

  cout << "- Jerry - Average Health, Average Damage, Average Healing\n\n";
 

  cout << "- Spike - Low Health, High Damage, Average Healing\n\n";
  

  char player1,player2;
  Player *p1;
  Player *p2;
  cout<< "Player 1 Choose your player: \nPress 'T' for Tom \nPress 'J' for Jerry \nPress 'S' for Spike.\n";
  cin>>player1; 

  if ((player1 == 'T'|| player1 == 't') ||(player1 == 'J'|| player1 == 'j')|| (player1 == 'S'|| player1 == 's'))
  {
    if (player1 == 'T'|| player1 == 't')
    {
      cout<< "Player 1 Choose Tom\n";
       p1 = new Tom();
    
    }
    if (player1 == 'J'|| player1 == 'j')
    {
      cout<< "Player 1 Choose Jerry\n";
      p1 = new Jerry();
    }

    if (player1 == 'S'|| player1 == 's')
    {
      cout<< "Player 1 Choose Spike\n";
      p1 = new Spike();
    }
  }
else 
  {
  cout<< "Enter Correct Input\n";
  }
 cout<< "Player 2 Choose your player: \nPress 'T' for Tom \nPress 'J' for Jerry \nPress 'S' for Spike.\n";
 cin>>player2; 

  if (player1==player2)
    {
    cout<< "Player 1 already choose that player.plz choose another player\n";
    }
 else if (player2 == 'T'|| player2 == 't')
    {
      cout<< "Player 2 Choose Tom\n";
      p2 = new Tom();
    }
   else if (player2 == 'J'|| player2 == 'j')
    {
      cout<< "Player 2 Choose Jerry\n";
       p2 = new Jerry();
    }

   else if (player2 == 'S'|| player2 == 's')
    {
      cout<< "Player 2 Choose Spike\n";
      p2 = new Spike();
    }
  
else 
  {
  cout<< "Enter Correct Input\n";
  }

  
  PlayGame(p1,p2);
  delete p1;
  delete p2;

}