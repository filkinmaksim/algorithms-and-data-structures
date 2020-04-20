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
    
    int MinDepth(){
        int mn = 1e9;
        queue <pair<TreeNode*,int> > q;
        if (head)
            q.push({head,1});
        while(!q.empty()){
            TreeNode *v = q.front().first;
            int gl = q.front().second;
            if (!v->left && !v->right)
                mn = min(mn,gl);
            q.pop();
            if (v->left)
                q.push({v->left,gl + 1});
            if (v->right)
                q.push({v->right, gl + 1});
        }
        return mn;
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
    cout << t_a.MinDepth() << endl;
}
