#include <iostream>
#include <vector>
#include "SearchTree.h" 

int main()
{
    BSearchTree bst;
    int choice;
    int key;
    Node* successor = nullptr;
    Node* predecessor = nullptr;
    std::vector<int> constrVect = {8,3,10,1,6,14,4,7,13};
    bst.construct(constrVect);
    do {
        std::cout << std::endl;
        std::cout << "1. Insert\n";
        std::cout << "2. Find\n";
        std::cout << "3. Delete\n";
        std::cout << "4. Minimum\n";
        std::cout << "5. Maximum\n";
        std::cout << "6. Successor\n";
        std::cout << "7. Predecessor\n";
        std::cout << "8. Print Tree\n";
        std::cout << "9. Clear\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the key to insert: ";
            std::cin >> key;
            bst.insert(key);
            break;
        case 2:
            std::cout << "Enter the key to find: ";
            std::cin >> key;
            if (bst.find(key) != nullptr)
                std::cout << "Key found!\n";
            else
                std::cout << "Key not found!\n";
            break;
        case 3:
            std::cout << "Enter the key to delete: ";
            std::cin >> key;
            bst.del(key);
            break;
        case 4:
            if (bst.minim(bst.getRoot()) != nullptr)
                std::cout << "Minimum key: " << bst.minim(bst.getRoot())->key << "\n";
            else
                std::cout << "Tree is empty!\n";
            break;
        case 5:
            if (bst.maxim(bst.getRoot()) != nullptr)
                std::cout << "Maximum key: " << bst.maxim(bst.getRoot())->key << "\n";
            else
                std::cout << "Tree is empty!\n";
            break;
        case 6:
            std::cout << "Enter the key to find its successor: ";
            std::cin >> key;
            successor = bst.succesor(bst.find(key));
            if (successor != nullptr)
                std::cout << "Successor: " << successor->key << "\n";
            else
                std::cout << "No successor found!\n";
            break;
        case 7:
            std::cout << "Enter the key to find its predecessor: ";
            std::cin >> key;
            predecessor = bst.predecesor(bst.find(key));
            if (predecessor != nullptr)
                std::cout << "Predecessor: " << predecessor->key << "\n";
            else
                std::cout << "No predecessor found!\n";
            break;
        case 8:
            std::cout << "Choose the print option:\n";
            std::cout << "1. Preorder\n";
            std::cout << "2. Inorder\n";
            std::cout << "3. Postorder\n";
            std::cout << "4. Level Order\n";
            std::cout << "Enter your choice: ";
            std::cin >> key;
            bst.print_tree(key);
            break;
        case 9:
            bst.clear();
            std::cout << "Tree cleared!\n";
            break;
        case 0:
            std::cout << "Exit";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 0);
}