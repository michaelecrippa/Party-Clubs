# Party-Clubs
Small OOP project for university course. (condition link available at the bottom)

Examples for inheritance, polymorphism, hierarchical structure and encapsulation can be found in the project.

## Project explanation
### Music preferences
 * Folk - doesnt like house music
 * House - doesnt like rock music
 * Rock - doesnt like folk music
 * No preferences - likes all types of music
 
 ### Club rules for users
* User likes club type
* The club is not full
* User has enought money to pay his drinks
* User is not underaged (underaged users can enter only folk clubs and must pay 20$ fee to the guard)

### Personal implementation
| Classes | Characteristics | Base class |
| ------ | ------ | ------ |
| User | name/years/money/fav. music/# of whiskies/# of vodka| no |
| Club | size / whisky price / vodka price | Messages |
| FolkClub | performer / size / whisky price / vodka price   |  Club | 
| HouseClub | whisky price/ vodka price / # of djs |  Club | 
| RockClub | size / whisky pricey / vodka price |  Club | 
| Messages | prints messages to the console | no |
| Clubs | collection of different clubs | Messages |

 Full rules can be found in [Task.pdf](https://github.com/michaelecrippa/Party-Clubs/blob/main/Task.pdf) !
