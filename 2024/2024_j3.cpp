#include <iostream>

int computeTopScores(int top_scores[], int score);

int main() {
    int participants;
    std::cin >> participants;

    int top_scores[3] = {0, 0, 0};

    // Find top scores
    for (int i = 0; i < participants; i++) {
        int score;
        std::cin >> score;

        computeTopScores(top_scores, score);
    }

    for (int i = 0; i < )

    return 0;
}

// array decays to pointer
int computeTopScores(int top_scores[], int score) {
    if (score > top_scores[0]) {
        top_scores[2] = top_scores[1];
        top_scores[1] = top_scores[0];
        top_scores[0] = score;
    } else if (score > top_scores[1]) {
        top_scores[2] = top_scores[1];
        top_scores[1] = score;
    } else if (score > top_scores[2]) {
        top_scores[2] = score;
    }
}