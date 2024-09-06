#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

struct Questions {
    string question;
    string choices[4];
    char correctAnswer;
    int branch; // Indicates the branch corresponding to this question
};

void titleScreen() {
    cout << "-----------------------------------------" << endl;
    cout << "|        The Mystery of the Diamond      |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|           Choose an option:            |" << endl;
    cout << "|                                       |" << endl;
    cout << "|  1. Play the game                      |" << endl;
    cout << "|  2. How to play                        |" << endl;
    cout << "|  3. Quit                               |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Enter your choice: ";
}

void storyQuest() {
    cout << "\nAs a detective, you've been called to investigate a mysterious case of a missing diamond." << endl;
    cout << "The diamond had been kept in a heavily guarded museum vault, but somehow, it had disappeared without a trace." << endl;
    cout << "Upon interviewing the museum staff, you discover that only four people had access to the" << endl;
    cout << "vault - the security guard, the museum curator, the maintenance worker, and the cleaning lady." << endl;
    cout << "However, all of them deny any knowledge of the missing diamond." << endl;
    cout << "As you search the museum, you find a note on the curator's desk," << endl;
    cout << "which reads: 'I have taken what rightfully belongs to me. You will never find it.' What could this mean?" << endl;
    cout << "\nYou will now answer four questions to solve the mystery." << endl;
}

bool validateInput(char choice) {
    return (choice == 'a' || choice == 'A' || choice == 'b' || choice == 'B' ||
            choice == 'c' || choice == 'C' || choice == 'd' || choice == 'D');
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    bool playAgain = true;
 
    while (playAgain) {
        system("cls");
        titleScreen();

        int choice;
        while (!(cin >> choice) || cin.peek() !='\n') {
    		cout << "Invalid input. Try again. ";
    		clearInputBuffer();
		}
        system("cls");

        switch (choice) {
            case 1: {
                system("cls");

                Questions questions[4] = {
                    {
                        "Who do you suspect of stealing the diamond?",
                        {
                            "A. The security guard: They had access to the vault and knowledge of the security system.",
                            "B. The museum curator: They were responsible for the diamond's display and had inside knowledge.",
                            "C. The maintenance worker: They had access to the museum premises and could exploit vulnerabilities.",
                            "D. The cleaning lady: They had regular access to various areas of the museum, including the vault."
                        },
                        'a',
                        1 // Branch 1 corresponds to the security guard suspicion
                    },
                    {
                        "What is the thief's motive for stealing the diamond?",
                        {
                            "A. Financial gain, the thief intends to sell the diamond for a high price.",
                            "B. Revenge, the thief has a personal vendetta against someone associated with the museum.",
                            "C. Blackmail, the thief plans to use the diamond to extort money or favors.",
                            "D. Collecting, the thief is a notorious collector and wants to add the diamond to their collection."
                        },
                        'b',
                        2 // Branch 2 corresponds to the thief's motive suspicion
                    },
                    {
                        "What do you think the note means?",
                        {
                            "A. The curator is innocent and the note is a red herring: The note is designed to mislead investigators.",
                            "B. The curator stole the diamond and left the note as a clue: The note implicates the curator directly.",
                            "C. The note is a decoy and someone else stole the diamond: The note is meant to divert suspicion.",
                            "D. The note is a prank and has no relation to the theft: The note is unrelated to the diamond's disappearance."
                        },
                        'd',
                        3 // Branch 3 corresponds to the note interpretation suspicion
                    },
                    {
                        "Who do you think has a credible alibi?",
                        {
                            "A. The security guard: They were on duty and had surveillance footage to support their alibi.",
                            "B. The museum curator: They were attending a high-profile meeting during the time of the theft.",
                            "C. The maintenance worker: They were repairing a crucial electrical system during the incident.",
                            "D. The cleaning lady: They were seen by multiple witnesses cleaning other areas at the time."
                        },
                        'c',
                        4 // Branch 4 corresponds to the alibi suspicion
                    }
                };

                
                int numCorrect = 0;
                storyQuest();

                for (int i = 0; i < 4; i++) {
                    cout << "\nQuestion " << (i + 1) << ": " << questions[i].question << endl;
                    for (int j = 0; j < 4; j++) {
                        cout << "   " << questions[i].choices[j] << endl;
                    }

                    char playerAnswer;
                    cout << "\nEnter your answer (A, B, C, or D): ";
                    cin >> playerAnswer;

                    while (!validateInput(playerAnswer)) {
    					cout << "Invalid input. Try again." << endl;
    					clearInputBuffer();
    					cin >> playerAnswer;
						}

                    if (playerAnswer == questions[i].correctAnswer) {
                        numCorrect++;
                    }

                    system("cls");
                    storyQuest();
                }

                if (numCorrect == 4) {
                	system("cls");
                    cout << "\n--------------------------------------------" << endl;
                    cout << "|  Congratulations! You've solved the case.   |" << endl;
                    cout << "|---------------------------------------------|" << endl;
                    cout << "| The suspect is the security guard,          |" << endl;
                    cout << "| the diamond has been sold on the black      |" << endl;
                    cout << "| market, the note is a prank and has no      |" << endl;
                    cout << "| relation to the theft, the alibi is the     |" << endl;
                    cout << "| cleaning lady, and the other person who     |" << endl;
                    cout << "| could be involved is the maintenance        |" << endl;
                    cout << "| worker.                                     |" << endl;
                    cout << "----------------------------------------------" << endl;
                } else {
                    cout << "\n--------------------------------------------------------" << endl;
                    cout << "|   Sorry, you only got " << numCorrect << " out of 4 questions correct.   |" << endl;
                    cout << "--------------------------------------------------------" << endl;
                }
                
				string response;
				bool validInput = false;
				do {
    				cout << "\nDo you want to try again? (Y/N): ";
    				clearInputBuffer();
    				getline(cin, response);

    			if (response.length() == 1 && (response[0] == 'y' || response[0] == 'Y')) {
        			validInput = true;
    			} else if (response.length() == 1 && (response[0] == 'n' || response[0] == 'N')) {
        			validInput = true;
        			cout << "-----------------------------------------" << endl;
        			cout << "|         Thank you for playing!          |" << endl;
        			cout << "|                 Goodbye!                |" << endl;
        			cout << "-----------------------------------------" << endl;
        			playAgain = false; // Assuming 'playAgain' is a variable controlling the game loop
    			} else {
        			cout << "Invalid input. Please enter 'Y' or 'N': ";
    			}
    
				} while (!validInput);

				break;

            }
            case 2: {
                cout << "-----------------------------------------" << endl;
                cout << "| This is a mystery game where you need   |" << endl;
                cout << "| to solve a case of a missing diamond.   |" << endl;
                cout << "| You will be presented with a series     |" << endl;
                cout << "| of questions related to the case.       |" << endl;
                cout << "| Answer the questions correctly to       |" << endl;
                cout << "| progress in the game and uncover the    |" << endl;
                cout << "| truth. Good luck!                       |" << endl;
                cout << "-----------------------------------------" << endl;
                cout << "|     Enter enter to return to the        |" << endl;
                cout << "|            title screen...              |" << endl;
                cout << "-----------------------------------------" << endl;
                cin.ignore();  // Ignore any leftover newline character
                cin.get();  // Wait for user to press any key
                system("cls");
                break;
            }
            case 3: {
                cout << "-----------------------------------------" << endl;
                cout << "|         Thank you for playing!          |" << endl;
                cout << "|                 Goodbye!                |" << endl;
                cout << "-----------------------------------------" << endl;
                playAgain = false;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}


