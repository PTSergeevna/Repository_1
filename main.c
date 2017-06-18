// Метод, который выводит сумму узлов дерева
class tree {
    struct node {
        int     val;
        node* left;
        node* right;
    };
private:
    node*  tr;
    size_t cnt;
public:
    tree(void):tr(NULL), cnt(0){}
    tree(const tree&);
    ~tree(){
        clear();
    }

public:

   bool insert(const int& val){
        node* p = tr, *i = tr;
        while(i != NULL){
            p = i;
            if(val < i->val)
                i = i->left;
            else if(val > i->val)
                i = i->right;
            else
                return false;
        }
 
        node* n = new (std::nothrow) node();
        if(n != NULL){
            n->val  = val;
            n->left = n->right = NULL;
 
            if(p == NULL)
                tr = n;
            else if(val < p->val)
                p->left  = n;
            else
                p->right = n;
            ++cnt;
        }
        return (n != NULL);
    }
 
    int get_sum(void) {
        return __sum(tr);
    }
 
    void clear(void){
        __clear(tr);
        tr  = NULL;
        cnt = 0;
    }
 
private:
 
   int __sum(const node* p){
        if(p != NULL)
            return p->val + __sum(p->left) + __sum(p->right);
        return 0;
    }
 
    void __clear(node* p){
        if(p != NULL){
            if(p->left != NULL)
                __clear(p->left);
            if(p->right != NULL)
                __clear(p->right);
            delete p;
        }
    }
 
    size_t getSize(void) const { return cnt; }
    //...
};
 
 
int main(void){
    tree<size_t> tr;
    for(int i = 0; i < 30; ++i)
        tr.insert((size_t)(rand() % 40));
 
    std::cout << "sum: " << tr.get_sum() << std::endl;
    tr.clear();
    return 0;
}
