// Shannon Fano 
#include <bits/stdc++.h>
using namespace std;

struct ShannonFanoNode {
    char symbol;
    double probability;
    std::string code;
};

void shannonFano(std::vector<ShannonFanoNode>& nodes, int start, int end) {
    if (start == end) {
        return;
    }

    double totalProbability = 0;
    for (int i = start; i <= end; ++i) {
        totalProbability += nodes[i].probability;
    }

    double halfProbability = totalProbability / 2;
    int splitIndex = start;

    double tempSum = nodes[start].probability;
    while (tempSum < halfProbability) {
        ++splitIndex;
        tempSum += nodes[splitIndex].probability;
    }

    for (int i = start; i <= end; ++i) {
        if (i <= splitIndex) {
            nodes[i].code += "0";
        } else {
            nodes[i].code += "1";
        }
    }

    shannonFano(nodes, start, splitIndex);
    shannonFano(nodes, splitIndex + 1, end);
}

double calculateEntropy(const double probabilities[], int size) {
    double entropy = 0;
    for (int i = 0; i < size; ++i) {
        if (probabilities[i] > 0) {
            entropy -= probabilities[i] * log2(probabilities[i]);
        }
    }
    return entropy;
}

double calculateAverageLength(const double probabilities[], const std::string codes[], int size) {
    double avgLength = 0;
    for (int i = 0; i < size; ++i) {
        avgLength += probabilities[i] * codes[i].length();
    }
    return avgLength;
}

int main() {
    std::string inputWord;
    std::cout << "Enter a word: ";
    std::cin >> inputWord;

    std::map<char, int> charCount;
    int totalChars = 0;

    // Count the frequency of each character in the input word
    for (char c : inputWord) {
        charCount[c]++;
        totalChars++;
    }

    std::vector<ShannonFanoNode> nodes;

    // Calculate probabilities and prepare nodes for Shannon-Fano
    for (const auto& pair : charCount) {
        double probability = static_cast<double>(pair.second) / totalChars;
        nodes.push_back({pair.first, probability, ""});
    }

    // Sort nodes based on probabilities in descending order
    std::sort(nodes.begin(), nodes.end(), [](const ShannonFanoNode& a, const ShannonFanoNode& b) {
        return a.probability > b.probability;
    });

    shannonFano(nodes, 0, nodes.size() - 1);

    int size = charCount.size();
    double probabilities[size];
    std::string shannonFanoCodes[size];

    for (size_t i = 0; i < nodes.size(); ++i) {
        probabilities[i] = nodes[i].probability;
        shannonFanoCodes[i] = nodes[i].code;
    }

    double entropy = calculateEntropy(probabilities, size);
    double avgLength = calculateAverageLength(probabilities, shannonFanoCodes, size);

    for (size_t i = 0; i < size; ++i) {
        std::cout << nodes[i].symbol <<" -> "<< nodes[i].code << "\n";
    }

    std::cout << "Entropy: " << entropy << " bits\n";
    std::cout << "Average Length: " << avgLength << " bits\n";

    return 0;
}