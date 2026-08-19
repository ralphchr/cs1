/*Ask the user to enter his/her birth month and day (in numerical format, e.g. 8 for August). Based on these inputs, tell him/her his/her zodiac sign and display a fortune. The fortune should come from the following list only (choose any 12 to serve as fortune or horoscope for the day) for the 12 zodiac signs. DO NOT FORGET ABOUT THE HONOR CODE.

A few hours grace before the madness begins again.
A long-forgotten loved one will appear soon. Buy the negatives at any price.
Abandon the search for Truth; settle for a good fantasy.
After your lover has gone you will still have PEANUT BUTTER!
Among the lucky, you are the chosen one.
Are you a turtle?
Be different: conform.
Be free and open and breezy! Enjoy! Things won't get any better so get used to it.
Best of all is never to have been born. Second best is to die soon.
Caution: breathing may be hazardous to your health.
Cheer Up! Things are getting worse at a slower rate.
Do what comes naturally. Seethe and fume and throw a tantrum.
Don't hate yourself in the morning -- sleep till noon.
Don't kiss an elephant on the lips today.
Don't look now, but there is a multi-legged creature on your shoulder.
Don't relax! It's only your tension that's holding you together.
Don't tell any big lies today. Small ones can be just as effective.
Excellent day to have a rotten day.
Excellent time to become a missing person.
Expect the worst, it's the least you can do.
You will be attacked next Wednesday at 3:15 p.m. by six samurai sword wielding purple fish glued to Harley-Davidson motorcycles. Oh, and have a nice day!
Go to a movie tonight. Darkness becomes you.
Good day to let down old friends who need help.
Good news. Ten weeks from Friday will be a pretty good day.
If you learn one useless thing every day, in a single year you'll learn 365 useless things.
In the stairway of life, you'd best take the elevator.
It is so very hard to be an on-your-own-take-care-of-yourself-because-there-is-no-one-else-to-do-it-for-you-grown-up.
It was all so different before everything changed.
Never look up when dragons fly overhead.
Of course you have a purpose -- to find a purpose.
Questionable day. Ask somebody something.
Someone whom you reject today, will reject you tomorrow.
There is a 20% chance of tomorrow.
This will be a memorable month -- no matter how hard you try to forget it.
Today is the tomorrow you worried about yesterday.
Tomorrow will be canceled due to lack of interest.
Tonight you will pay the wages of sin; Don't forget to leave a tip.
What happened last night can happen again.
You are a very redundant person, that's what kind of person you are.
Write yourself a threatening letter and pen a defiant reply.
You are confused; but this is your normal state.
You are going to have a new love affair.
You are not dead yet. But watch for further reports.
You are number 6! Who is number one?
You are scrupulously honest, frank, and straightforward. Therefore you have few friends.
You are only young once, but you can stay immature indefinitely.
You are sick, twisted and perverted. I like that in a person.
You are standing on my toes.
You are wise, witty, and wonderful, but you spend too much time reading this sort of trash.
You definitely intend to start living sometime soon.
You have the body of a 19 year old. Please return it before it gets wrinkled.
You have the capacity to learn from mistakes. You'll learn a lot today.
You should emulate your heroes, but don't carry it too far. Especially if they are dead.
You two ought to be more careful--your love could drag on for years and years.
You will be a winner today. Pick a fight with a four-year-old.
You will be attacked by a beast who has the body of a wolf, the tail of a lion, and the face of Donald Duck.
You will be reincarnated as a toad; and you will be much happier.
You will be Told about it Tomorrow. Go Home and Prepare Thyself.
You will pay for your sins. If you have already paid, please disregard this message.
Your lucky number is 3552664958674928. Watch for it everywhere.
For this MP, there will be no evaluation as you will be choosing from a number of possible horoscopes.
*/

//Sources: https://www.astrology.com/article/zodiac-sign-dates/

#include <stdio.h>

int main(){
    int month, day;
    printf("Month: ");
    scanf("%d", &month);

    printf("Day: ");
    scanf("%d", &day);

    if (month >= 1 && month <= 12 && day >= 1 && day <= 31){
        if ((month == 3 && day >=21 && day <= 31) || (month == 4 && day <=19)){
            printf("You are an Aries!\n");
            printf("Do what comes naturally. Seethe and fume and throw a tantrum.");

        } else if ((month == 4 && day >=20  && day <= 30) || (month == 5 && day <= 20)){
            printf("You are a Taurus!\n");
            printf("After your lover has gone you will still have PEANUT BUTTER!");

        } else if ((month == 5 && day >=21  && day <= 31) || (month == 6 && day <= 20)){
            printf("You are a Gemini!\n");
            printf("You are confused; but this is your normal state.");

        } else if ((month == 6 && day >=21  && day <= 30) || (month == 7 && day <= 22)){
            printf("You are a Cancer!\n");
            printf("A long-forgotten loved one will appear soon. Buy the negatives at any price.");

        } else if ((month == 7 && day >=23  && day <= 31) || (month == 8 && day <= 22)){
            printf("You are a Leo!\n");
            printf("Among the lucky, you are the chosen one.");

        } else if ((month == 8 && day >=23  && day <= 31) || (month == 9 && day <= 22)){
            printf("You are a Virgo!\n");
            printf("You are scrupulously honest, frank, and straightforward. Therefore you have few friends.");

        } else if ((month == 9 && day >=23 && day <= 30) || (month == 10 && day <= 22)){
            printf("You are a Libra!\n");
            printf("You two ought to be more careful—your love could drag on for years and years.");

        } else if ((month == 10 && day >=23 && day <= 31) || (month == 11 && day <= 21)){
            printf("You are a Scorpio!\n");
            printf("Tonight you will pay the wages of sin; Don’t forget to leave a tip.");

        } else if ((month == 11 && day >=22 && day <= 30) || (month == 12 && day <= 21)){
            printf("You are a Sagittarius!\n");
            printf("Be free and open and breezy! Enjoy! Things won't get any better so get used to it.");

        } else if ((month == 12 && day >=22 && day <= 31) || (month == 1 && day <= 20)){
            printf("You are a Capricorn!\n");
            printf("Of course you have a purpose -- to find a purpose.");

        } else if ((month == 1 && day >=21  && day <= 31) || (month == 2 && day <= 18)){
            printf("You are an Aquarius!\n");
            printf("Abandon the search for Truth; settle for a good fantasy.");

        } else if ((month == 2 && day >=19  && day <= 29) || (month == 3 && day <= 20)){
            printf("You are a Pisces!\n");
            printf("Go to a movie tonight. Darkness becomes you.");
        } else{
            printf("Invalid Input!");
        }
    } else {
        printf("Invalid Input!");
    }

    return 0;

}