#include <iostream>//Includes common functions and such
 using namespace std;//Use the std namespace
  
 int main()//Program entry point
 {
 bool done=false;//loop quit variable
 while(done!=true)//The main program loop.
 {
  cout << "1 - Play the number game.\n 2 - Play the letter game.\n3 - Quit.\n";//This is the menu
   int choice=0; //Declare the variable choice and set its value to 0
   cin >> choice;//Get the user input and put it in choice
   switch(choice)
  {
  case 1: //This is the number game, where who ever is playing chooses a number between 1 and 10, and then puts it in!
             int theNum;
             cout << "Welcome to the Number Game!  Enter a number between 1 and 10!\n:";
             cin >> theNum; //This is were the person puts in the number, "theNum" refers to the number
             if (theNum >=1 && theNum <=10) //This means that if the number is greater then 1 and less then 10, it is true
             {
                 cout << "Your number was " << theNum << "\n"; //If the number is greater then 1 and less then 10, this is the message you'll get
             }
             else
             {
                 cout << " " << theNum << " is greater then 10 smartass!!\n"; //This is what happens if the number is greater then 10
             }
    break;
     case 2: //This is what you get is you press 2 in then menu, which is the letter game, basically the same thing as the number game!
            char theChar;
            cout << "This is the letter game! \n Enter one letter, only 1, or the game will go into a never ending loop!!!\n:";
            cin >> theChar;  //The person puts in the character here, "theChar" refers to the charater
            cout << "Your letter was " << theChar << "!\n"; //If the person puts in 1 letter, then you get thus screen.  If the person puts 2 or more letters the game will go into an infinate loop
   break;
   case 3:
   done=true;//quits the loop
         break;
  default: //This is what you get if you pressed a number you put in the menu wasn't choice 1, 2, or 3
   cout << "That wasn't one of the choices!\n";
        }
   cout << "\n\n\n";//You can put a few new lines in right here!!
 } // End the while loop
 }//end the program
