#include <stdio.h>
#include <stdlib.h>

// 2分探索木のノードを表す構造体
typedef struct Node_tag {
    int data;
    struct Node_tag* left;
    struct Node_tag* right;
} Node;

// プロトタイプ宣言
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* search(Node* root, int data);
Node* rotateR(Node* root);
Node* rotateL(Node* root);
Node* balance(Node* root);
Node* insertB(Node* root, int data);
int height(Node* root);

//カウンタ変数
Node* pstCreateNode[10] = { NULL };
int iCreateNodeNum = 0;
int rotateR_Count = 0;  // 右回転の回数
int rotateL_Count = 0;  // 左回転の回数

// 新しいノードを作成する関数
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

// 2分木にデータを挿入する関数
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

// 2分木を探索する関数
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

// 右回転
Node* rotateR(Node* root) {
    Node* a;
    a = root->left;  // 左の子ノードが新しいルートになる
    root->left = a->right;  // 新しいルートの右子ノードを元のノードの左子に設定
    a->right = root;  // 元のルートを新しいルートの右子に設定
    rotateR_Count++;
    return a;  // 新しいルートを返す
}

// 左回転
Node* rotateL(Node* root) {
    Node* a;
    a = root->right;  // 右の子ノードが新しいルートになる
    root->right = a->left;  // 新しいルートの左子ノードを元のノードの右子に設定
    a->left = root;  // 元のルートを新しいルートの左子に設定
    rotateL_Count++;
    return a;  // 新しいルートを返す
}

// balance関数 
Node* balance(Node* root) {
    int h1, h2, h3;
    int leftHeight = 0;  // 左サブツリーの高さ
    int rightHeight = 0;  // 右サブツリーの高さ

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

// 2分木にデータを挿入する関数
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
    root = balance(root); //追加
    return root;
}

// 高さを計算する関数
int height(Node* root) {
    // ツリーの高さの変数
    int leftHeight = 0;  // 左サブツリーの高さ
    int rightHeight = 0;  // 右サブツリーの高さ

    if (root == NULL) {
        return 0;  // 空のノードは高さ0
    }

    if (root->left != NULL) {
        leftHeight += height(root->left);  // 左サブツリーの高さ
        /*if ((root->left->left != NULL) || (root->left->right) != NULL) {
            leftHeight++;
        }*/
    }
    if (root->right != NULL) {
        rightHeight += height(root->right);  // 右サブツリーの高さ
        /*if ((root->right->left != NULL) || (root->right->right) != NULL) {
            rightHeight++;
        }*/
    }

    //leftHeight += height(root->left);  // 左サブツリーの高さ
    //rightHeight += height(root->right);  // 右サブツリーの高さ

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

// メイン関数
int main(void)
{
    Node* root = NULL; // 初期のルートノードはNULL
    int key = 1;

    // データを挿入
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

    // 探索
    key = 9;
    Node* result = search(root, key);
    if (result != NULL) {
        printf("データ%dが見つかりました。\n", key);
    }
    else {
        printf("データ%dが見つかりませんでした。\n", key);
    }

    // 右回転と左回転の回数を表示
    printf("右回転が%d回実行されました。\n", rotateR_Count);
    printf("左回転が%d回実行されました。\n", rotateL_Count);

    return 0;
}
