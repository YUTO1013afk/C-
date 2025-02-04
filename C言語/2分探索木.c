#include <stdio.h>
#include <stdlib.h>

// 2���T���؂̃m�[�h��\���\����
typedef struct Node_tag {
    int data;
    struct Node_tag* left;
    struct Node_tag* right;
} Node;

// �v���g�^�C�v�錾
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* search(Node* root, int data);
Node* rotateR(Node* root);
Node* rotateL(Node* root);
Node* balance(Node* root);
Node* insertB(Node* root, int data);
int height(Node* root);

//�J�E���^�ϐ�
Node* pstCreateNode[10] = { NULL };
int iCreateNodeNum = 0;
int rotateR_Count = 0;  // �E��]�̉�
int rotateL_Count = 0;  // ����]�̉�

// �V�����m�[�h���쐬����֐�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        pstCreateNode[iCreateNodeNum] = newNode;
        iCreateNodeNum++;
    }
    return newNode;
}

// 2���؂Ƀf�[�^��}������֐�
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// 2���؂�T������֐�
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

// �E��]
Node* rotateR(Node* root) {
    Node* a;
    a = root->left;  // ���̎q�m�[�h���V�������[�g�ɂȂ�
    root->left = a->right;  // �V�������[�g�̉E�q�m�[�h�����̃m�[�h�̍��q�ɐݒ�
    a->right = root;  // ���̃��[�g��V�������[�g�̉E�q�ɐݒ�
    rotateR_Count++;
    return a;  // �V�������[�g��Ԃ�
}

// ����]
Node* rotateL(Node* root) {
    Node* a;
    a = root->right;  // �E�̎q�m�[�h���V�������[�g�ɂȂ�
    root->right = a->left;  // �V�������[�g�̍��q�m�[�h�����̃m�[�h�̉E�q�ɐݒ�
    a->left = root;  // ���̃��[�g��V�������[�g�̍��q�ɐݒ�
    rotateL_Count++;
    return a;  // �V�������[�g��Ԃ�
}

// balance�֐� 
Node* balance(Node* root) {
    int h1, h2, h3;
    int leftHeight = 0;  // ���T�u�c���[�̍���
    int rightHeight = 0;  // �E�T�u�c���[�̍���

    leftHeight = height(root->left);
    rightHeight = height(root->right);
    h1 = leftHeight - rightHeight;
    //h1 = height(root->left) - height(root->right);
    if (h1 == 2) {
        h2 = height(root->left->right) - height(root->left->left);
        if (h2 > 0) {
            root->left = rotateL(root->left);
        }
        root = rotateR(root);
    }
    else if (h1 == -2) {
        h3 = height(root->right->left) - height(root->right->right);
        if (h3 > 0) {
            root->right = rotateR(root->right);
        }
        root = rotateL(root);
    }
    return root;
}

// 2���؂Ƀf�[�^��}������֐�
Node* insertB(Node* root, int data)
{
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data < root->data) {
        root->left = insertB(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertB(root->right, data);
    }
    root = balance(root); //�ǉ�
    return root;
}

// �������v�Z����֐�
int height(Node* root) {
    // �c���[�̍����̕ϐ�
    int leftHeight = 0;  // ���T�u�c���[�̍���
    int rightHeight = 0;  // �E�T�u�c���[�̍���

    if (root == NULL) {
        return 0;  // ��̃m�[�h�͍���0
    }

    if (root->left != NULL) {
        leftHeight += height(root->left);  // ���T�u�c���[�̍���
        /*if ((root->left->left != NULL) || (root->left->right) != NULL) {
            leftHeight++;
        }*/
    }
    if (root->right != NULL) {
        rightHeight += height(root->right);  // �E�T�u�c���[�̍���
        /*if ((root->right->left != NULL) || (root->right->right) != NULL) {
            rightHeight++;
        }*/
    }

    //leftHeight += height(root->left);  // ���T�u�c���[�̍���
    //rightHeight += height(root->right);  // �E�T�u�c���[�̍���

    if (leftHeight == rightHeight) {
        return leftHeight + 1;
    }
    else if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}

// ���C���֐��̗�
int main(void)
{
    Node* root = NULL; // �����̃��[�g�m�[�h��NULL
    int key = 1;

    // �f�[�^��}��
   /* root = insertB(root, 1);
    root = insertB(root, 3);
    root = insertB(root, 4);
    root = insertB(root, 5);
    root = insertB(root, 6);
    root = insertB(root, 8);
    root = insertB(root, 9);*/

    root = insertB(root, 1);
    root = insertB(root, 3);
    root = insertB(root, 5);
    root = insertB(root, 6);
    root = insertB(root, 9);
    root = insertB(root, 4);
    root = insertB(root, 8);

    // �T��
    key = 9;
    Node* result = search(root, key);
    if (result != NULL) {
        printf("�f�[�^%d��������܂����B\n", key);
    }
    else {
        printf("�f�[�^%d��������܂���ł����B\n", key);
    }

    // �E��]�ƍ���]�̉񐔂�\��
    printf("�E��]��%d����s����܂����B\n", rotateR_Count);
    printf("����]��%d����s����܂����B\n", rotateL_Count);

    return 0;
}
