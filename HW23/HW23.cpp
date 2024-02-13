#include <iostream>
#include <unordered_set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <stack>

class Node {
public:
    int data;
    Node* next;

    Node(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    void push_front(int data)
    {
        Node* node = new Node(data);

        if (head != nullptr)
        {
            node->next = head;
        }

        head = node;
    }

    void popFront() {}

private:
    Node* head = nullptr;
};

bool has_cycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* tortoise = head;
    Node* hare = head->next;

    while (hare != nullptr && hare->next != nullptr) {
        if (tortoise == hare) {
            return true;
        }

        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    return false;
}

size_t uniqueWordsCount(const std::string& line) {
    std::unordered_set<std::string> uniqueWords;
    std::istringstream iss(line);

    std::string word;
    while (iss >> word) {
        // Додаємо слово до unordered_set, яке автоматично відфільтровує дублікати.
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

std::string mostOccuredWord(const std::string& line) {
    std::unordered_map<std::string, int> wordCountMap;

    std::istringstream iss(line);

    std::string word;
    while (iss >> word) {
        wordCountMap[word]++;
    }

    std::string mostOccured;
    int maxCount = 0;

    for (const auto& entry : wordCountMap) {
        if (entry.second > maxCount) {
            mostOccured = entry.first;
            maxCount = entry.second;
        }
    }

    return mostOccured;
}

bool areBracketsBalanced(const std::string& str) {
    std::stack<char> bracketStack;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (bracketStack.empty()) {
                return false;
            }

            char openBracket = bracketStack.top();
            bracketStack.pop();

            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false;
            }
        }
    }

    return bracketStack.empty();
}

int main()
{
    Node* node1 = new Node(5);
    Node* node2 = new Node(5);
    Node* node3 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1; //OOPS, cycle is formed

    bool hasCycle = has_cycle(node1);
    if (hasCycle) {
        std::cout << "List contain the cycle." << std::endl;
    }
    else {
        std::cout << "List doesn't contain the cycle." << std::endl;
    }

    std::string line = "Hello Hey Hello Bye Hey Hello";
    size_t count = uniqueWordsCount(line);
    std::string mostOccured = mostOccuredWord(line);

    std::cout << "Number of unique word: " << count << std::endl;
    std::cout << "Most used word: " << mostOccured << std::endl;

    std::string input = "{[(])()}";
    bool result = areBracketsBalanced(input);

    if (result) {
        std::cout << "Brackets are Balanced" << std::endl;
    }
    else {
        std::cout << "Brackets aren't Balanced" << std::endl;
    }

}
 