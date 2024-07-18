#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
private:
    string questionText;
    string choices[4];
    int correctAnswerIndex;

public:
    Question(string text, string choice1, string choice2, string choice3, string choice4, int correctIndex) {
        questionText = text;
        choices[0] = choice1;
        choices[1] = choice2;
        choices[2] = choice3;
        choices[3] = choice4;
        correctAnswerIndex = correctIndex;
    }

    void displayQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << choices[i] << endl;
        }
    }

    bool checkAnswer(int userAnswer) {
        return userAnswer == correctAnswerIndex + 1;
    }
};

class Quiz {
private:
    vector<Question> questions;
    int score;

public:
    Quiz() {
        score = 0;
    }

    void addQuestion(Question question) {
        questions.push_back(question);
    }

    void start() {
        int userAnswer;
        for (size_t i = 0; i < questions.size(); i++) {
            questions[i].displayQuestion();
            cout << "Your answer: ";
            cin >> userAnswer;
            if (questions[i].checkAnswer(userAnswer)) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect!" << endl;
            }
            cout << endl;
        }
        cout << "Quiz finished! Your score is: " << score << " out of " << questions.size() << endl;
    }
};

int main() {
    Quiz quiz;

    Question q1("What is the capital of France?", "Berlin", "London", "Paris", "Rome", 2);
    Question q2("Who wrote 'To Kill a Mockingbird'?", "Harper Lee", "Mark Twain", "Ernest Hemingway", "F. Scott Fitzgerald", 0);
    Question q3("What is the chemical symbol for water?", "H2O", "O2", "CO2", "NaCl", 0);

    quiz.addQuestion(q1);
    quiz.addQuestion(q2);
    quiz.addQuestion(q3);

    quiz.start();

    return 0;
}
