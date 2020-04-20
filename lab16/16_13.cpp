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
    
    void PreOrder(){
        stack <pair<TreeNode*,int> > q;
        if (head)
            q.push({head,0});
        while(!q.empty()){
            TreeNode *v = q.top().first;
            int w = q.top().second;
            q.pop();
            if (w == 0){
                q.push({v,1});
                if (v->right)
                    q.push({v->right,0});
                if (v->left)
                    q.push({v->left,0});
            } else{
                cout << v -> val << ' ' ;
            }
        }
    }
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
    t_a.PreOrder();
}
