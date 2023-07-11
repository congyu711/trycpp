#include<vector>
#include<stack>
#include<algorithm>

namespace cartesianTree
{
  using namespace std;

  // treetype: type for the balanced tree.
  // heaptype: type for the heap.
  template<typename treetype, typename heaptype>
  struct node
  {
    treetype treeval;
    heaptype heapval;
    node* lson;
    node* rson;
    node(const treetype& tv, const heaptype& hv):treeval(tv),heapval(hv),lson(nullptr),rson(nullptr){}
    node():treeval(treetype{}),heapval(heaptype{}),lson(nullptr),rson(nullptr){}
  };

  template<typename treetype, typename heaptype, typename tree_cmp_t=less<treetype>, typename heap_cmp_t=less<heaptype>>
  struct cartesianTree
  {
    tree_cmp_t tree_cmp;
    heap_cmp_t heap_cmp;
    node<treetype,heaptype>* root;
    using datatype=pair<treetype,heaptype>;
    cartesianTree(const vector<datatype>& vec)
    {
      auto sortedvec=vec;
      sort(sortedvec.begin(), sortedvec.end(), [&](const datatype& a, const datatype& b){return tree_cmp(a.first,b.first);});
      stack<node<treetype,heaptype>*> st;
      for(const auto& e:sortedvec)
      {
        auto p=new node<treetype, heaptype>(e.first,e.second);
        int sz=st.size(); node<treetype,heaptype>* justpopped;
        while(!st.empty()&&heap_cmp(e.second,st.top()->heapval)) {justpopped=st.top();st.pop();}
        if(st.size()) st.top()->rson=p;
        if(st.size()<sz) p->lson=justpopped;
        st.push(p);
      }
      while(st.size()>1)  st.pop();
      root=st.top();
    }
  };
  
}

int main()
{
  using namespace std;
  vector<pair<int,int>> vec={{1,4},{2,1},{3,3},{4,2},{5,5}};
  cartesianTree::cartesianTree<int,int> a(vec);
}