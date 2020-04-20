//OnlyVim 20.04.2020
#include <bits/stdc++.h>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree{
public:
    TreeNode *head;
    Tree() : head(NULL) {};
    void Insert(int val){
        if (!head){
            head = new TreeNode(val);
            return;
        }
        TreeNode *temp = head;
        while(1){
            if (head -> val > val){
                if (head -> left){
                    head = head -> left;
                } else{
                    head -> left = new TreeNode(val);
                    break;
                }
            } else{
                if (head -> right){
                    head = head -> right;
                } else{
                    head -> right = new TreeNode(val);
                    break;
                }
            }
        }
        head = temp;
    } // Вставка числа val в Бинарное Дерево Поиска
    
    int IsSameTree(Tree p){
        multiset <int> a,b;
        queue <TreeNode*> q;
        if (head)
            q.push(head);
        while(!q.empty()){
            TreeNode *v = q.front();
            q.pop();
            a.insert(v->val);
            if (v->left)
                q.push(v->left);
            if (v->right)
                q.push(v->right);
        }
        if (p.head)
            q.push(p.head);
        while(!q.empty()){
            TreeNode *v = q.front();
            q.pop();
            b.insert(v->val);
            if (v->left)
                q.push(v->left);
            if (v->right)
                q.push(v->right);
        }    
        return (a == b);
    } // Вернуть 1 если текущее дерево равно p, иначе вернуть 0
};

int main(){
    int n;
    cin >> n;
    Tree t_a;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        t_a.Insert(x);
    }
    int m;
    cin >> m;
    Tree t_b;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        t_b.Insert(x);
    }
    cout << t_a.IsSameTree(t_b) << endl;
}
