#include <iostream>

struct Score {
    int score;
    int occurances;
};

void computeTopScores(Score top_scores[], int score);


int main() {
    int participants;
    std::cin >> participants;

    // Don't forget to initialise - otherwise garbage values may be read
    Score top_scores[3] = {
        {0, 0},
        {0, 0},
        {0, 0}
    };


    // Find top scores
    for (int i = 0; i < participants; i++) {
        int score;
        std::cin >> score;

        computeTopScores(top_scores, score);
    }

    // std::cout << "Results\n";
    // for (int i = 0; i < 3; i++) {
    //     std::cout << top_scores[i].score << "x" << top_scores[i].occurances << '\n';
    // }

    // Output bronze requirement
    std::cout << top_scores[2].score << ' ' << top_scores[2].occurances << '\n';

    return 0;
}

// array decays to pointer
void computeTopScores(Score top_scores[], int score) {
    // top_scores is a pointer
    
    // [x] does the dereferencing
    // top_scores[0]  ≡  *(top_scores + 0)
    // top_scores[1]  ≡  *(top_scores + 1)
    // top_scores[2]  ≡  *(top_scores + 2)

    if (score == top_scores[0].score) top_scores[0].occurances++;
    else if (score == top_scores[1].score) top_scores[1].occurances++;
    else if (score == top_scores[2].score) top_scores[2].occurances++;

    else if (score > top_scores[0].score) {
        top_scores[2] = top_scores[1];
        top_scores[1] = top_scores[0];
        top_scores[0] = Score{score, 1};
    } else if (score > top_scores[1].score) {
        top_scores[2] = top_scores[1];
        top_scores[1] = Score{score, 1};
    } else if (score > top_scores[2].score) {
        top_scores[2] = Score{score, 1};
    }
}