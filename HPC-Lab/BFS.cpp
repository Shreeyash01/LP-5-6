#include <iostream>
#include <queue>
#include <omp.h>
using namespace std;

class node {
public:
    node *left, *right;
    int data;

    node(int data) : data(data), left(nullptr), right(nullptr) {}

    void bfs(node *head) {
        if (!head)
            return;

        queue<node*> q;
        q.push(head);

        while (!q.empty()) {
            int level_size = q.size();

            // Parallelize the loop for processing nodes at the current level
            #pragma omp parallel for
            for (int i = 0; i < level_size; ++i) {
                node* currNode;
                #pragma omp critical
                {
                    currNode = q.front();
                    q.pop();
                }
                cout << "\t" << currNode->data;

                // Enqueue child nodes (left and right) if they exist
                if (currNode->left)
                    #pragma omp critical
                    {
                        q.push(currNode->left);
                    }
                if (currNode->right)
                    #pragma omp critical
                    {
                        q.push(currNode->right);
                    }
            }
            cout << endl; // Print newline after processing all nodes at the current level
        }
    }
};

int main() {
    node *root = nullptr; // Initialize root to nullptr
    int data;
    char ans;

    do {
        cout << "\nEnter data => ";
        cin >> data;
        if (!root) {
            root = new node(data); // Create root node if it's nullptr
        } else {
            queue<node*> q;
            q.push(root);

            while (!q.empty()) {
                node *temp = q.front();
                q.pop();

                if (!temp->left) {
                    temp->left = new node(data);
                    break;
                } else {
                    q.push(temp->left);
                }

                if (!temp->right) {
                    temp->right = new node(data);
                    break;
                } else {
                    q.push(temp->right);
                }
            }
        }

        cout << "Do you want to insert one more node? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    cout << "\nBFS traversal: ";
    root->bfs(root);

    return 0;
}
